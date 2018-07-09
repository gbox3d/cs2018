// exam4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
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
		TGE::setCursor(hStdout, 0, 0);
		TGE::setCursor(hStdout, 0, 26);
		printf_s("                                                                                     ]");
		TGE::setCursor(hStdout, 0, 26);
		printf_s("[cmd >");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		TGE::doTokenize(szCmdBuf, szTokenBuf);

		if (!strcmp(szTokenBuf[0], "quit")) {
			break;
		}
		if (!strcmp(szTokenBuf[0], "set")) {
			int _xpos = atoi(szTokenBuf[1]);
			int _ypos = atoi(szTokenBuf[2]);
			int _code = strtol(szTokenBuf[3], NULL, 16);
			int _attr = strtol(szTokenBuf[4], NULL, 16);

			TGE::setCharacter(TGE::g_chiBuffer, _xpos, _ypos, _code, _attr);
			
		}
		if (!strcmp(szTokenBuf[0], "clear")) {
		
		}
		//save 1.map
		if (!strcmp(szTokenBuf[0], "save")) {
			FILE *fp;
			fopen_s(&fp, szTokenBuf[1], "w");
			//.......
			for (int i = 0; i < 2000; i++) {
				fprintf_s(fp,"%d  %d %d\n",i, TGE::g_chiBuffer[i].Char.UnicodeChar, TGE::g_chiBuffer[i].Attributes);
			}
			fclose(fp);
		
		}
		if (!strcmp(szTokenBuf[0], "load")) {
			FILE *fp;
			fopen_s(&fp, szTokenBuf[1], "r");
			
			while (fgets(szCmdBuf, sizeof(szCmdBuf), fp) != NULL) {
				printf_s("%s\n", szCmdBuf);

			}

			

			fclose(fp);
			
		
		}


		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}

	return 0;
}
