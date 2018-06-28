// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

/*

helloworld123456hi
**********123456**
*/

int main()
{
	char word[32];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);

	int nArraySize = sizeof(word) / sizeof(word[0]);

	for (int i = 0; i < nArraySize; i++) {
		if (word[i] == 0x00) break;

		if ((word[i] >= 65 && word[i] <= 90) || //대문자
			(word[i] >= 97 && word[i] <= 122) //소문자
			)
		{
			word[i] = '*';
		}
	}
	printf_s("변환된 문자열 %s \n", word);


    return 0;
}

