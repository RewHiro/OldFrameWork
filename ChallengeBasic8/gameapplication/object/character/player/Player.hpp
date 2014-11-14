#pragma once
#include "../Character.hpp"

class CPlayer : public CCharacter
{
public:
	CPlayer(std::shared_ptr<AppEnv>app_env);

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();


private:
	std::shared_ptr<AppEnv>m_app_env;									//�@�A�v���C�x���g�����锠
};

