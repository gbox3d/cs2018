// exam13.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char strBuf[64];

	//scanf_s("%s", strBuf,64);
	gets_s(strBuf, sizeof(strBuf));

	//printf_s("입력한 문장은 : %s\n", strBuf);
	puts("입력한 문장은 :");
	puts(strBuf);

	printf_s("문자를 입력하세요 :");
	char _c;
	_c = getchar();
	putchar(_c);
	putchar('\n');


    return 0;
}

