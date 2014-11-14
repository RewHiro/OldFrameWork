#pragma once
#include "../Uncopyable.hpp"
#include "../utility/Font.hpp"
#include "../../lib/appEnv.hpp"
#include <memory>
#include <unordered_map>

class CScene;

//========================================
//�V�[���}�l�[�W���[�N���X
//========================================

class CSceneManager :private Uncopyable, public std::enable_shared_from_this<CSceneManager>{

public:
	CSceneManager(const std::shared_ptr<AppEnv>app_env);

	//�@�V�[���̎��
	enum class Scene{
		TITLE,
		STAGE,
		RULE,
		RANKING,
		RESULT
	};

	void AddSceneList();								//�@�V�[�����X�g�̒ǉ�
	void Update();										//�@�X�V
	void Draw();										//�@�`��
	void TransformOfScene(const Scene next_scene);		//�@�J�ڂ������V�[����n���֐�
	bool GetisFade();									//�@�t�F�[�h���Ă��邩�ǂ������擾

private:

	//�@��Ԃ̎��
	enum class State{
		INIT,
		UPDATE
	};

	std::unique_ptr<CScene> m_scene;										//�@�V�[�������锠
	Scene m_now_scene;														//�@���݂̃V�[��
	Scene m_old_scene;														//�@�J�ڂ���O�̃V�[��
	State m_state;															//�@���݂̏��
	std::shared_ptr<AppEnv>m_app_env;										//�@�A�v���C�x���g
	std::unordered_map<Scene, std::unique_ptr<CScene>>m_scene_list;			//�@�V�[�����X�g
	bool m_isFade;															//�@�t�F�[�h���Ă邩
	int m_alpha;															//�@�A���t�@�l

	// �J�ڏ���
	void Transition();

	//�@�V�[���̍X�V
	void SceneUpdate();

	//�@�t�F�[�h�C��
	void FadeIn();

	//�@�t�F�[�h�A�E�g
	void FadeOut();
};