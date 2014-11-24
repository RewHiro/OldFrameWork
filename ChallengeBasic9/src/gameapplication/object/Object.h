#pragma once
#include "../Uncopyable.h"
#include "Transform.h"
#include "../../lib/vector.hpp"
#include <vector>
#include <memory>
#include <list>

//========================================
//�I�u�W�F�N�g�N���X(���N���X)
//========================================

class Object : private Uncopyable{
public:
	Object() = default;
	virtual ~Object() = default;

	//�@�X�V
	virtual void Update() = 0;
	//�@�`��
	virtual void Draw() = 0;
	
	//�@�폜���邩
	bool isRemove(){ return m_is_delete ? true : false; }

	//�@�ʒu���擾
	Vec2f GetPos()const{ return m_hit_model.GetPos(); }

	//�@�ʒu���擾
	Vec2f GetScale()const{ return m_hit_model.GetScale(); }

	//�@�A�N�e�B�u���擾
	bool isActive()const{ return m_is_active; }

protected:
	CTransform m_model;										//�@���f���̏��
	CTransform m_hit_model;									//�@�����蔻��p
	bool m_is_active = true;								//	�A�N�e�B�u�ȏ�Ԃ�
	bool m_is_delete = false;								//	�폜���邩
};