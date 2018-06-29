// exam5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include <string.h>
// simple REPL 기본형

//add 문자열을 버퍼에 입력
//del 특정위치 문자 삭제
//ins 특정위치 문자 삽입 
//helo
int main()
{
	char szCmd[32];
	char cBuf[256];
	int nLength = 0;

	while (1) {
		printf_s("명령어 > ");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) {
			printf_s("프로그램을 종료 합니다.");
			break;
		}
		else if (strcmp("add", szCmd) == 0) {
			char _[32]; //입력할문자열
			char __;
			scanf_s("%c", &__, 1);
			scanf_s("%s", &_, sizeof(_));
			char _add_size = 0;
			//get size
			for (int i = 0; i < sizeof(_); i++)
			{
				if (_[i] == 0x00) break;
				_add_size++;
			}
			//copy
			for (int i = 0; i < _add_size; i++)
			{
				cBuf[i+nLength] = _[i];
			}
			nLength += _add_size;

			printf_s("%s 을 추가 했습니다.\n",_);
		}
		else if (strcmp("del", szCmd) == 0) {
		}
		else if (strcmp("dump", szCmd) == 0) {
			//
			for (int i = 0; i < nLength; i++)
			{
				printf_s("%c", cBuf[i]);
			}
			printf_s("\n");
		}
		else {
			printf_s("입력 하신 커멘드는 : %s 입니다.\n ", szCmd);
		}
	}

	return 0;
}
