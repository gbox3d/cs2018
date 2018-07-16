#pragma once
namespace cs2018prj {

	namespace playerObject {
		struct S_GAMEOBJECT {
			double m_dbSpeed;
			double m_posx, m_posy;
			//CHAR_INFO m_Spr;
			tge_sprite::S_SPRITE_OBJECT *m_pSprite;
			irr::core::vector2df m_translation;
			int m_nFSM;
		};

		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbSpeed, 
			tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}
	
}