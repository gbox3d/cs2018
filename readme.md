### c study 2018

https://drive.google.com/open?id=0B2SIfUvbN7xEZUd1ZG44T2dmNFE


tge 엔진용 스켈로톤 코드입니다.</br>
복붙하세요.
```c
//TGE skeleton 
#include "stdafx.h"
#include "../../engine/tge.h"
//#include "gameobject.h"
int main()
{

	HANDLE hStdout = NULL;
	TGE::startTGE(&hStdout);

	/*cs2018prj::S_GAMEOBJECT testObj;
	CHAR_INFO _chr;
	_chr.Attributes = 0x00f0;
	_chr.Char.UnicodeChar = 0x20;
	cs2018prj::Init(&testObj, 40, 12,3.5, _chr);*/
	
	CHAR_INFO *pBakBuffer = TGE::CreateScreenBuffer();

	bool _bLoop = true;
	static int _nFSM = 0;
	UINT64 _oldTick = TGE::util::GetTimeMs64();

	while (_bLoop)
	{	
		UINT64 _curTick = TGE::util::GetTimeMs64();
		UINT64 _deltaTick = _curTick - _oldTick;
		_oldTick = _curTick;

		double _dbDeltaTick = (double)(_deltaTick) / 1000.0;

		//SetConsoleCursorPosition(hStdout,{ 40, 1 });

		static char szCmdBuf[128];
		//입력 처리 
		switch (_nFSM) {
		case 0:
			if (TGE::input::g_KeyTable[VK_RETURN]) {
				_nFSM = 1;
				TGE::input::setEditMode();
			}
			break;
		case 1: //동기  모드
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf_s("                                                 ]");
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[cmd >");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			TGE::input::setNormalMode();
			break;
		}
		//커멘드 처리..
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0) {
				if (!strcmp(szTokenBuf[0], "quit")) {
					_bLoop = false;
				}
			}
			szCmdBuf[0] = 0x00;
		}

		//ai
		//cs2018prj::Apply(&testObj, _dbDeltaTick);

		//랜더링 전처리
		TGE::clearScreenBuffer(pBakBuffer, 0x20, 0x0007);
		//cs2018prj::Render(&testObj, pBakBuffer);

		//랜더 (화면 갱신)
		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBakBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	free(pBakBuffer);
	TGE::endTGE();

	return 0;

}

```



