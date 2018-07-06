// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include "tge.h"

int main()
{	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(hStdout,0, 26);

	clearScreenBuffer(g_chiBuffer);

	setCharacter(g_chiBuffer, 20, 3, 'A', 0x00cf);
	setCharacter(g_chiBuffer, 20, 4, 'B', 0x00cf);

	updateBuffer(hStdout, g_chiBuffer);

    return 0;
}

