#include "GameApplication.h"
#include <ctime>

CGameApplication::CGameApplication() :
m_app_env(std::make_shared<AppEnv>(CScene::WIDTH, CScene::HEIGHT, false, true)),
m_random(std::make_shared<Random>()),
m_scene_manager(CSceneManager::GetInstance(m_app_env,m_random))
{
	//　シードの設定
	m_random->setSeed(u_int(time(nullptr)));
}

void CGameApplication::Update(){
	m_scene_manager->Update();
	m_scene_manager->Draw();
}