// exam3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//int a, b, c, d, e;
	int ages[5];
	int nTot;
	double nAvg;
	scanf_s("%d %d %d %d %d", &ages[0], &ages[1], &ages[2], &ages[3], &ages[4]);

	//nTot = ages[0] + ages[1] + ages[2] + ages[3] + ages[4];

	for (int i = 0; i < 5; i++) {
		nTot += ages[i];
	}

	nAvg = (double)nTot / 5;

	printf_s("평균 : %lf \n", nAvg);
	
    return 0;
}

