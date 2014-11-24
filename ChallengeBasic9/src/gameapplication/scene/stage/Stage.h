#pragma once
#include "../Scene.h"
#include "../../resource/Resource.h"
#include "../../task/ObjectTask.h"

//========================================
//�X�e�[�W�N���X
//========================================
class CStage : public CScene{
public:
	CStage(std::shared_ptr<AppEnv>app_env);

	//�@�X�V
	Type Update();

	//�@�`��
	void Draw();
private:
	CObjectTask m_obj_task;
	CObjectInfoManager m_info;
};

