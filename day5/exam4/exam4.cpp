// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
// simple REPL 기본형
int main()
{
	char szCmd[32];
	char cBuf[256];
	int nHead=0;
	int nTail=0;

	while (1) {
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) {
			printf_s("프로그램을 종료 합니다.");
			break;
		}
		else if (strcmp("ins", szCmd) == 0) {
			char _;
			scanf_s("%c", &_,1);
			scanf_s("%c", &_,1);
			cBuf[nHead++] = _;
		}
		else if (strcmp("del", szCmd) == 0) {
		}
		else if (strcmp("dump", szCmd) == 0) {
		}
		else {
			printf_s("존재하지않는 명령어 : %s 입니다.\n ", szCmd);
		}
	}

	return 0;
}
