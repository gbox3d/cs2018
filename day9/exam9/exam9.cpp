// exam9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	FILE *fp;
	fopen_s(&fp, "a.txt", "w+");

	fputs("orc fighter,100,200,70\n",fp);

	fclose(fp);

	char szBuf[32];
	fopen_s(&fp, "a.txt", "r+");
	fgets(szBuf, sizeof(szBuf), fp);

	printf_s("%s \n", szBuf);


    return 0;
}

