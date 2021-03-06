// exam8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "tge.h"

void drawBox(CHAR_INFO *pBuf, int _posx, int _posy, int _width, int _height)
{
	int x, y;

	/*int _posx = 10;
	int _posy = 10;
	int _width = 5;
	int _height = 3;*/

	for (y = 0; y < _height; y++) {
		for (x = 0; x < _width; x++) {
			setCharacter(pBuf, _posx + x, _posy + y, 0x20, 0x000f);
		}
	}
}

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	clearScreenBuffer(g_chiBuffer);
	drawBox(g_chiBuffer, 3, 3, 5, 3);
	drawBox(g_chiBuffer, 10, 5, 2, 5);
	updateBuffer(hStdout, g_chiBuffer);

    return 0;
}

