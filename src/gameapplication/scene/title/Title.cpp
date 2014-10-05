#include "Title.h"

CTitle::CTitle(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random):
CScene(app_env,random)
{
}


CTitle::~CTitle(){
}

void CTitle::Update(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		CSceneManager::SlectScene(CSceneManager::Scene::STAGE);
	}
}

void CTitle::Draw(){
	drawFillBox(0, 0, 20, 20, Color(1, 1, 0));
}