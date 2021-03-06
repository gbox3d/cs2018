//TGE skeleton 
#include "stdafx.h"

#include "udp.h"






extern S_GHOST g_ghosts[];
S_GHOST g_Myghost;

int main()
{
	{
		for (int i = 0; i < MAX_GHOST; i++) {
			g_ghosts[i].m_szName[0] = 0x00;
		}
	}

	g_Myghost.m_vPos = irr::core::vector2df(40, 12);

	HANDLE hStdout = NULL;
	TGE::startTGE(&hStdout);

	CHAR_INFO *pBakBuffer = TGE::CreateScreenBuffer();

	bool _bLoop = true;
	static int _nFSM = 0;
	UINT64 _oldTick = TGE::util::GetTimeMs64();

	{
		COORD _pos = { 0, 25 };
		SetConsoleCursorPosition(hStdout, _pos);
	}


	openNetWork(3334);

	

	while (_bLoop)
	{
		//타이밍 
		UINT64 _curTick = TGE::util::GetTimeMs64();
		UINT64 _deltaTick = _curTick - _oldTick;
		_oldTick = _curTick;

		double _dbDeltaTick = (double)(_deltaTick) / 1000.0;

		{
			irr::core::vector2df _vDir(0, 0);
			if (TGE::input::g_KeyTable[VK_UP]) {
				_vDir.Y = -1;
			}
			if (TGE::input::g_KeyTable[VK_DOWN]) {
				_vDir.Y = 1;
			}
			if (TGE::input::g_KeyTable[VK_LEFT]) {
				_vDir.X = -1;
			}
			if (TGE::input::g_KeyTable[VK_RIGHT]) {
				_vDir.X = 1;
			}

			if (_vDir.getLength() > 0) {
				_vDir.normalize();
				g_Myghost.m_vPos += (_vDir * _dbDeltaTick * 5.0);

				sendUdp_Pos(g_Myghost.m_vPos);
			}
		}

		//apply

		//랜더링 전처리
		TGE::clearScreenBuffer(pBakBuffer, 0x20, 0x0007);

		{
			for (int i = 0; i < MAX_GHOST; i++) {
				S_GHOST *pObj = &g_ghosts[i];
				if (strlen(pObj->m_szName) > 0) {
					TGE::setCharacter(pBakBuffer, 
						irr::core::round32(pObj->m_vPos.X), 
						irr::core::round32(pObj->m_vPos.Y), 0x20, 0x00f0);
				}
			}
		}

		//랜더 (화면 갱신)
		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBakBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	free(pBakBuffer);
	TGE::endTGE();

	closeNetwork();

	return 0;

}


