// exam9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <malloc.h>

int main()
{
	//int xx[5];
	int *pa;
	pa = (int *)malloc(5* sizeof(int));

	for (int i = 0; i < 5; i++) {
		//scanf_s("%d", &(pa[i]) );
		scanf_s("%d", (pa + i));
	}

	for (int i = 0; i < 5; i++) {
		printf_s("%5d", pa[i]);
		//printf_s("%5d", *(pa + i));
	}

	printf_s("\n");

    return 0;
}

