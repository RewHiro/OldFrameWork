#pragma once
#include "../../lib/vector.hpp"
#include <vector>
#include <memory>
#include <list>

//========================================
//�I�u�W�F�N�g�N���X(���N���X)
//========================================

class Object{
public:
	Object() = default;
	virtual ~Object() = default;

	//�@��Ԃ̎��
	enum class State{
		NONE,				// ���݂��Ȃ�
		LIVE,				//�@�����Ă�
		INVINCIBLE,			//�@���G
		DEATH,				//�@���S
		EFFECT,				//�@�G�t�F�N�g����
		MOVE				//�@�ړ�
	};
	//�@�X�V
	virtual void Update() = 0;
	//�@�`��
	virtual void Draw() = 0;
	
	//�@�^�X�N�̏I������
	bool isRunOut(){
		if (m_state == State::NONE){
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

	//�@���a���擾
	Vec2f GetR(){
		return m_r;
	}

	//�@��Ԃ��擾
	State GetState(){
		return m_state;
	}

	//�@��������Z�b�g
	void SetHit(bool hit){
		m_ishit = hit;
	}

protected:
	bool m_ishit = false;
	int m_alpha;
	int m_hp;
	float m_alphaf;

	Vec2f m_pos;
	Vec2f m_vec;
	Vec2f m_r;					//�@���a
	State m_state;
};

typedef std::vector<std::unique_ptr<Object>> ArrayVec;
typedef std::vector<std::shared_ptr<Object>> ArrayList;