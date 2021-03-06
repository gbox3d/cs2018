// _2_console.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <Windows.h>

//color 바이트구성
//8421 IRGB
// (back | fore)

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	WORD wOldColorAttrs;

	if (!GetConsoleScreenBufferInfo(hConsole, &csbiInfo))
	{
		MessageBox(NULL, TEXT("GetConsoleScreenBufferInfo"),
			TEXT("Console Error"), MB_OK);
		return 1;
	}

	wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(hConsole, 0x9e);
	printf_s("hello \n");

	SetConsoleTextAttribute(hConsole, wOldColorAttrs);

}

