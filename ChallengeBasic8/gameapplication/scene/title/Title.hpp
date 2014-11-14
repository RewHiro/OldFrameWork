#pragma once
#include "../Scene.hpp"
#include "../../resource/Resource.hpp"
#include <memory>

class CSceneManager;

//========================================
//タイトルクラス
//========================================
class CTitle : public CScene{
public:
	CTitle(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager);

	//　最初の処理
	void Start();

	//　更新
	void Update();

	//　描画
	void Draw();

private:

	CResource &m_res;														//　リソース
	
};

