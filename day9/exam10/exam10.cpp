// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num;
	char name[20];

	fputs("숫자입력", stdout);
	scanf_s("%d", &num);
	//fputs("문자열 입력", stdout);
	scanf_s("%s", name,20);

	printf_s("%d 와 ,%s 를 입력했습니다.", num, name);

    return 0;
}

