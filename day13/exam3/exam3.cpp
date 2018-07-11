#include "stdafx.h"
#include "../../engine/tge.h"

//주인공 오브잭트//////////
COORD g_cdPlayerPos;
int g_nInven_keyCount;
///////////////////////////

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	CHAR_INFO *pBackScreenBuffer = TGE::CreateScreenBuffer();
	CHAR_INFO *pMapDataBuffer = TGE::CreateScreenBuffer();

	TGE::loadBufferBinary(pMapDataBuffer, "../../pub_res/1.map");
	g_cdPlayerPos.X = 15;
	g_cdPlayerPos.Y = 5;
	g_nInven_keyCount = 0;

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
						case VK_UP:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 -1");
							break;
						case VK_DOWN:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 1");
							break;
						case VK_LEFT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move -1 0");
							break;
						case VK_RIGHT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 1 0");
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
				else if (!strcmp(szTokenBuf[0], "move")) {
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					int _check_x = g_cdPlayerPos.X + _dx;
					int _check_y = g_cdPlayerPos.Y + _dy;

					if (pMapDataBuffer[_check_y * SCREEN_WIDTH + _check_x].Attributes == 0x0007)
					{
						g_cdPlayerPos.X = _check_x;
						g_cdPlayerPos.Y = _check_y;
					}
					
				}
				else if (!strcmp(szTokenBuf[0], "use")) {
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					int _check_x = g_cdPlayerPos.X + _dx;
					int _check_y = g_cdPlayerPos.Y + _dy;
					//문 인가?
					if (pMapDataBuffer[_check_y * SCREEN_WIDTH + _check_x].Attributes == 0x00c0) {
						g_nInven_keyCount--;
						pMapDataBuffer[_check_y * SCREEN_WIDTH + _check_x].Attributes = 0x0007;
					}
					else if (pMapDataBuffer[_check_y * SCREEN_WIDTH + _check_x].Attributes == 0x00a0) {
						printf_s("탈출성공! [Game Over] \n");
						_bLoop = false;
					}
					else {
						printf_s("아무것도 없습니다.");
					}
				}
				else if (!strcmp(szTokenBuf[0], "get")) {
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					int _check_x = g_cdPlayerPos.X + _dx;
					int _check_y = g_cdPlayerPos.Y + _dy;
					//열쇠인가?
					if (pMapDataBuffer[_check_y * SCREEN_WIDTH + _check_x].Attributes == 0x0090) {
						g_nInven_keyCount++;
						pMapDataBuffer[_check_y * SCREEN_WIDTH + _check_x].Attributes = 0x0007;
					}
					else {
						printf_s("아무것도 없습니다.");
					}

				}
				else if (!strcmp(szTokenBuf[0], "drop")) {

				}
				else if (!strcmp(szTokenBuf[0], "teleport")) {
					int _x = atoi(szTokenBuf[1]);
					int _y = atoi(szTokenBuf[2]);

					g_cdPlayerPos.X = _x;
					g_cdPlayerPos.Y = _y;
				}
			}
			szCmdBuf[0] = 0x00;
		}


		//배경 다시 그리기
		memcpy_s(pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO),
			pMapDataBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));

		//오브잭트 그리기 
		TGE::setCharacter(pBackScreenBuffer, g_cdPlayerPos.X, g_cdPlayerPos.Y, 0x41, 0x000f);

		//전체 화면 갱신
		memcpy_s(TGE::g_chiBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO),
			pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
		
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	free(pBackScreenBuffer);
	free(pMapDataBuffer);

	return 0;
}

