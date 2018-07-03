// exam12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	const char *str1 = "apple";

	char buf[64];

	strcpy_s(buf, 64, str1);

	printf_s("%s\n", buf);

	printf_s("%d\n", strnlen_s(buf, sizeof(buf)));

	printf_s("같은 문자열 일때 : %d \n", strcmp("cat", "cat"));
	printf_s("다른 문자열 일때 : %d \n", strcmp("cat", "bat"));
	printf_s("다른 문자열 일때 : %d \n", strcmp("cat", "dog"));
	
	//strcat
	strcat_s(buf, sizeof(buf), "pie"); //buf <= buf + "pie"
	printf_s("%s \n", buf);


	
    return 0;
}

