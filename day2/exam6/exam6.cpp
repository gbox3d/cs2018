// exam6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	double fUseElec; //사용량
	double fTotal; // 총사용 요금
	printf("사용량을 입력하세요 : ");
	scanf_s("%lf", &fUseElec);

	fTotal = 660 + (fUseElec * 88.5);
	double fTex = fTotal * 0.09;

	printf("최종 사용 요금 : %lf \n", fTotal - fTex);

    return 0;
}

