#pragma once
#include "resource\Resource.h"
#include "scene\SceneManager.h"
#include "../lib\appEnv.hpp"
#include "../lib\random.hpp"
#include <memory>

//========================================
//�Q�[���A�v���P�[�V�����N���X
//========================================
class CGameApplication{
public:
	CGameApplication();
	~CGameApplication() = default;

	std::shared_ptr<AppEnv>m_app_env;

	//�@�X�V
	void Update();
private:
	std::shared_ptr<Random>m_random;
	std::unique_ptr<CSceneManager>m_scene_manager;
	//�@���\�[�X�̓ǂݍ���
	CResource m_rec;
};

