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
			nTail++;
		}
		else if (strcmp("dump", szCmd) == 0) {
			//
			for (int i = nTail; i < nHead; i++)
			{
				printf_s("%c", cBuf[i]);
			}
			printf_s("\n");
		}
		else if (strcmp("compact", szCmd) == 0) {
			int _len = nHead - nTail;
			for (int i = 0; i < _len; i++) {
				cBuf[i] = cBuf[nTail + i];
			}
			nTail = 0;
			nHead = _len;
		}
		else {
			printf_s("존재하지않는 명령어 : %s 입니다.\n ", szCmd);
		}
	}

	return 0;
}
