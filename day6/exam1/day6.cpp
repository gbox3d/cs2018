// day6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	int num;
	int *ptr;
	num = 3;
	ptr = &num;
	
	printf_s("%d %d \n", num, &num);
	printf_s("%d %d \n",*ptr,ptr);

	*ptr = 5;
	printf_s("%d %d \n", *ptr, ptr);
	printf_s("%d %d \n", num, &num);

	int address;
	scanf_s("%d", &address); //주소 입력
	printf_s("%d %d\n", address, *((int *)address)); //주소의 내용보기 

    return 0;
}

