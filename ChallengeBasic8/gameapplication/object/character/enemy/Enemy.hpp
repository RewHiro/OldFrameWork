#pragma once
#include "../Character.hpp"
class CEnemy : public CCharacter{
public:
	CEnemy();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

private:
	int m_count;
};

