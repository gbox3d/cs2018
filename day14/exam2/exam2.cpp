//TGE skeleton 
#include "stdafx.h"
#include "../../engine/tge.h"
#include "../../engine//tge_sprite.h"

struct S_GAME_OBJECT{
	COORD m_cdPosition;
	tge_sprite::S_SPRITE_OBJECT m_SpriteObject;
	int m_nFSM;
};

void Apply(S_GAME_OBJECT *pObj)
{
	//S_GAME_OBJECT *pObj = &crossObj;

	switch (pObj->m_nFSM) {
	case 0:
		pObj->m_nFSM = 10;
		break;
	case 10:
		if (pObj->m_cdPosition.X < 76) {
			pObj->m_cdPosition.X += 1;
		}
		else {
			pObj->m_nFSM = 20;
		}
		break;
	case 20:
		if (pObj->m_cdPosition.X > 5) {
			pObj->m_cdPosition.X -= 1;
		}
		else {
			pObj->m_nFSM = 10;
		}
		break;
	}

}

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	TGE::clearScreenBuffer(0x20, 0x0090);


	CHAR_INFO *pBackDataBuf = TGE::CreateScreenBuffer();
	TGE::loadBufferBinary(pBackDataBuf, "../../pub_res/1.map");


	CHAR_INFO *pBackBuff = TGE::CreateScreenBuffer();
	S_GAME_OBJECT crossObj = {0};
	tge_sprite::load(&(crossObj.m_SpriteObject), "../../pub_res/cross.spr");
	
	bool _bLoop = true;
	static int _nFSM = 0;
	while (_bLoop)
	{
		static char szCmdBuf[128];
		
		//ai
		Sleep(50);

		Apply(&crossObj);

		memcpy_s(pBackBuff, SCREEN_BUF_SIZE * sizeof(CHAR_INFO),
			pBackDataBuf, SCREEN_BUF_SIZE * sizeof(CHAR_INFO)
		);
		
		tge_sprite::put(&(crossObj.m_SpriteObject),
			crossObj.m_cdPosition.X, 
			crossObj.m_cdPosition.Y,
			pBackBuff);
			
		memcpy_s(TGE::g_chiBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO),
			pBackBuff, SCREEN_BUF_SIZE * sizeof(CHAR_INFO)
			);

		//랜더 (화면 갱신)
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	SetConsoleMode(hStdin, fdwOldMode);

	free(pBackBuff);

	return 0;
}