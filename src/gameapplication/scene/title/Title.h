#pragma once
#include "../SceneManager.h"

//========================================
//�^�C�g���N���X
//========================================
class CTitle : public CScene{
public:
	CTitle(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random);
	~CTitle();

	void Update();
	void Draw();
};

