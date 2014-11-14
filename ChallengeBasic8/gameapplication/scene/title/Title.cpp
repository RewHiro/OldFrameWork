#include "Title.hpp"
#include "../SceneManager.hpp"
#include "../../../lib/graph.hpp"


CTitle::CTitle(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager) :
CScene(app_env,scene_manager),
m_res(CResource::GetInstance())
{

}

void CTitle::Start(){
}

//　更新
void CTitle::Update(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_scene_manager.lock()->TransformOfScene(CSceneManager::Scene::STAGE);
	}
}

//　描画
void CTitle::Draw(){
	drawFillBox(0, 0, 20, 20, Color(1, 1, 0));
}

