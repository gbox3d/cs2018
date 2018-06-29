// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
// simple REPL 기본형

char cTileMap[64] = {
	1,1,1,1,1,1,1,1,//0
	1,0,0,0,0,0,0,1,//1
	1,0,0,0,0,0,0,1,//2
	1,0,0,0,0,0,0,1,//3
	1,1,1,0,0,0,0,1,//4
	1,0,0,0,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

int main()
{
	char szCmd[32];

	while (1) {
		printf_s("명령어 >");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) {
			printf_s("프로그램을 종료 합니다.");
			break;
		}
		else if (strcmp("dump", szCmd) == 0) {
			
			for (int y = 0; y < 8; y++)
			{
				for (int x = 0; x < 8; x++)
				{
					printf_s("%d", cTileMap[x + y * 8]);
				}
				printf_s("\n");
			}
		}
		else {
			printf_s("입력 하신 커멘드는 : %s 입니다.\n ", szCmd);
		}
	}

	return 0;
}