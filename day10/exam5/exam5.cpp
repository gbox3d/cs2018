// exam5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

// 8421
// 0101 = > 0x5
// 
/*
0 | 0 ->0
0 | 1 ->1
1 | 0 ->1
1 | 1 ->1

0 & 0 = > 0
0 & 1 = > 0
1 & 0 = > 0
1 & 1 = > 1

*/

void outputDec2Bin(int nDec)
{
	//e = 9; //1001 & 0001 = 0 or 1
	unsigned int a = 0x80000000;
	for (int i = 0; i < 32; i++) {
		if (nDec & a) {
			printf_s("1");
		}
		else {
			printf_s("0");
		}
		a = a >> 1;
	}
}

int main()
{
	char a = 1; //0000 0001
	char b = 2;
	char c = 4;
	char d = 8;

	char e = a | b | c | d;

	printf_s("%d %x \n", e, e);

	e = 9; //1001 & 0001 = 0 or 1
	for (int i = 0; i < 8; i++) {
		if (e & a) {
			printf_s("1");
		}
		else {
			printf_s("0");
		}
		a = a << 1;
	}
	// 0010 0100 = > 0110
	char _e = b ^ c;

	printf("%d \n", _e);

	char k = 1;
	for (int i = 0; i < 5; i++) {
		k = k ^ 1;
		printf_s("%d \n", k);
	}

	outputDec2Bin(513);

    return 0;
}

