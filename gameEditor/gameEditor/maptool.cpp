#include "stdafx.h"

#include "../../engine/tge.h"
#include "maptool.h"

namespace tge_sprite {

	struct S_SPRITE_HEADER {
		char szHeader[16];
		COORD m_cdWorkSpr;
	};

	struct S_SPRITE_OBJECT {
		S_SPRITE_HEADER m_header;
		CHAR_INFO *m_pSpriteBuf;
	};

	void Init(S_SPRITE_OBJECT *pObj) {
		pObj->m_header.m_cdWorkSpr = { 0,0 };
		strcpy_s(pObj->m_header.szHeader, sizeof(pObj->m_header.szHeader), "TGESPR");
		pObj->m_pSpriteBuf = NULL;
	}

	int load(S_SPRITE_OBJECT *pObj, const char *szFileName)
	{
		FILE *fp;
		fopen_s(&fp, szFileName, "r");

		fread(&(pObj->m_header), sizeof(S_SPRITE_HEADER), 1, fp);

		if (pObj->m_pSpriteBuf != NULL) { free(pObj->m_pSpriteBuf); }

		int _nBuffSize = pObj->m_header.m_cdWorkSpr.X*pObj->m_header.m_cdWorkSpr.Y * sizeof(CHAR_INFO);

		pObj->m_pSpriteBuf = (CHAR_INFO *)malloc( _nBuffSize );
		fread(pObj->m_pSpriteBuf,
			_nBuffSize, 1,
			fp);

		fclose(fp);

		return 0;
	}
	int save(S_SPRITE_OBJECT *pObj, const char *szFileName)
	{
		FILE *fp;
		fopen_s(&fp, szFileName, "w");

		fwrite(&(pObj->m_header), sizeof(S_SPRITE_HEADER), 1, fp);		
		fwrite(pObj->m_pSpriteBuf, 
			sizeof(CHAR_INFO),pObj->m_header.m_cdWorkSpr.X*pObj->m_header.m_cdWorkSpr.Y,
			 fp);

		fclose(fp);

		return 0;
	}
	int put(S_SPRITE_OBJECT *pObj,int posx,int posy)
	{
		TGE::putSprite(posx, posy, 
			pObj->m_header.m_cdWorkSpr.X, 
			pObj->m_header.m_cdWorkSpr.Y, TGE::g_chiBuffer, pObj->m_pSpriteBuf);
		return 0;

	}
	int get(S_SPRITE_OBJECT *pObj, int _xpos, int _ypos,int _width,int _height)
	{
		if (pObj->m_pSpriteBuf != NULL) { free(pObj->m_pSpriteBuf); }
		pObj->m_pSpriteBuf = (CHAR_INFO *)malloc(sizeof(CHAR_INFO) * (_width*_height));
		pObj->m_header.m_cdWorkSpr = { (SHORT)_width , (SHORT)_height };

		int _desx, _desy;

		for (_desy = 0; _desy < _height; _desy++) {
			for (_desx = 0; _desx < _width; _desx++) {
				pObj->m_pSpriteBuf[_desx + (_desy*_width)] =
					TGE::g_chiBuffer[(_desx + _xpos) + ((_desy + _ypos) *SCREEN_WIDTH)];
			}
		}
		return 0;
	}

}

tge_sprite:: S_SPRITE_OBJECT g_WorkSprObject;

void initMapTool(S_TGE_MAPTOOL *pObj)
{
	pObj->m_cdCurrentCursorPos.X = 40;
	pObj->m_cdCurrentCursorPos.Y = 12;
	pObj->m_wcCurrentBrushCode = 0x20;
	pObj->m_CurrentBrushAttr = 0x00e0;

	tge_sprite::Init(&g_WorkSprObject);
	
}

int parseCmd(S_TGE_MAPTOOL *pObj,char *szCmdBuf)
{
	static char szTokenBuf[8][MAX_TOKEN_SIZE];

	//토큰처리 
	TGE::doTokenize(szCmdBuf, szTokenBuf);

	if (!strcmp(szTokenBuf[0], "quit")) {
		return 0;
	}
	else if (!strcmp(szTokenBuf[0], "set")) {
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		WCHAR _code = (WCHAR)strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[4], NULL, 16);
		TGE::setCharacter(TGE::g_chiBuffer, _xpos, _ypos, _code, _attr);
	}
	else if (!strcmp(szTokenBuf[0], "moveCursor") ||
		!strcmp(szTokenBuf[0], "moveCursorEnd")
		) {

		static COORD _oldPos = { -1,-1 };
		static WCHAR _oldCode = -1;
		static WORD _oldAttr = -1;

		if (!strcmp(szTokenBuf[0], "moveCursorEnd")) {
			_oldPos.X = -1;
		}
		else {
			if (_oldPos.X >= 0) {
				TGE::setCharacter(TGE::g_chiBuffer, _oldPos.X, _oldPos.Y,
					_oldCode, _oldAttr);
			}
			//이전값 대피 
			_oldPos.X = pObj->m_cdCurrentCursorPos.X;
			_oldPos.Y = pObj->m_cdCurrentCursorPos.Y;
			CHAR_INFO *oldInfo = TGE::getCharacter(TGE::g_chiBuffer, _oldPos.X, _oldPos.Y);
			_oldCode = oldInfo->Char.UnicodeChar;
			_oldAttr = oldInfo->Attributes;

			pObj->m_cdCurrentCursorPos.X = atoi(szTokenBuf[1]);
			pObj->m_cdCurrentCursorPos.Y = atoi(szTokenBuf[2]);
			WCHAR _code = (WCHAR)strtol(szTokenBuf[3], NULL, 16);
			WORD _attr = (WORD)strtol(szTokenBuf[4], NULL, 16);
			TGE::setCharacter(TGE::g_chiBuffer, pObj->m_cdCurrentCursorPos.X, pObj->m_cdCurrentCursorPos.Y,
				_code, _attr);
		}
	}
	else if (!strcmp(szTokenBuf[0], "clear")) {
		
		TGE::clearScreenBuffer(0x2e, 0x0007);
	}
	else if (!strcmp(szTokenBuf[0], "changeBrush")) {
		WCHAR _code = (WCHAR)strtol(szTokenBuf[1], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[2], NULL, 16);
		pObj->m_wcCurrentBrushCode = _code;
		pObj->m_CurrentBrushAttr = _attr;
	}
	else if (!strcmp(szTokenBuf[0], "saveb")) {
		TGE::saveBufferBinary(TGE::g_chiBuffer, szTokenBuf[1]);
	}
	else if (!strcmp(szTokenBuf[0], "loadb")) {
		TGE::loadBufferBinary(TGE::g_chiBuffer, szTokenBuf[1]);
	}
	else if (!strcmp(szTokenBuf[0], "getSprite")) {
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		int _width = atoi(szTokenBuf[3]);
		int _height = atoi(szTokenBuf[4]);

		tge_sprite::get(&g_WorkSprObject,_xpos,_ypos,_width,_height);


	}
	else if (!strcmp(szTokenBuf[0], "putSprite")) {
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		tge_sprite::put(&g_WorkSprObject,_xpos,_ypos);
	}
	else if (!strcmp(szTokenBuf[0], "saveSprite")) {
		tge_sprite::save(&g_WorkSprObject, szTokenBuf[1]);
	}
	else if (!strcmp(szTokenBuf[0], "loadSprite")) {
		tge_sprite::load(&g_WorkSprObject, szTokenBuf[1]);
	}


	return 1;
}