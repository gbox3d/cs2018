// exam11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	int i;
	i = 0; //초기식
	while (i <= 100) { //조건식
		printf("%d \n", i);
		//i = i + 1;
		//i++;
		i += 5; //증감식
	}

	i = 0;
	while (i <= 50)
	{
		printf("-");
		i++;
	}
	printf("\n");

	i = 100;
	while (i >= 0) {
		printf("%d\n", i);
		i -= 10;
	}

	i = 0;
	int sum = 0;
	while (i <= 100) {
		if ((i % 2) == 0) {
			printf("짝수 : %d \n", i);
			//sum += i; //누적
			sum = sum + i;
			printf("%d \n", sum);
		}
		else {
			printf("홀수 : %d \n", i);
		}
		i++;
	}
	
    return 0;
}

