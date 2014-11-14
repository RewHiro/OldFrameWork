#pragma once
#include "../Uncopyable.hpp"
#include "../../lib/appEnv.hpp"
#include <memory>

class CSceneManager;

//========================================
//�V�[���N���X(���N���X)
//========================================

class CScene : private Uncopyable{
public:
	CScene(const std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager) :
		m_app_env(app_env),
		m_scene_manager(scene_manager){}

	virtual ~CScene() = default;

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//�@�R���g���[���̃t���O�ϊ�
	void TransformOfisControl(bool is_control){ m_is_control = is_control; }

	//�@��ʂ̃T�C�Y
	static const int WIDTH = 1320;
	static const int HEIGHT = 720;

protected:
	std::shared_ptr<AppEnv>m_app_env;									//�@�A�v���C�x���g
	std::weak_ptr<CSceneManager>m_scene_manager;						//�@�V�[���}�l�[�W���[
	bool m_is_control = false;											//�@����̉�

};