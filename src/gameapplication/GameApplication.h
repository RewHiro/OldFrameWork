#pragma once
#include "resource\Resource.h"
#include "scene\SceneManager.h"
#include "../lib\appEnv.hpp"
#include "../lib\random.hpp"
#include <memory>

//========================================
//ゲームアプリケーションクラス
//========================================
class CGameApplication{
public:
	CGameApplication();
	~CGameApplication() = default;

	std::shared_ptr<AppEnv>m_app_env;

	//　更新
	void Update();
private:
	std::shared_ptr<Random>m_random;
	std::unique_ptr<CSceneManager>m_scene_manager;
	//　リソースの読み込み
	CResource m_rec;
};

