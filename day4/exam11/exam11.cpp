// exam11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[32];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);

	int nArraySize = sizeof(word) / sizeof(word[0]);
	int nLength=0;

	for (int i = 0; i < nArraySize; i++) {
		if (word[i] == 0x00) break;
		nLength++;
	}

	printf_s("문자열크기 : %d\n", nLength);

	for (int i = 0; i < nLength/2; i++)
	{
		char _temp;
		_temp = word[i];
		word[i] = word[ (nLength-1) - i];
		word[(nLength - 1) - i] = _temp;
	}

	printf_s("변환 결과 : %s \n",word);


	/*
	char _temp;
	_temp = word[0];
	word[0] = word[1];
	word[1] = _temp;
	
	for (int i = 0; i < nArraySize; i++) {

	}
	*/
    return 0;
}

