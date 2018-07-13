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

	}

	void Render(S_GAMEOBJECT *pObj,CHAR_INFO *pTargetBuf)
	{
		TGE::setCharacter(pTargetBuf, pObj->m_posx, pObj->m_posy,
			pObj->m_Spr.Char.UnicodeChar,
			pObj->m_Spr.Attributes );
	}
}