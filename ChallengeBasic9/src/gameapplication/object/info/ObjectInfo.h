#pragma once
#include "../regist/ObjectRegist.h"

//========================================
//�I�u�W�F�N�g�̃f�[�^�N���X
//========================================

class CObjectInfo{
	typedef std::unordered_multimap < std::wstring, std::shared_ptr<Object>>::iterator ObjMapIt;
public:
	CObjectInfo() = default;

	//�@�o�^
	void Regist(const std::shared_ptr<CObjectRegist>obj_regist){
		m_obj_regist = obj_regist;
	}
	
	//�@�I�u�W�F�N�g���擾
	std::unordered_multimap < std::wstring, std::shared_ptr<Object>> Getobject()const{
		return m_obj_regist.lock()->Getobject();
	}

	//�@�ŏ��ƍŌ�̃C�e���[�^�[��Ԃ�
	std::pair<ObjMapIt, ObjMapIt> GetItr()const{
		return m_obj_regist.lock()->GetItr();
	}
	std::pair<ObjMapIt, ObjMapIt> GetItr(std::wstring name)const{
		return m_obj_regist.lock()->GetItr(name);
	}

	//�@�ŏ��̃C�e���[�^�[��Ԃ�
	ObjMapIt Begin(const std::wstring name)const{
		return GetItr(name).first;
	}
	ObjMapIt Begin()const{
		return GetItr().first;
	}

	//�@�ŏ��̃C�e���[�^�[��Ԃ�
	ObjMapIt End()const{
		return GetItr().second;
	}
	ObjMapIt End(const std::wstring name)const{
		return GetItr(name).second;
	}

	//�@�|�W�V�������擾
	Vec2f GetPos(const ObjMapIt itr)const{
		return itr->second->GetPos();
	}

	//�@�傫�����擾
	Vec2f GetScale(const ObjMapIt itr)const{
		return itr->second->GetScale();
	}

	//�@�A�N�e�B�u�����擾
	bool GetActive(const ObjMapIt itr)const{
		return itr->second->isActive();
	}

	//�@�_�E���L���X�g
	template <class Type>
	std::shared_ptr<Type> DynamicCast(const ObjMapIt itr)const{
		return std::dynamic_pointer_cast<Type>(itr->second);
	}

private:
	std::weak_ptr<CObjectRegist>m_obj_regist;
};

