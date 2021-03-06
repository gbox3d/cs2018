// exam3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	static char szCmdBuf[32];
	static char szTokenBuf[8][16];

	TGE::clearScreenBuffer(0x2e, 0x0007);
	TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	while (1) {
		TGE::setCursor(hStdout,0, 26);
		printf_s("                                                                                     ]");
		TGE::setCursor(hStdout, 0, 26);
		printf_s("[cmd >");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		TGE::doTokenize(szCmdBuf, szTokenBuf);

		if (!strcmp(szTokenBuf[0], "quit")) {
			break;
		}

		
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}

    return 0;
}

