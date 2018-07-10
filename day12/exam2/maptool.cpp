#include "stdafx.h"

#include "../../engine/tge.h"
#include "maptool.h"


void initMapTool(S_TGE_MAPTOOL *pObj)
{
	pObj->m_cdCurrentCursorPos.X = 40;
	pObj->m_cdCurrentCursorPos.Y = 12;
	pObj->m_wcCurrentBrushCode = 0x20;
	pObj->m_CurrentBrushAttr = 0x00e0;
}

int parseCmd(S_TGE_MAPTOOL *pObj,char *szCmdBuf)
{
	static char szTokenBuf[8][16];

	//��ūó�� 
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
			//������ ���� 
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
		FILE *fp;
		fopen_s(&fp, szTokenBuf[1], "w");
		fwrite(TGE::g_chiBuffer, 2000 * sizeof(CHAR_INFO), 1, fp);
		fclose(fp);
	}
	else if (!strcmp(szTokenBuf[0], "loadb")) {
		FILE *fp;
		fopen_s(&fp, szTokenBuf[1], "r");
		fread_s(TGE::g_chiBuffer, 2000 * sizeof(CHAR_INFO), sizeof(CHAR_INFO), 2000, fp);
		fclose(fp);
	}


	return 1;
}