// exam6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
enum season {spring=1000, summer, fall, winter,rat=2000,cow,tiger,rabit,dragon,snake};

typedef int _BYTE32;

int main()
{
	_BYTE32 myVal = 100;

	printf_s("%d \n", myVal);

	printf_s("%d %d %d %d\n", spring, summer, fall, winter);
	printf_s("%d %d %d %d\n", rat, cow, tiger, rabit);
    return 0;

	
}

