#include "GameAppliacation.h"
#include "DxLib.h"

CGameAppliacation::CGameAppliacation():
m_scene_mgr(CSceneManager::GetInstacnce())
{
	DxLib_Init();   // DX���C�u��������������
	WaitKey();      // �L�[���͑҂�
}


CGameAppliacation::~CGameAppliacation(){
	DxLib_End();    // DX���C�u�����I������
}

void CGameAppliacation::Update(){
	m_scene_mgr.Update();
	m_scene_mgr.Draw();
}