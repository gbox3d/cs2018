// exam10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nHeight = 0;
	int nDay = 0;
	
	do {
		printf("%d 일째 %d cm 등판완료 \n", nDay, nHeight);
		nDay = nDay + 1;
		nHeight = nHeight + 55;
	} while (nHeight < 300);

	//nHeight = 0;
	while (nHeight < 300) {
		printf("%d 일째 %d cm 등판완료 \n", nDay, nHeight);
		nDay = nDay + 1;
		nHeight = nHeight + 55;
	} 

	printf("끝났습니다.");
    return 0;
}

