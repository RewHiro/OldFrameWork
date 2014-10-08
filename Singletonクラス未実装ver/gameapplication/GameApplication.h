#pragma once
#include "resource\Resource.h"
#include "scene\SceneManager.h"
#include "Uncopyable.h"

//========================================
//�Q�[���A�v���P�[�V�����N���X
//========================================

class CGameApplication : private Uncopyable{
public:
	~CGameApplication() = default;

	static CGameApplication &GetInstance(){
		static CGameApplication instance;
		return instance;
	}

	std::shared_ptr<AppEnv>m_app_env;

	//�@�X�V
	void Update();
private:
	CGameApplication();
	std::shared_ptr<Random>m_random;
	CSceneManager &m_scene_manager;
	//�@���\�[�X�̓ǂݍ���
	CResource m_rec;
};

