#include "Stage.hpp"
#include "../SceneManager.hpp"
#include "../../task/TaskObject.hpp"

CStage::CStage(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager) :
CScene(app_env, scene_manager),
m_res(CResource::GetInstance()),
m_task_object(std::make_unique<CTaskObject>(app_env))
{

	m_task_object->AddObject(Object::Type::PLAYER);
	m_task_object->AddObject(Object::Type::ENEMY);
}

//　最初の処理
void CStage::Start(){
}

//　更新
void CStage::Update(){
	if (m_app_env->isPushKey(GLFW_KEY_ENTER)){
		m_scene_manager.lock()->TransformOfScene(CSceneManager::Scene::TITLE);
	}
	m_task_object->Update();
}

//　描画
void CStage::Draw(){
	drawFillCircle(0, 0, 20, 20, 30, Color(1, 0, 0));
	m_task_object->Draw();
}
