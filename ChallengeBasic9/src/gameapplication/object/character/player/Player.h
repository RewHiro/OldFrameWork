#pragma once
#include "../Character.h"
#include "../../info/ObjectInfoManager.h"

class CPlayer : public CCharacter
{
public:
	CPlayer(std::shared_ptr<AppEnv>);

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

private:
	std::weak_ptr<AppEnv>m_app_env;
	CObjectInfoManager m_info;
	//�@�ړ�����
	void Move();
};

