#pragma once
#include "ObjectManager.h"
#include "../regist/ObjectRegist.h"
#include "../factory/EnemyFactory.h"

//========================================
//�v���C���[�Ǘ��N���X
//========================================

class CEnemyManager : public CObjectManager{
public:
	CEnemyManager::CEnemyManager(){
		Regist(L"�X���C��", m_factory.Getobject(CEnemyFactory::Type::SLIME, 10, 20));
		Regist(L"�h���S��", m_factory.Getobject(CEnemyFactory::Type::DRAGON, 300, 20));
		m_info_manager(InfoType::ENMEY).GetInfo(InfoType::ENMEY).Regist(m_obj_regist);
	}
private:
	CEnemyFactory m_factory;
};

