// exam11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

struct _S_GAMEOBJECT {
	char m_szName[32];
	int m_nHp;
	int m_nAttack;
	int m_nMp;
	int m_nDep;
};

void parsePlayerInfo(_S_GAMEOBJECT *pObj, char *szBuf)
{
	const char *deli = " ";
	char *_temp;
	char *pToken;
	pToken = strtok_s(szBuf, deli, &_temp);
	//puts(pToken);
	pToken = strtok_s(NULL, deli, &_temp); //이름
	strcpy_s(pObj->m_szName, sizeof(pObj->m_szName), pToken);
	pToken = strtok_s(NULL, deli, &_temp); //hp
	pObj->m_nHp = atoi(pToken);
	//puts(pToken);
	pToken = strtok_s(NULL, deli, &_temp);
	pObj->m_nMp = atoi(pToken);
	//puts(pToken);
	pToken = strtok_s(NULL, deli, &_temp);
	pObj->m_nAttack = atoi(pToken);
	//puts(pToken);
	pToken = strtok_s(NULL, deli, &_temp);
	pObj->m_nDep = atoi(pToken);
	//puts(pToken);

}

int main()
{
	char szBuf[128];
	_S_GAMEOBJECT player = { 0 };
	while (1) {
		printf_s("명령어 > ");
		gets_s(szBuf, sizeof(szBuf));
		if (strcmp("quit", szBuf) == 0) {
			break;
		}
		else if (!strcmp("dump", szBuf)) {
			printf_s("%12s%4d%4d%4d%4d\n", 
				player.m_szName, player.m_nHp, player.m_nMp, player.m_nDep, player.m_nAttack);
		}
		else if (!strncmp("edit", szBuf,4)) {
			//edit 이름 100 50 6 3
			parsePlayerInfo(&player, szBuf);
		}
		else if (!strncmp("save", szBuf, 4)) {
			FILE *fp = NULL;
			fopen_s(&fp, "save.txt", "w");
			fprintf_s(fp,"edit %s %d %d %d %d\n", 
				player.m_szName, player.m_nHp, player.m_nMp, player.m_nDep, player.m_nAttack);
			fclose(fp);
		}
		else if (!strncmp("load", szBuf, 4)) {
			FILE *fp = NULL;
			fopen_s(&fp, "save.txt", "r");
			
			fgets(szBuf, sizeof(szBuf), fp);
			parsePlayerInfo(&player, szBuf);
			
			fclose(fp);

		}
	}
	
    return 0;
}

