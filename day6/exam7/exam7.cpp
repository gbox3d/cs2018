// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void ary_prn(int *ap)
//void ary_prn(int ap[])
//void ary_prn(int ap[5])
{
	printf_s("%d \n", sizeof(ap));
	for (int i = 0; i < 5; i++) {
		printf_s("%d ", ap[i]);
	}

	printf_s("\n");

}

int main()
{
	int ary[5] = { 10,20,30,40,50 };
	printf_s( "%d \n", sizeof(ary) );
	ary_prn(ary);

    return 0;
}

