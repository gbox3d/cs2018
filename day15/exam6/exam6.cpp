// exam6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"
#include "../../engine/irrlicht/include/irrlicht.h"

int main()
{
	irr::core::vector2df vDir = irr::core::vector2df(1, 0);
	irr::core::vector2df vBasePos = irr::core::vector2df(40, 12);
	HANDLE hStdout;
	TGE::startTGE(&hStdout);
	CHAR_INFO *pBackBuffer = TGE::CreateScreenBuffer();

	double _dbAngle = 0;
	UINT64 _tick = TGE::util::GetTimeMs64();

	while (1) {

		UINT64 _deltaTick = TGE::util::GetTimeMs64() - _tick;
		_tick = TGE::util::GetTimeMs64();

		double _dbDelatTick = (double)_deltaTick / 1000.0;

		TGE::clearScreenBuffer(pBackBuffer, 0x20, 0x0007);

		TGE::setCharacter(pBackBuffer, vBasePos.X, vBasePos.Y, 0x20, 0x00f0);
		
		irr::core::vector2df _pos = vBasePos;
		_pos += (vDir*5.0);
		TGE::setCharacter(pBackBuffer, _pos.X, _pos.Y, 0x20, 0x00e0);

		{
			irr::core::vector2df _pos = vBasePos;
			irr::core::vector2df _vDir = vDir;
			_vDir.rotateBy(90);
			_pos = vBasePos;
			_pos += (_vDir*5.0);
			TGE::setCharacter(pBackBuffer, _pos.X, _pos.Y, 0x20, 0x00c0);
		}

		{
			_dbAngle += (_dbDelatTick * 45);
			irr::core::vector2df _pos = vBasePos;
			irr::core::vector2df _vDir = vDir;
			_vDir.rotateBy(_dbAngle);
			_pos = vBasePos;
			_pos += (_vDir*5.0);
			TGE::setCharacter(pBackBuffer, irr::core::round32( _pos.X), irr::core::round32(_pos.Y), 
				0x20, 0x00a0);
		}

		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	TGE::endTGE();
	free(pBackBuffer);

    return 0;
}

