// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void dump(char **buf)
{
	int i;
	for (i = 0; buf[i] != 0; i++) {
		printf_s("%s \n", buf[i]);
	}

}

int main()
{
	
	char szCmdBuf[32];
	char *strBuf[100] = { NULL};
	while (1)
	{
		printf_s("명령어 >");
		gets_s(szCmdBuf, sizeof(szCmdBuf));
		if (strcmp(szCmdBuf, "quit") == 0) {
			int i;
			for (i = 0; strBuf[i] != 0; i++) {
				free(strBuf[i]);
				strBuf[i] = NULL;
			}
			break;
		}
		else if (strcmp(szCmdBuf, "add") == 0) {
			printf_s("문자열을 입력하세요. :");
			gets_s(szCmdBuf, 32);

			int i;
			for (i = 0; strBuf[i] != 0; i++) {}

			strBuf[i] = (char *)malloc(strlen(szCmdBuf)+1); //공간 확보
			strcpy_s(strBuf[i], strlen(szCmdBuf) + 1, szCmdBuf);//strBuf[i] = szCmdBuf;
		}
		else if (strcmp(szCmdBuf, "dump") == 0) {
			dump(strBuf);
		}

	}
    return 0;
}

