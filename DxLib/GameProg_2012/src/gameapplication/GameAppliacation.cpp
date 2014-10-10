#include "GameAppliacation.h"
#include "DxLib.h"

CGameAppliacation::CGameAppliacation():
m_scene_mgr(CSceneManager::GetInstacnce())
{
	DxLib_Init();   // DXライブラリ初期化処理
	WaitKey();      // キー入力待ち
}


CGameAppliacation::~CGameAppliacation(){
	DxLib_End();    // DXライブラリ終了処理
}

void CGameAppliacation::Update(){
	m_scene_mgr.Update();
	m_scene_mgr.Draw();
}