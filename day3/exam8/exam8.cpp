// exam8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char cGender;

	scanf_s("%c", &cGender,sizeof(cGender));

	if (cGender == 'm') {
		printf("남자입니다.\n");

	}
	else if (cGender == 'f') {
		printf("여자입니다.\n");
	}
	else {
		printf("잘못입력 하셨습니다.\n");
	}

    return 0;
}

