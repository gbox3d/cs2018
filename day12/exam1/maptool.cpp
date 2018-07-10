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

	//토큰처리 
	TGE::doTokenize(szCmdBuf, szTokenBuf);

	if (!strcmp(szTokenBuf[0], "quit")) {
		return 0;
	}
	else if (!strcmp(szTokenBuf[0], "set")) {
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		int _code = strtol(szTokenBuf[3], NULL, 16);
		int _attr = strtol(szTokenBuf[4], NULL, 16);
		TGE::setCharacter(TGE::g_chiBuffer, _xpos, _ypos, _code, _attr);
	}
	else if (!strcmp(szTokenBuf[0], "moveCursor")) {
		g_cdCurrentCursorPos.X = atoi(szTokenBuf[1]);
		g_cdCurrentCursorPos.Y = atoi(szTokenBuf[2]);
	}

	return 1;
}