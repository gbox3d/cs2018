// exam6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[5] = { 1,2,3,4,5 };

	int *ap = ary;

	printf_s("%d \n", *(ap+2));
	printf_s("%d \n", ap[2]);

	ary[0] = 6;
	//ary = ap + 2;
	printf_s("%d \n", *(ary+0));
	




    return 0;
}

