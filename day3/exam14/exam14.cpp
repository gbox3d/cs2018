// exam14.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int i,j;

	for (j = 1; j <= 9; j++) {
		//j = 1; //단 값
		for (i = 0; i <= 9; i++) {
			printf("%d *  %d =  %d \n", j, i, j*i);
		}
	}

    return 0;
}

