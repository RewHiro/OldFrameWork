#pragma once
#include "../Uncopyable.hpp"
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
	bool isRemove(){
		if (!m_is_active){
			return true;
		}
		else {
			return false;
		}
	}

	//�@���W���擾
	Vec2f GetPos(){
		return m_pos;
	}

	//�@���W���擾
	Vec2f GetSize(){
		return m_size;
	}

	enum class Type{
		PLAYER,
		ENEMY
	};

protected:
	int m_alpha;											//�@�A���t�@�l(int)
	float m_alphaf;											//�@�A���t�@�l(float)
	Vec2f m_pos;											//�@�ʒu
	Vec2f m_size;											//�@�傫��
	Vec2f m_vec;											//�@�x�N�g��
	bool m_is_active = true;								//	�A�N�e�B�u�ȏ�Ԃ�
};

typedef std::vector<std::unique_ptr<Object>> ArrayVec;
typedef std::vector<std::shared_ptr<Object>> ArrayList;