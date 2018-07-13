// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include <Windows.h>

CRITICAL_SECTION g_cs;
WORD g_keyTable[1024] = { 0 };

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{	
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD _oldInputMode;
	DWORD _NumRead;
	INPUT_RECORD irInBuf[128];

	GetConsoleMode(hStdin, &_oldInputMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	while (1) {
		ReadConsoleInput(hStdin, irInBuf, 128, &_NumRead);
		for (DWORD i = 0; i < _NumRead; i++) {
			if (irInBuf[i].EventType == KEY_EVENT) {
				if (irInBuf[i].Event.KeyEvent.bKeyDown) {
					g_keyTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 1;
				}
				else {
					g_keyTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 0;
				}
			}
		}
		Sleep(1);
	}
	SetConsoleMode(hStdin, _oldInputMode);
	return 0;
}

int main()
{
	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	InitializeCriticalSection(&g_cs);

	DWORD dwThreadId;
	HANDLE hThread = CreateThread(
		NULL, 0, MyThreadFunction, NULL, 0, &dwThreadId
	);

	bool _bloop = true;

	while (_bloop) {
		

	}

	


	return 0;
}

