#pragma once
#include "../SceneManager.h"

//========================================
//ステージクラス
//========================================
class CStage : public CScene{
public:
	CStage(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random);
	~CStage();

	void Update();
	void Draw();
private:
	//　当たり判定処理
	void Collision();
};

