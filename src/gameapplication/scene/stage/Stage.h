#pragma once
#include "../SceneManager.h"

//========================================
//�X�e�[�W�N���X
//========================================
class CStage : public CScene{
public:
	CStage(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random);
	~CStage();

	void Update();
	void Draw();
private:
	//�@�����蔻�菈��
	void Collision();
};

