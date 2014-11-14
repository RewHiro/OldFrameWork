#pragma once
#include "../Uncopyable.hpp"
#include "../utility/Font.hpp"
#include "../../lib/appEnv.hpp"
#include <memory>
#include <unordered_map>

class CScene;

//========================================
//シーンマネージャークラス
//========================================

class CSceneManager :private Uncopyable, public std::enable_shared_from_this<CSceneManager>{

public:
	CSceneManager(const std::shared_ptr<AppEnv>app_env);

	//　シーンの種類
	enum class Scene{
		TITLE,
		STAGE,
		RULE,
		RANKING,
		RESULT
	};

	void AddSceneList();								//　シーンリストの追加
	void Update();										//　更新
	void Draw();										//　描画
	void TransformOfScene(const Scene next_scene);		//　遷移したいシーンを渡す関数
	bool GetisFade();									//　フェードしているかどうかを取得

private:

	//　状態の種類
	enum class State{
		INIT,
		UPDATE
	};

	std::unique_ptr<CScene> m_scene;										//　シーンを入れる箱
	Scene m_now_scene;														//　現在のシーン
	Scene m_old_scene;														//　遷移する前のシーン
	State m_state;															//　現在の状態
	std::shared_ptr<AppEnv>m_app_env;										//　アプリイベント
	std::unordered_map<Scene, std::unique_ptr<CScene>>m_scene_list;			//　シーンリスト
	bool m_isFade;															//　フェードしてるか
	int m_alpha;															//　アルファ値

	// 遷移処理
	void Transition();

	//　シーンの更新
	void SceneUpdate();

	//　フェードイン
	void FadeIn();

	//　フェードアウト
	void FadeOut();
};