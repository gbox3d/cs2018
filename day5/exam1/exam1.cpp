// exam1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

/*

*/

int main()
{
	char strTemp[] = "test/*hello*/12354";
	int i;
	int nFSM = 0;
	for (i = 1; i < sizeof(strTemp); i++) {

		if (nFSM == 0) {
			if(strTemp[i - 1] == '/' && strTemp[i] == '*') {
				nFSM = 1;
			}
			//strTemp[i] = ' ';
		}
		else if (nFSM == 1) {
			if (strTemp[i] == '*' ) {
				nFSM = 0;
			}
			strTemp[i] = ' ';
		}
		else if (nFSM == 2) {
			if (strTemp[i] == '/') nFSM = 0;
			else {
				nFSM = 1;
				strTemp[i] = ' ';
			}
		}
		
	}

	printf_s("%s\n", strTemp);

    return 0;
}

