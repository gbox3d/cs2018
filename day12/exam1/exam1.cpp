// exam1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"

COORD g_cdCurrentCursorPos;

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

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	static char szCmdBuf[32];

	g_cdCurrentCursorPos.X = 40;
	g_cdCurrentCursorPos.Y = 12;
	

	TGE::clearScreenBuffer(0x2e,0x0007);
	TGE::updateBuffer(hStdout,TGE::g_chiBuffer);

	while (1)
	{
		//스크립트 입력처리
		TGE::setCursor(hStdout, 0, 0);
		TGE::setCursor(hStdout, 0, 26);
		printf_s("                                                 ]");
		TGE::setCursor(hStdout, 0, 26);
		printf_s("[cmd >");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		//커멘드 파싱
		if (!parseCmd(szCmdBuf)) break;

		TGE::setCharacter(TGE::g_chiBuffer, g_cdCurrentCursorPos.X, g_cdCurrentCursorPos.Y, 0x20, 0x00e0);

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}


    return 0;
}

