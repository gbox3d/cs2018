//TGE skeleton 
#include "stdafx.h"
#include "../../engine/tge.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	TGE::clearScreenBuffer(0x20, 0x0090);

	//8x4
	int nW = 8;
	int nH = 4;
	CHAR_INFO *pBuf = (CHAR_INFO *)malloc( sizeof(nW*nH) * sizeof(CHAR_INFO) );
	//clear
	for (int i = 0; i < nW*nH; i++) {
		pBuf[i].Attributes = 0x00f0;
		pBuf[i].Char.UnicodeChar = 0x20;
	}

	//TGE::loadBufferBinary(TGE::g_chiBuffer, "../../pub_res/1.map");
	//g_cdPlayerPos.X = 15;
	//g_cdPlayerPos.Y = 5;

	bool _bLoop = true;
	static int _nFSM = 0;
	while (_bLoop)
	{
		static char szCmdBuf[128];

		//입력 처리 
		switch (_nFSM) {
		case 0: //비동기 모드
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];
			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++) {
				if (irInputBuf[i].EventType == KEY_EVENT) {
					if (irInputBuf[i].Event.KeyEvent.bKeyDown) {
						switch (irInputBuf[i].Event.KeyEvent.wVirtualKeyCode) {
						case VK_RETURN: //커멘드 입력 모드 전환 
							_nFSM = 1;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						}
					}
				}
			}
			break;
		case 1: //동기  모드
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf_s("                                                 ]");
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[cmd >");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			break;
		}
		//커멘드 처리..
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0) {
				if (!strcmp(szTokenBuf[0], "quit")) {
					_bLoop = false;
				}

			}
			szCmdBuf[0] = 0x00;
		}

		//00000000
	    //00000000
		
		int nStep = 0;
		int _i = 0;
		for (int i = 0; i < nW*nH; i++) {
			nStep = i / nW;
			TGE::g_chiBuffer[ _i + (nStep * SCREEN_WIDTH) ] = pBuf[i];
			_i++;
			_i %= nW;
		}

		//랜더 (화면 갱신)
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	SetConsoleMode(hStdin, fdwOldMode);

	free(pBuf);

	return 0;
}