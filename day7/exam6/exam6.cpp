// exam6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

/*

1  4  7  10
2  5  8  11
3  6  9  12

*/

int main()
{
	int num[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int num2[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	
	{
		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				printf_s("%4d", num[j][i]);
			}
			printf_s("\n");
		}
	}

	{
		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {
				printf_s("%4d", num2[(i*4)+j]);
			}
			printf_s("\n");
		}

	}
	
	

    return 0;
}

