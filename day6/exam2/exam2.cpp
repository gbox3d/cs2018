// exam2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char nums[5] = { 1,2,3,4,5 };

	printf_s("%d\n%d\n%d\n%d\n%d\n", nums[0], nums[1], nums[2], nums[3], nums[4]);
	printf_s("%d\n%d\n%d\n%d\n%d\n", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);

    return 0;
}

