#pragma once
#include "resource\Resource.h"
#include "scene\SceneManager.h"
#include "Uncopyable.h"
#include "../lib\appEnv.hpp"
#include "../lib\random.hpp"
#include <memory>

//========================================
//ゲームアプリケーションクラス
//========================================
class CGameApplication:Uncopyable{
public:
	~CGameApplication() = default;

	static CGameApplication *GetInstance(){
		static CGameApplication instance;
		return &instance;
	}

	std::shared_ptr<AppEnv>m_app_env;

	//　更新
	void Update();
private:
	CGameApplication();
	std::shared_ptr<Random>m_random;
	CSceneManager *m_scene_manager;
	//　リソースの読み込み
	CResource m_rec;
};

