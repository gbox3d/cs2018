#include "stdafx.h"
#include "../../engine/tge.h"
#include "gameobject.h"

namespace cs2018prj {

	void Init( S_GAMEOBJECT *pObj, double _x,double _y,CHAR_INFO _spr)
	{
		pObj->m_posx = _x;
		pObj->m_posy = _y;
		pObj->m_nFSM = 0;
		pObj->m_Spr = _spr;
	}

	void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
	{
		if (TGE::input::g_KeyTable[VK_RIGHT]) {
			pObj->m_posx += 0.01;
		}
		if (TGE::input::g_KeyTable[VK_LEFT]) {
			pObj->m_posx -= 0.01;
		}
		if (TGE::input::g_KeyTable[VK_UP]) {
			pObj->m_posy -= 0.01;
		}
		if (TGE::input::g_KeyTable[VK_DOWN]) {
			pObj->m_posy += 0.01;
		}


	}

	void Render(S_GAMEOBJECT *pObj,CHAR_INFO *pTargetBuf)
	{
		TGE::setCharacter(pTargetBuf, pObj->m_posx, pObj->m_posy,
			pObj->m_Spr.Char.UnicodeChar,
			pObj->m_Spr.Attributes );
	}
}