#pragma once
#include "resource\Resource.hpp"
#include "scene\SceneManager.hpp"
#include "Uncopyable.hpp"

//========================================
//ゲームアプリケーションクラス
//========================================

class CGameApplication : private Uncopyable{
public:

	//　インスタンスの取得
	static CGameApplication& GetInstance(){
		static CGameApplication instance;
		return instance;
	}

	std::shared_ptr<AppEnv>m_app_env;								//　アプリイベント

	//　更新
	void Update();

private:
	CGameApplication();
	std::shared_ptr<CSceneManager>m_scene_manager;					//　シーンマネージャー
	CResource& m_res;												//　リソース
};

