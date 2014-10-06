#include "SceneManager.h"
#include "title\Title.h"
#include "stage\Stage.h"

CSceneManager::Scene CSceneManager::m_now_scene = CSceneManager::Scene::TITLE;

CSceneManager::CSceneManager(std::shared_ptr<AppEnv>app_env,std::shared_ptr<Random>random):
m_state(State::INIT),
m_scene(nullptr),
m_app_env(app_env),
m_random(random)
{
}

CSceneManager::~CSceneManager(){
}

//　遷移処理
void CSceneManager::Transition(){
	m_scene.reset();
	switch (m_now_scene){
	case Scene::TITLE:
		m_scene = std::make_unique<CTitle>(m_app_env,m_random);
		break;
	case Scene::STAGE:
		m_scene = std::make_unique<CStage>(m_app_env, m_random);
		break;
	case Scene::GAMECLEAR:
		break;
	case Scene::RESLUT:
		break;
	}

	m_old_scene = m_now_scene;
	m_state = State::UPDATE;
}

//　更新
void CSceneManager::Update(){
	switch (m_state){
	case State::INIT:
		Transition();
		break;

	case State::UPDATE:
		m_scene->Update();
		if (m_now_scene != m_old_scene){
			m_state = State::INIT;
		}
		break;
	}
}

//　描画
void CSceneManager::Draw(){
	// 描画準備
	m_app_env->setupDraw();
	
	if (m_state == State::UPDATE){
		m_scene->Draw();
	}

	// 画面更新
	m_app_env->update();
}

//　遷移したいシーンを渡す関数
void CSceneManager::SlectScene(Scene next_scene){
	m_now_scene = next_scene;
}