// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nAge;
	scanf_s("%d",&nAge);

	if (nAge <= 6 || nAge >= 70) {
		printf("무료입장\n");
	}
	else {
		printf("입장료 3000원\n");
	}


    return 0;
}

