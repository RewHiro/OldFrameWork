#pragma once
#include "../Scene.hpp"
#include "../../resource/Resource.hpp"

class CTaskObject;

//========================================
//ステージクラス
//========================================
class CStage : public CScene{
public:
	CStage(std::shared_ptr<AppEnv>app_env, std::shared_ptr<CSceneManager>scene_manager);

	//　最初の処理
	void Start();

	//　更新
	void Update();

	//　描画
	void Draw();
private:

	CResource &m_res;										//　リソース
	std::unique_ptr<CTaskObject>m_task_object;
};

