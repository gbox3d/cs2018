// exam14.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <string.h>
#include <malloc.h>

int main()
{
	const char *szMsg = "hello world";
	char *pTemp;

	pTemp = (char *)malloc(7);

	//strcpy_s(pTemp, strlen(szMsg) + 1, szMsg);

	memcpy(pTemp, szMsg+4, 6);
	pTemp[6] = 0x00;

	printf_s("%s \n", pTemp);

	free(pTemp);

    return 0;
}

