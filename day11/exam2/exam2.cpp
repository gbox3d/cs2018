// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	TGE::clearScreenBuffer(0x2e, 0x0007);
	TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	static char szBuf[32];
	static char szBufToken[8][16];
	
	//setchar 3 4 0x20 0x00e0
	while (1) {

		COORD _cursor;
		_cursor.X = 0;
		_cursor.Y = 26;
		SetConsoleCursorPosition(hStdout, _cursor);
		printf_s("                                                                                     ");
		SetConsoleCursorPosition(hStdout, _cursor);
		printf_s("cmd >");
		gets_s(szBuf, sizeof(szBuf));
		//char *ptr[8]
		TGE::doTokenize(szBuf, szBufToken);

		if (strcmp(szBufToken[0], "quit") == 0) {
			printf_s("bye~ \n");
			break;
		}
		else if(strcmp(szBufToken[0], "setchar") == 0) {
			int _xpos = atoi(szBufToken[1]);
			int _ypos = atoi(szBufToken[2]);
			int _code = strtol(szBufToken[3], NULL, 16);//atoi(szBufToken[3]);
			int _attr = strtol(szBufToken[4], NULL, 16);//atoi(szBufToken[4]);

			TGE::setCharacter(TGE::g_chiBuffer, _xpos, _ypos, _code, _attr);
		}
		else if (strcmp(szBufToken[0], "clear") == 0) {
			TGE::clearScreenBuffer(0x2e, 0x0007);
		}
		//lineV 3 4 8 0x20 0x00c0 
		else if (strcmp(szBufToken[0], "lineV") == 0) {
			int _xpos = atoi(szBufToken[1]);
			int _ypos = atoi(szBufToken[2]);
			int _nLength = atoi(szBufToken[3]);
			int _code = strtol(szBufToken[4], NULL, 16);
			int _attr = strtol(szBufToken[5], NULL, 16);

			TGE::drawLineV(_xpos, _ypos, _nLength, _code, _attr);
		}
		else if (strcmp(szBufToken[0], "lineH") == 0) {
		}

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}
    return 0;
}

