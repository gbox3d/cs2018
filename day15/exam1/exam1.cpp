// day15.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>

CRITICAL_SECTION g_cs;

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	double _tick = 0;
	while (1) {
		_tick += 0.001;
		
		EnterCriticalSection(&g_cs);
		SetConsoleCursorPosition(hStdout, { 35,1 });
		printf_s("%5lf", _tick);
		LeaveCriticalSection(&g_cs);
		Sleep(1);
	}

	return 0;
}

int main()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD _oldInputMode;
	DWORD _NumRead;
	INPUT_RECORD irInBuf[128];

	GetConsoleMode(hStdin, &_oldInputMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	InitializeCriticalSection(&g_cs);

	DWORD dwThreadId;
	HANDLE hThread = CreateThread(
		NULL,0,MyThreadFunction,NULL,0,&dwThreadId
	);

	bool _bloop = true;
	
	while (_bloop) {
		ReadConsoleInput(hStdin, irInBuf, 128, &_NumRead);

		for (DWORD i = 0; i < _NumRead; i++) {
			if (irInBuf[i].EventType == KEY_EVENT) {
				if (irInBuf[i].Event.KeyEvent.bKeyDown) {

					EnterCriticalSection(&g_cs);

					SetConsoleCursorPosition(hStdout, { 0,10 });
					printf_s("           ");
					SetConsoleCursorPosition(hStdout, { 0,10 });
					printf_s("%5d", irInBuf[i].Event.KeyEvent.wVirtualKeyCode);

					LeaveCriticalSection(&g_cs);

				}
			}
		}
		
	}

	SetConsoleMode(hStdin, _oldInputMode);


	return 0;
}

