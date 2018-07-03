// exam3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void count()
{
	int a = 0;
	a++;
	printf_s("%d\n", a);
}

void count2()
{
	static int a = 0;
	a++;
	printf_s("%d\n", a);
}

void count3(int *a)
{
	(*a)++;
	printf_s("%d\n",*a);
}

int main()
{
	count();
	count();

	count2();
	count2();
	int a = 0;
	count3(&a);
	count3(&a);

    return 0;
}

