// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include <Windows.h>

WORD g_keyTable[1024] = { 0 };

bool g_bThreadRun;

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{	
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD _oldInputMode;
	DWORD _NumRead;
	INPUT_RECORD irInBuf[128];

	GetConsoleMode(hStdin, &_oldInputMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	g_bThreadRun = true;
	while (g_bThreadRun) {
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
	printf_s("stop thread\n");
	return 0;
}

int main()
{	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwThreadId;
	HANDLE hThread = CreateThread(
		NULL, 0, MyThreadFunction, NULL, 0, &dwThreadId
	);
	double _tick = 0;
	bool _bloop = true;
	while (_bloop) {
		SetConsoleCursorPosition(hStdout, { 0,10 });
		printf_s("                                                       ");
		SetConsoleCursorPosition(hStdout, { 0,10 });
		printf_s("%5d %5d", g_keyTable['A'],g_keyTable[VK_UP]);

		SetConsoleCursorPosition(hStdout, { 30,1 });
		printf_s("                                                       ");
		SetConsoleCursorPosition(hStdout, { 30,1 });
		_tick+=0.001;
		printf_s("%lf", _tick);
		if (g_keyTable['Q']) {
			_bloop = false;
		}
	}

	g_bThreadRun = false;
	WaitForSingleObject(hThread, 1000);

	return 0;
}

