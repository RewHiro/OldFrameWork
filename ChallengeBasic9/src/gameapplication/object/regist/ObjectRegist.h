#pragma once
#include "../Object.h"
#include <unordered_map>
#include <string>

//========================================
//�I�u�W�F�N�g�̓o�^�N���X
//========================================

class CObjectRegist{
	typedef std::unordered_multimap < std::wstring, std::shared_ptr<Object>>::iterator ObjMapIt;
public:
	CObjectRegist() = default;

	//�@�o�^
	void Regist(const std::wstring name, const std::shared_ptr<Object>obj){
		m_obj_list.emplace(name, obj);
	}

	//�@�I�u�W�F�N�g�̎擾
	std::unordered_multimap < std::wstring, std::shared_ptr<Object>> Getobject()const{ return m_obj_list; }

	//�@�ŏ��ƍŌ�̃C�e���[�^�[��Ԃ�
	std::pair<ObjMapIt, ObjMapIt> GetItr(){
		return std::make_pair(m_obj_list.begin(), m_obj_list.end());
	}

	//�@�w�肵���͈͂��擾
	std::pair<ObjMapIt, ObjMapIt> GetItr(const std::wstring name){
		return m_obj_list.equal_range(name);
	}

	//�@�폜
	void Erase(const ObjMapIt it){ m_obj_list.erase(it); }

protected:
	std::unordered_multimap < std::wstring, std::shared_ptr<Object>> m_obj_list;
};

