#include "Stage.h"
#include "SceneManager.h"
#include "../../DxLib/DxLib.h"

CStage::CStage(){
}


CStage::~CStage(){
}

//　更新
void CStage::Update(){
}

//　描画
void CStage::Draw(){
	DrawCircle(CSceneManager::WIDTH / 2, CSceneManager::HEIGHT / 2, 10, GetColor(255, 0, 0), true);
}