// exam1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine//tge.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	TGE::clearScreenBuffer(TGE::g_chiBuffer);

	TGE::updateBuffer(hStdout,TGE::g_chiBuffer);
	
    return 0;
}

