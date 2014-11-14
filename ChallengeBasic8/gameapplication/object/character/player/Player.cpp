#include "Player.hpp"

CPlayer::CPlayer(std::shared_ptr<AppEnv>app_env) :
m_app_env(app_env)
{
}

//�@�X�V
void CPlayer::Update(){
	if (!m_is_active)return;
}

//�@�`��
void CPlayer::Draw(){
	if (!m_is_active)return;
	drawFillBox(100, 0, 64, 64, Color(1, 1, 1));
}
