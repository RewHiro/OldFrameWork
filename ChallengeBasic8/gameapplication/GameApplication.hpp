#pragma once
#include "resource\Resource.hpp"
#include "scene\SceneManager.hpp"
#include "Uncopyable.hpp"

//========================================
//�Q�[���A�v���P�[�V�����N���X
//========================================

class CGameApplication : private Uncopyable{
public:

	//�@�C���X�^���X�̎擾
	static CGameApplication& GetInstance(){
		static CGameApplication instance;
		return instance;
	}

	std::shared_ptr<AppEnv>m_app_env;								//�@�A�v���C�x���g

	//�@�X�V
	void Update();

private:
	CGameApplication();
	std::shared_ptr<CSceneManager>m_scene_manager;					//�@�V�[���}�l�[�W���[
	CResource& m_res;												//�@���\�[�X
};

