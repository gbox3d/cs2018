// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int sum(int a, int b)
{
	return a + b;
}

int _doit(int(*fp)(int, int), int a, int b)
{
	return fp(a, b);
}

int main()
{
	int(*fp)(int, int);
	fp = sum;
	printf_s("%d \n", sum(1, 2));
	printf_s("%d \n", fp(1, 2));
	printf_s("%d \n", _doit(sum,1,2));
    return 0;
}

