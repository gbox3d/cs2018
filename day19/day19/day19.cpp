// day19.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void exam1()
{
	char szBuf[1024] = { 0 };
	FILE *fp;
	fopen_s(&fp, "test.json", "rt");

	fread_s(szBuf, 1024, 1024, 1, fp);

	puts(szBuf);

	cJSON *pRoot = cJSON_Parse(szBuf);

	cJSON *pName = cJSON_GetObjectItemCaseSensitive(pRoot, "name");
	cJSON *pDistance = cJSON_GetObjectItemCaseSensitive(pRoot, "distance");
	cJSON *pNCode = cJSON_GetObjectItemCaseSensitive(pRoot, "national_code");
	cJSON *pComm = cJSON_GetObjectItemCaseSensitive(pRoot, "comm");

	printf_s("파싱결과 \n");
	printf_s("%s ,%lf %d %d \n", pName->valuestring,pDistance->valuedouble , pNCode->valueint,
		pComm->valueint
		);

	fclose(fp);
}

int main()
{
	exam1();

    return 0;
}

