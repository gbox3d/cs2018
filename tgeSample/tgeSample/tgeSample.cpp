// tgeSample.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include "../../engine/tge.h"
#include "../../engine/tge_sprite.h"


int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	CHAR_INFO *pBackBuf = TGE::CreateScreenBuffer();
	CHAR_INFO *pMapDataBuf = TGE::CreateScreenBuffer();
	TGE::loadBufferBinary(pMapDataBuf, "../../pub_res/1.map");

	tge_sprite::S_SPRITE_OBJECT sprTest;
	tge_sprite::Init(&sprTest);
	tge_sprite::load(&sprTest, "../../pub_res/cross.spr");

	bool bLoop = true;
	while (bLoop)
	{
		//TGE::clearScreenBuffer(pBackBuf, 0x20, 0x0000);
		TGE::copyScreenBuffer(pBackBuf, pMapDataBuf);

		tge_sprite::put(&sprTest, 40, 12,pBackBuf);



		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}

	free(pBackBuf);
	free(pMapDataBuf);
	TGE::endTGE();
    return 0;
}

