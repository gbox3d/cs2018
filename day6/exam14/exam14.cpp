// exam14.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char szBuf[8];

	for (int i = 0; i < 8; i++) {
		szBuf[i] = getchar();
	}

	printf("%s \n", szBuf);


    return 0;
}

