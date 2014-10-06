#pragma once
#include "../SceneManager.h"

//========================================
//タイトルクラス
//========================================
class CTitle : public CScene{
public:
	CTitle(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random);
	~CTitle();

	void Update();
	void Draw();
};

