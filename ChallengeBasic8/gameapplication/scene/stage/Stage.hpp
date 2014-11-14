#pragma once
#include "../Scene.hpp"
#include "../../resource/Resource.hpp"

class CTaskObject;

//========================================
//�X�e�[�W�N���X
//========================================
class CStage : public CScene{
public:
	CStage(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager);

	//�@�ŏ��̏���
	void Start();

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();
private:

	CResource &m_res;										//�@���\�[�X
	std::unique_ptr<CTaskObject>m_task_object;
};

