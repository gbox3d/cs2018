// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ages[5];
	scanf_s("%d %d %d %d %d", &ages[0], &ages[1], &ages[2], &ages[3], &ages[4]);

	int nMax;
	nMax = ages[0];

	for (int i = 1; i < 5; i++) {
		if (nMax < ages[i]) {
			nMax = ages[i];
		}
		//printf_s("%d \n", ages[i]);
	}

	printf_s("%d \n", nMax);

    return 0;
}

