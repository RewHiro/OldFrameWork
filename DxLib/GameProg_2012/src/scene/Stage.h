#pragma once
#include "SceneManager.h"

//=====================================
//ステージクラス
//=====================================

class CStage : public CScene{
public:
	CStage();
	~CStage();

	//　更新
	void Update();

	//　描画
	void Draw();
};

