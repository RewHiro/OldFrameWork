#pragma once
#include "../Uncopyable.h"
#include "../../lib/appEnv.hpp"
#include "../../lib/random.hpp"
#include <memory>

//========================================
//シーンクラス(基底クラス)
//========================================

class CScene{
public:
	CScene(std::shared_ptr<AppEnv>app_env,std::shared_ptr<Random>random):
		m_app_env(app_env),
		m_random(random){}

	virtual ~CScene() = default;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	//　画面のサイズ
	static const int WIDTH = 1320;
	static const int HEIGHT = 720;
protected:
	std::shared_ptr<AppEnv>m_app_env;
	std::shared_ptr<Random>m_random;
};

//========================================
//シーンマネージャークラス
//========================================

class CSceneManager:private Uncopyable{

public:
	//　シーンの種類
	enum class Scene{
		TITLE,
		STAGE,
		GAMECLEAR,
		RESLUT
	};

	//　インスタンスの生成
	static CSceneManager *GetInstance(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random){
		static CSceneManager instance(app_env,random);
		return &instance;
	}
	~CSceneManager();
	void Update();										//　更新
	void Draw();										//　描画
	static void SlectScene(Scene next_scene);			//　遷移したいシーンを渡す関数


private:
	//　状態の種類
	enum class State{
		INIT,
		UPDATE
	};

	std::unique_ptr<CScene> m_scene;		//　シーンを入れる箱
	static Scene m_now_scene;				//　現在のシーン(静的にして他でも変えられるようになってしまってる)
	Scene m_old_scene;						//　遷移する前のシーン
	State m_state;							//　現在の状態

	std::shared_ptr<AppEnv>m_app_env;
	std::shared_ptr<Random>m_random;

	// 遷移処理
	void Transition();

	CSceneManager(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random);
};