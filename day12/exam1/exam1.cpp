// exam1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"
#include "maptool.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;

	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	initMapTool();

	TGE::clearScreenBuffer(0x2e,0x0007);
	TGE::updateBuffer(hStdout,TGE::g_chiBuffer);

	int nFSM = 0;
	TGE::setCursor(hStdout, 0, 0);
	TGE::setCursor(hStdout, 0, 26);
	while (1)
	{
		static char szCmdBuf[32];

		switch (nFSM)
		{
		case 0:
			//비동기 키입력 처리 
		{
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];
			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++) {
				if (irInputBuf[i].EventType == KEY_EVENT) {
					if (irInputBuf[i].Event.KeyEvent.bKeyDown) {
						TGE::setCursor(hStdout, 0, 0);
						TGE::setCursor(hStdout, 0, 26);
						printf_s("                                                 ]");
						TGE::setCursor(hStdout, 0, 26);
						printf_s("%d", irInputBuf[i].Event.KeyEvent.wVirtualScanCode);
						//u72 d80 l75 r77
						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode) {
						case 28: //커멘드 입력 모드 전환 
							nFSM = 1;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case 72: //up
							g_cdCurrentCursorPos.Y -= 1;
							sprintf_s(szCmdBuf, 32, "set %d %d 0x20 0x00e0", 
								g_cdCurrentCursorPos.X ,g_cdCurrentCursorPos.Y);
							//set  g_cdCurrentCursorPos.X g_cdCurrentCursorPos.Y-1 0x20 0x00e0
							//strcpy_s(szCmdBuf,32,
							//
							break;
						case 80: //down
							g_cdCurrentCursorPos.Y += 1;
							sprintf_s(szCmdBuf, 32, "set %d %d 0x20 0x00e0",
								g_cdCurrentCursorPos.X, g_cdCurrentCursorPos.Y);
							break;
						case 75: //left
							g_cdCurrentCursorPos.X -= 1;
							sprintf_s(szCmdBuf, 32, "set %d %d 0x20 0x00e0",
								g_cdCurrentCursorPos.X, g_cdCurrentCursorPos.Y);
							break;
						case 77: //right
							g_cdCurrentCursorPos.X += 1;
							sprintf_s(szCmdBuf, 32, "set %d %d 0x20 0x00e0",
								g_cdCurrentCursorPos.X, g_cdCurrentCursorPos.Y);
							break;
						}
						
					}
					
				}
			}
		}
			break;
		case 1:
		{
			//스크립트 입력처리
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf_s("                                                 ]");
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[cmd >");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			nFSM = 0;
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		}
			break;
		default:
			break;
		}
		

		//커멘드 파싱
		if (!parseCmd(szCmdBuf)) break;

		//TGE::setCharacter(TGE::g_chiBuffer, g_cdCurrentCursorPos.X, g_cdCurrentCursorPos.Y, 0x20, 0x00e0);

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}


    return 0;
}

