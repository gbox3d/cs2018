// exam5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int bonus; //보너스
	int salery; //본봉급

	printf("본봉과 보너스를 입력 하세요 :");
	scanf_s("%d %d", &bonus, &salery);

	int  total = bonus + salery;
	int tex = total * 0.09;

	printf("%lf %d \n", total * 0.09, tex );

	printf("실지급액 : %d 만원\n", total - tex);

    return 0;
}

