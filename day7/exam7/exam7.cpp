// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int score_ary[3][5] = {
		{1,2,3,4},
		{5,6,7,8},
		{9, 10, 11, 12}
	};

	{
		int i, j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 5; j++) {
				printf_s("%4d", score_ary[i][j]);
			}
			printf_s("\n");
		}
	}

	return 0;
}

