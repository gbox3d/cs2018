// exam3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("%d\n", 1234);
	printf("%10d\n", 1234);

	int a = 10;
	double b = 3.0;

	//double c = (double)a / (double)b;
	double c = a / b;

	printf("%lf\n", c );
	printf("%10lf\n",c);

	printf("%10.2lf\n", 3.141592);

	printf("%s######\n", "hello");
	printf("%10s######\n", "hello");
	printf("%-10s######\n", "hello");

	

    return 0;
}

