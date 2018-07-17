#pragma once
namespace cs2018prj {

	struct S_GAMEOBJECT {
		double m_dbSpeed;
		//double m_posx, m_posy;
		irr::core::vector2df m_vPos;
		double m_dbAngle;
		double m_dbWorkTick;
		void *m_pWepon;
		tge_sprite::S_SPRITE_OBJECT *m_pSprite;
		irr::core::vector2df m_translation;
		int m_nFSM;
		bool m_bActive;
		void(*m_fpApply)(S_GAMEOBJECT *, double);
		void(*m_fpRender)(S_GAMEOBJECT *, CHAR_INFO *);
		void(*m_fpClone)(S_GAMEOBJECT *pObj);
	};

	namespace playerObject {
		struct S_SUBOBJECT {

		};

		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed, 
			tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}
	namespace ailenObject {
		struct S_SUBOBJECT {};
		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
			tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
	}
	namespace attackObject {
		namespace claw {

		}
		namespace fire {
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbSpeed,
				tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		}
		
	}
	
}