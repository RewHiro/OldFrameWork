#pragma once
#include "../Uncopyable.h"
#include "../../lib/appEnv.hpp"
#include "../../lib/random.hpp"
#include <memory>

//========================================
//�V�[���N���X(���N���X)
//========================================

class CScene{
public:
	CScene(std::shared_ptr<AppEnv>app_env,std::shared_ptr<Random>random):
		m_app_env(app_env),
		m_random(random){}

	virtual ~CScene() = default;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//�@��ʂ̃T�C�Y
	static const int WIDTH = 1320;
	static const int HEIGHT = 720;
protected:
	std::shared_ptr<AppEnv>m_app_env;
	std::shared_ptr<Random>m_random;
};

//========================================
//�V�[���}�l�[�W���[�N���X
//========================================

class CSceneManager:private Uncopyable{

public:
	//�@�V�[���̎��
	enum class Scene{
		TITLE,
		STAGE,
		GAMECLEAR,
		RESLUT
	};

	//�@�C���X�^���X�̐���
	static CSceneManager *GetInstance(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random){
		static CSceneManager instance(app_env,random);
		return &instance;
	}
	~CSceneManager();
	void Update();										//�@�X�V
	void Draw();										//�@�`��
	static void SlectScene(Scene next_scene);			//�@�J�ڂ������V�[����n���֐�


private:
	//�@��Ԃ̎��
	enum class State{
		INIT,
		UPDATE
	};

	std::unique_ptr<CScene> m_scene;		//�@�V�[�������锠
	static Scene m_now_scene;				//�@���݂̃V�[��(�ÓI�ɂ��đ��ł��ς�����悤�ɂȂ��Ă��܂��Ă�)
	Scene m_old_scene;						//�@�J�ڂ���O�̃V�[��
	State m_state;							//�@���݂̏��

	std::shared_ptr<AppEnv>m_app_env;
	std::shared_ptr<Random>m_random;

	// �J�ڏ���
	void Transition();

	CSceneManager(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random);
};