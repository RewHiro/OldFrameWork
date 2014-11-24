#pragma once
#include "ObjectInfo.h"

//========================================
//�I�u�W�F�N�g�̃f�[�^�Ǘ��N���X
//========================================

class CObjectInfoManager{
public:
	CObjectInfoManager() = default;

	enum class Type{
		PLAYER,
		ENMEY,
		ITEM
	};



	//�@�o�^
	CObjectInfoManager& operator()(const CObjectInfoManager::Type name){
		m_info_list.emplace(name, CObjectInfo());
		return *this;
	}

	//�@�N���A
	void Crear(){
		m_info_list.clear();
	}

	//�@�폜
	void Erase(const CObjectInfoManager::Type name){
		m_info_list.erase(name);
	}

	//�@�f�[�^���擾
	CObjectInfo& GetInfo(const Type name)const{ return m_info_list.find(name)->second; }
private:
	static std::unordered_map<Type, CObjectInfo>m_info_list;
};

typedef CObjectInfoManager::Type InfoType;