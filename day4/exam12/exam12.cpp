// exam12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
/*

abcfddsj@kls2!45jvk@ldkfigl132344
abcfddsj@**********@ldkfigl132344


*/

int main()
{
	char word[32];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s \n", word);

	int nArraySize = sizeof(word) / sizeof(word[0]);
	int nLength = 0;

	for (int i = 0; i < nArraySize; i++) {
		if (word[i] == 0x00) break;
		nLength++;
	}
	printf_s("문자열크기 : %d\n", nLength);

	int nFSM = 0;//0 ->normal , 1 ->start
	for (int i = 0; i < nLength; i++)
	{
		//if (word[i] == '@') {
		//}
		if (nFSM == 0) {
			if (word[i] == '@') nFSM = 1;
			printf_s("%c", word[i]);
		}
		else if (nFSM == 1) {
			if (word[i] == '@') nFSM = 0;
			printf_s("*");
		}
	}

	printf_s("\n");

    return 0;
}

