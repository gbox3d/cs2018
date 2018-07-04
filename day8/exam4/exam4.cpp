// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void print_ary(int nCount,const char **pptr_ary)
{
	for (int i = 0; i < nCount; i++) {
		printf_s("%s \n", pptr_ary[i]);
	}

}

int main()
{
	const char *ptr_ary[] = {
		"eagle","tiger","lion","squirrel"
	};
	int count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
	print_ary(count,ptr_ary);

    return 0;
}

