#include "stdafx.h"

void exam2_cjson_write()
{
	cJSON *pRoot = NULL;
	pRoot = cJSON_CreateObject();

	cJSON_AddNumberToObject(pRoot, "xpos", 10); // "xpos" : 10
	cJSON_AddNumberToObject(pRoot, "ypos", 27.9);
	//cJSON_AddFalseToObject(pRoot, "axies");
	cJSON_AddBoolToObject(pRoot, "axies",0);
	cJSON_AddStringToObject(pRoot, "name", "p29a"); // "name" : "p29a"
	
	char szBuf[1024] = { 0 };
	cJSON_PrintPreallocated(pRoot, szBuf, 1024, 0);

	puts(szBuf);
	
	FILE *fp;
	fopen_s(&fp, "out.json", "wt");
	fputs(szBuf, fp);

	fclose(fp);

	cJSON_free(pRoot);

}