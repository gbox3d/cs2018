// _7_asyncKeyInput.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>

int main()
{
	

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hStdin, &fdwSaveOldMode);

	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, fdwMode);

	double test = 0.0f;
	bool _bLoop = true;
	char vkTable[1024] = { 0 };
	while (_bLoop) {
		/**/
		bool bPeeked = PeekConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead);
		if (bPeeked ) {
			ReadConsoleInput(
				hStdin,      // input buffer handle 
				irInBuf,     // buffer to read into 
				128,         // size of read buffer 
				&cNumRead);

			for (DWORD i = 0; i < cNumRead; i++) {
				if (irInBuf[i].EventType == KEY_EVENT) {
					if (irInBuf[i].Event.KeyEvent.bKeyDown) {
						vkTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 1;

					}
					else {
						vkTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 0;
						
					}
				}
			}
			//FlushConsoleInputBuffer(hStdin);
			
		}

		test += 0.001;
		SetConsoleCursorPosition(hStdout, { 0,10 });
		printf_s("%8d %8.3lf %8d", cNumRead, test, vkTable['A']);
	
	}
    return 0;
}

