// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	int _array[] = { 4,5,7,8,9,19,14,7,4,5,6,7,9,2,3,4,5,7,4,5,6 };
	int nFind;
	int nCount = 0;

	printf_s("찾고싶은 수를 입력 :");
	scanf_s("%d", &nFind);
	int nSize = sizeof(_array) / sizeof(_array[0]);
	for (int i = 0; i < nSize ; i++)
	{
		if (nFind == _array[i]) {
			nCount++;
		}

	}
	printf_s("%d 은 %d개 있습니다\n", nFind, nCount); 
    return 0;
}

