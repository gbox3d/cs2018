// exam15.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbInfo;
	WORD wOldColorAttr;

	GetConsoleScreenBufferInfo(hConsole, &csbInfo);

	wOldColorAttr = csbInfo.wAttributes;

	// 0000 0000
	// 8421 8421
	// (back)(fore)
	// iRGB iRGB
	SetConsoleTextAttribute(hConsole, 0x1e );
	printf_s("hello \n");
	SetConsoleTextAttribute(hConsole, 0x2e);
	printf_s("world \n");
	
	SetConsoleTextAttribute(hConsole, wOldColorAttr);

    return 0;
}

