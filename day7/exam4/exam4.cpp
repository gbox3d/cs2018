// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void count()
{
	static int a = 0;
	printf_s("%d \n", a++);
}

void decount()
{
	static int  a = 100;
	printf_s("%d \n", a--);
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
		else if(strcmp(szCmdBuf, "count") == 0)
		{
			count();
		}
		else if (strcmp(szCmdBuf, "decount") == 0)
		{
			decount();
		}
		else {
			printf_s("%s 는 처리할수없는 명령어 입니다.\n", szCmdBuf);
		}
	}
	printf_s("프로그램을 종료합니다!\n");
    return 0;
}

