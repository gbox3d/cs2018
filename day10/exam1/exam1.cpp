// exam1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include "gameobject.h"

int main()
{
	_S_GAMEOBJECT *pPlayerObj = NULL;
	CreateObject(&pPlayerObj,"noname",100);
	dumpObject(pPlayerObj);
	free(pPlayerObj);
    return 0;
}

