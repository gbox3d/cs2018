// exam5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <malloc.h>

union student
{
	double grade;
	int num;
};

int main()
{
	student a;
	a.num = 10;
	printf_s("%d %lf \n", a.num, a.grade);

	student b;
	b.grade = 10.0;
	printf_s("%d %lf \n", b.num, b.grade);

	printf_s("%d %d \n", &(b.num), &(b.grade) );

	printf_s("%d \n", sizeof(student));

	void *pUnion;
	pUnion = malloc(8);

	*(int *)pUnion = 10;

	printf_s("%d %lf \n", *(int *)pUnion, *(double *)pUnion);

	*(double *)pUnion = 10.0;
	printf_s("%d %lf \n", *(int *)pUnion, *(double *)pUnion);

    return 0;
}

