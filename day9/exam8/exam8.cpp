// exam8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	FILE *fp;
	fopen_s(&fp, "b.txt", "w");

	fputc('a',fp);
	putc('a', stdout);


	fclose(fp);

    return 0;
}

