// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	TGE::clearScreenBuffer(0x2e, 0x0007);

	static char szBuf[32];
	static char szBufToken[8][16];
	
	//setchar 3 4 0x20 0x00e0
	while (1) {
		gets_s(szBuf, sizeof(szBuf));
		char *szpTemp;
		char *pNextToken = NULL;
		const char *pszDelimiter = " ";
		szpTemp = strtok_s(szBuf, pszDelimiter, &pNextToken);
		int _nTokenIndex = 0;
		while (szpTemp != NULL) {
			strcpy_s(szBufToken[_nTokenIndex], sizeof(szBufToken[_nTokenIndex]), szpTemp);
			_nTokenIndex++;
			szpTemp = strtok_s(NULL, pszDelimiter, &pNextToken);
		}

		printf_s("토큰 수 :%d  \n", _nTokenIndex);
		for (int i = 0; i < _nTokenIndex; i++) {
			printf_s("%s \n", szBufToken[i]);
		}

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
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}
    return 0;
}

