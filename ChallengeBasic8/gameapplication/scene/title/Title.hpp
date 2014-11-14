#pragma once
#include "../Scene.hpp"
#include "../../resource/Resource.hpp"
#include <memory>

class CSceneManager;

//========================================
//�^�C�g���N���X
//========================================
class CTitle : public CScene{
public:
	CTitle(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager);

	//�@�ŏ��̏���
	void Start();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

private:

	CResource &m_res;														//�@���\�[�X
	
};

