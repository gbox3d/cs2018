// exam9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	const char *ptr_ary[5] = {
		"dog",
		"elephant",
		"horse",
		"tiger",
		"lion"
	};
	char str_ary[5][16] = {
		"dog",
		"elephant",
		"horse",
		"tiger",
		"lion"
	};

	printf_s("%8s%8s\n", ptr_ary[0], str_ary[1]);
    return 0;
}

