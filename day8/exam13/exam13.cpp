// exam13.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	//move n , move s , move 1,3

	char strMsg[] = "move east and move north set 3,4";
	char *pTemp =NULL;
	const char *pszDelimitor = " ,";

	char *pToken = strtok_s((char *)strMsg, pszDelimitor, &pTemp);

	while (pToken)
	{	
		pToken = strtok_s(NULL, pszDelimitor, &pTemp);
		if (pToken == NULL) break;
		printf_s("%s \n", pToken);
	}


    return 0;
}

