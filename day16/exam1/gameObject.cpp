#include "stdafx.h"
#include "../../engine/irrlicht/include/irrlicht.h"
#include "../../engine/tge.h"
#include "../../engine/tge_sprite.h"
#include "gameobject.h"

namespace cs2018prj {

	namespace playerObject {
		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbSpeed, 
			tge_sprite::S_SPRITE_OBJECT *pSpr)
		{
			pObj->m_posx = _x;
			pObj->m_posy = _y;
			pObj->m_dbSpeed = _dbSpeed;
			pObj->m_nFSM = 0;
			pObj->m_pSprite = pSpr;
			pObj->m_bActive = true;
			//pObj->m_Spr = _spr;
		}

		void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
		{
			if (TGE::input::g_KeyTable[VK_RIGHT]) {
				pObj->m_posx += (pObj->m_dbSpeed * _deltaTick);
			}
			if (TGE::input::g_KeyTable[VK_LEFT]) {
				pObj->m_posx -= (pObj->m_dbSpeed * _deltaTick);
			}
			if (TGE::input::g_KeyTable[VK_UP]) {
				pObj->m_posy -= (pObj->m_dbSpeed * _deltaTick);
			}
			if (TGE::input::g_KeyTable[VK_DOWN]) {
				pObj->m_posy += (pObj->m_dbSpeed * _deltaTick);
			}

			switch (pObj->m_nFSM)
			{
			case 0: //정지
				if (TGE::input::g_KeyTable[VK_SPACE]) {
					pObj->m_nFSM = 10;
				}
				break;
			case 10: //move
			{
				irr::core::vector2df vTarget = irr::core::vector2df(TGE::input::g_cdMousePos.X,
					TGE::input::g_cdMousePos.Y);
				irr::core::vector2df vCurPos = irr::core::vector2df(pObj->m_posx, pObj->m_posy);
				irr::core::vector2df vDir = vTarget - vCurPos;
				if (vDir.getLength() < 1) {
					pObj->m_nFSM = 0; //정지상태로...
				}
				else {
					vDir.normalize();
					pObj->m_posx += vDir.X * _deltaTick * pObj->m_dbSpeed;
					pObj->m_posy += vDir.Y * _deltaTick * pObj->m_dbSpeed;
				}
			}
			break;
			case 100:
				pObj->m_bActive = false;
				pObj->m_nFSM = 101;
				break;
			case 101: //ko 
				break;
			default:
				break;
			}



		}

		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf)
		{
			/*TGE::setCharacter(pTargetBuf, pObj->m_posx, pObj->m_posy,
				pObj->m_Spr.Char.UnicodeChar,
				pObj->m_Spr.Attributes);*/
			if (pObj->m_bActive) {
				tge_sprite::put(pObj->m_pSprite,
					irr::core::round32(pObj->m_posx + pObj->m_translation.X),
					irr::core::round32(pObj->m_posy + pObj->m_translation.Y), pTargetBuf);
			}
		}

	}

	namespace ailenObject {
		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbSpeed,
			tge_sprite::S_SPRITE_OBJECT *pSpr)
		{
			pObj->m_posx = _x;
			pObj->m_posy = _y;
			pObj->m_dbSpeed = _dbSpeed;
			pObj->m_nFSM = 0;
			pObj->m_pSprite = pSpr;
			pObj->m_vDir = irr::core::vector2df(1, 0);
			pObj->m_pTargetObj = NULL;
			pObj->m_pWepon = NULL;
		}

		void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
		{
			switch (pObj->m_nFSM)
			{
			case 0:
				pObj->m_nFSM = 10;
				pObj->m_dbWorkTick = 0;
				break;
			case 10: //순찰모드 
				pObj->m_posx += (pObj->m_dbSpeed * _deltaTick) * pObj->m_vDir.X;
				pObj->m_posy += (pObj->m_dbSpeed * _deltaTick) * pObj->m_vDir.Y;
				pObj->m_dbWorkTick += _deltaTick;
				if (pObj->m_dbWorkTick > 3.5) {
					//pObj->m_nFSM = 10;
					pObj->m_vDir.rotateBy(180);
					pObj->m_dbWorkTick = 0;
				}
				if (pObj->m_pTargetObj) {
					irr::core::vector2df a(pObj->m_posx, pObj->m_posy);
					irr::core::vector2df b(pObj->m_pTargetObj->m_posx, pObj->m_pTargetObj->m_posy);
					double fDist = a.getDistanceFrom(b);
					if (fDist < 10) {
						pObj->m_nFSM = 20;
					}
				}
				break;
			case 20: //추적모드 
			{
				irr::core::vector2df a(pObj->m_posx, pObj->m_posy);
				irr::core::vector2df b(pObj->m_pTargetObj->m_posx, pObj->m_pTargetObj->m_posy);
				irr::core::vector2df c = b - a;
				c.normalize();
				pObj->m_posx += c.X * pObj->m_dbSpeed * _deltaTick;
				pObj->m_posy += c.Y * pObj->m_dbSpeed * _deltaTick;

				if (a.getDistanceFrom(b) < 2.5) {
					if (pObj->m_pWepon) {
						cs2018prj::attackObject_claw::S_GAMEOBJECT *pWepon = 
							(cs2018prj::attackObject_claw::S_GAMEOBJECT *)pObj->m_pWepon;
						pWepon->m_posx = pObj->m_pTargetObj->m_posx;
						pWepon->m_posy = pObj->m_pTargetObj->m_posy;
						pWepon->m_nFSM = 10;
						pObj->m_nFSM = 30;
					}
				}

			}
				break;
			default:
				break;
			}
		}

		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf)
		{	
			tge_sprite::put(pObj->m_pSprite,
				irr::core::round32(pObj->m_posx + pObj->m_translation.X),
				irr::core::round32(pObj->m_posy + pObj->m_translation.Y), pTargetBuf);
		}
	}

	namespace attackObject_claw {
		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbSpeed,
			tge_sprite::S_SPRITE_OBJECT *pSpr)
		{
			pObj->m_posx = _x;
			pObj->m_posy = _y;
			pObj->m_dbSpeed = _dbSpeed;
			pObj->m_nFSM = 0;
			pObj->m_pSprite = pSpr;
			pObj->m_vDir = irr::core::vector2df(1, 0);
			pObj->m_pTargetObj = NULL;
			pObj->m_bActive = false;
		}

		void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
		{
			switch (pObj->m_nFSM)
			{
			case 0: // sleep down
				break;
			case 10: //wake up
				pObj->m_dbWorkTick = 0;
				pObj->m_bActive = true;
				pObj->m_nFSM = 11;
				break;
			case 11:
			{
				if (pObj->m_pTargetObj) {
					irr::core::vector2df a = irr::core::vector2df(pObj->m_posx, pObj->m_posy);
					irr::core::vector2df b = 
						irr::core::vector2df(pObj->m_pTargetObj->m_posx, pObj->m_pTargetObj->m_posy);

					double fDist = a.getDistanceFrom(b);
					if (fDist < 2) {
						pObj->m_nFSM = 20;
						pObj->m_pTargetObj->m_nFSM = 100;
					}

				}
				pObj->m_dbWorkTick += _deltaTick;
				if (pObj->m_dbWorkTick > 0.5) {
					pObj->m_bActive = false;
					pObj->m_nFSM = 0;
				}
			}	
				break;
			case 20:
				pObj->m_dbWorkTick += _deltaTick;
				if (pObj->m_dbWorkTick > 0.5) {
					pObj->m_bActive = false;
					pObj->m_nFSM = 0;
				}
				break;
			case 100:
				break;
			default:
				break;
			}
			
		}

		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf)
		{
			if (pObj->m_bActive) {
				tge_sprite::put(pObj->m_pSprite,
					irr::core::round32(pObj->m_posx + pObj->m_translation.X),
					irr::core::round32(pObj->m_posy + pObj->m_translation.Y), pTargetBuf);
			}
			
		}
	}

	
}