// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void count()
{
	int static a = 0;
}

int main()
{
	printf_s("명령어 >");
	char szCmdBuf[32];
	while (1)
	{
		gets_s(szCmdBuf, sizeof(szCmdBuf));
		if (strcmp(szCmdBuf, "quit") == 0 ) {
			break;
		}
		else {
			printf_s("%s 는 처리할수없는 명령어 입니다.\n", szCmdBuf);
		}
	}
	printf_s("프로그램을 종료합니다!\n");
    return 0;
}

