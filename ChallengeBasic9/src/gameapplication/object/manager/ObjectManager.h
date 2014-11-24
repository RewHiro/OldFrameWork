#pragma once
#include "../Object.h"
#include "../info/ObjectInfoManager.h"
#include <unordered_map>
#include <string>


//========================================
//�I�u�W�F�N�g�Ǘ��N���X(���N���X)
//========================================

class CObjectManager{
public:
	CObjectManager():
		m_obj_regist(std::make_shared<CObjectRegist>()){}

	virtual ~CObjectManager() = default;

	//�@�X�V
	virtual void Update(){
		for (auto& obj : m_obj_regist->Getobject()){
			obj.second->Update();
		}
		Remove();
	}

	//�@�`��
	void Draw(){
		for (auto& obj : m_obj_regist->Getobject()){
			obj.second->Draw();
		}
	}

protected:
	CObjectInfoManager m_info_manager;
	std::shared_ptr<CObjectRegist>m_obj_regist;

	//�@�폜
	void Remove(){
		for (auto it = m_obj_regist->GetItr().first; it != m_obj_regist->GetItr().second;){
			(*it).second->isRemove() ? m_obj_regist->Erase(it++) : ++it;
		}
	}

	//�@�o�^
	void Regist(const std::wstring name ,const std::shared_ptr<Object>obj){
		m_obj_regist->Regist(name, obj);
	}
};

