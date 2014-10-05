#include "Stage.h"


CStage::CStage(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random) :
CScene(app_env,random){
}

CStage::~CStage(){
}

void CStage::Update(){
	// テスト
	if(m_app_env->isPushKey(GLFW_KEY_ENTER)){
		CSceneManager::SlectScene(CSceneManager::Scene::TITLE);
	}
}

void CStage::Draw(){
	//　テスト
	drawFillCircle(0, 0, 20, 20, 30, Color(1, 0, 0));
}

void CStage::Collision(){
}