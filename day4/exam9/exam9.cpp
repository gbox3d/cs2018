// exam9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[32];
	scanf_s("%s", word,sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);

	//printf_s("입력한 크기는 : %d \n", sizeof(word) /sizeof(word[0]) );
	int nCount = 0;
	int nCount_alpha = 0;
	int nArray_size = sizeof(word) / sizeof(word[0]);
	for (int i = 0; i < nArray_size; i++) {
		if (word[i] == 0x00) {
			break;
		}
		if ((word[i] >= 65 && word[i] <= 90) || //대문자
			(word[i] >= 97 && word[i] <= 122) //소문자
			)
		{
			nCount_alpha++;
		}
		nCount++;
	}
	printf_s("입력한 크기는 : %d \n", nCount);
	printf_s("알파벳 수 : %d \n", nCount_alpha);

    return 0;
}

