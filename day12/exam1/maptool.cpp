#include "stdafx.h"

#include "../../engine/tge.h"
#include "maptool.h"

COORD g_cdCurrentCursorPos;

void initMapTool() 
{
	g_cdCurrentCursorPos.X = 40;
	g_cdCurrentCursorPos.Y = 12;
}

int parseCmd(char *szCmdBuf)
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
		WCHAR _code = strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = strtol(szTokenBuf[4], NULL, 16);
		TGE::setCharacter(TGE::g_chiBuffer, _xpos, _ypos, _code, _attr);
	}
	else if (!strcmp(szTokenBuf[0], "moveCursor")) {

		static COORD _oldPos = { -1,-1 };
		static WCHAR _oldCode = -1;
		static WORD _oldAttr = -1;
		if (_oldPos.X >= 0) {
			TGE::setCharacter(TGE::g_chiBuffer,  _oldPos.X, _oldPos.Y,
				_oldCode, _oldAttr);
		}
		//������ ���� 
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

	return 1;
}