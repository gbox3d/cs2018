// exam8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//char word[] = { 'l','o','v','e','\x00' };
	char word[] = "love";

	int nSize = sizeof(word)/sizeof(word[0]);

	for (int i = 0; i < nSize; i++) {
		printf_s("%c", word[i]);
	}
	printf_s("\n");

	printf_s("%s\n", word);

    return 0;
}

