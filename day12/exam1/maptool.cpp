#include "stdafx.h"

#include "../../engine/tge.h"
#include "maptool.h"

COORD g_cdCurrentCursorPos;
WCHAR g_wcCurrentBrushCode;
WORD g_wCurrentBrushAttr;


void initMapTool() 
{
	g_cdCurrentCursorPos.X = 40;
	g_cdCurrentCursorPos.Y = 12;
	g_wcCurrentBrushCode = 0x20;
	g_wCurrentBrushAttr = 0x00e0;
}

int parseCmd(char *szCmdBuf)
{
	static char szTokenBuf[8][16];

	//토큰처리 
	TGE::doTokenize(szCmdBuf, szTokenBuf);

	if (!strcmp(szTokenBuf[0], "quit")) {
		return 0;
	}
	else if (!strcmp(szTokenBuf[0], "set")) {
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		WCHAR _code = strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = strtol(szTokenBuf[4], NULL, 16);
		TGE::setCharacter(TGE::g_chiBuffer, _xpos, _ypos, _code, _attr);
	}
	else if (!strcmp(szTokenBuf[0], "moveCursor")) {

		if (_oldPos.X >= 0) {
			TGE::setCharacter(TGE::g_chiBuffer,  _oldPos.X, _oldPos.Y,
				_oldCode, _oldAttr);
		}
		//이전값 대피 
		_oldPos.X = g_cdCurrentCursorPos.X;
		_oldPos.Y = g_cdCurrentCursorPos.Y; 
		CHAR_INFO *oldInfo = TGE::getCharacter(TGE::g_chiBuffer, _oldPos.X, _oldPos.Y);
		_oldCode = oldInfo->Char.UnicodeChar;
		_oldAttr = oldInfo->Attributes;

		g_cdCurrentCursorPos.X = atoi(szTokenBuf[1]);
		g_cdCurrentCursorPos.Y = atoi(szTokenBuf[2]);
		WCHAR _code = strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = strtol(szTokenBuf[4], NULL, 16);
		TGE::setCharacter(TGE::g_chiBuffer, g_cdCurrentCursorPos.X, g_cdCurrentCursorPos.Y, _code, _attr);
	}
	else if (!strcmp(szTokenBuf[0], "clear")) {
		//WCHAR _code = strtol(szTokenBuf[1], NULL, 16);
		//WORD _attr = strtol(szTokenBuf[2], NULL, 16);
		//TGE::clearScreenBuffer(_code,_attr)
		TGE::clearScreenBuffer(0x2e, 0x0007);
	}
	else if (!strcmp(szTokenBuf[0], "changeBrush")) {
		WCHAR _code = (WCHAR)strtol(szTokenBuf[1], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[2], NULL, 16);
		g_wcCurrentBrushCode = _code;
		g_wCurrentBrushAttr = _attr;
	}
	else if (!strcmp(szTokenBuf[0], "saveb")) {
		TGE::saveBufferBinary(TGE::g_chiBuffer, szTokenBuf[1]);
	}
	else if (!strcmp(szTokenBuf[0], "loadb")) {
		TGE::loadBufferBinary( TGE::g_chiBuffer, szTokenBuf[1]);
	}

	return 1;
}