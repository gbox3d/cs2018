// exam1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int inch;
	printf("인치를 입력하세요. :");
	scanf_s("%d", &inch);
	printf("\n");
	printf("==================================================================\n");
	printf("|                      보고서                                    |\n");
	printf("==================================================================\n");
	printf("%d 인치는 %lf cm 입니다. \n",inch,inch * 2.54);
	printf("%d 인치는 \t %lf cm 입니다. \n", inch, inch * 2.54);
	printf("%d 인치는 \r %lf cm 입니다. \n", inch, inch * 2.54);



    return 0;
}

