#pragma once
#include "../object/Object.hpp"
#include "../../lib/appEnv.hpp"
#include <unordered_map>
#include <forward_list>
#include <functional>

class CTaskObject{
public:
	CTaskObject(std::shared_ptr<AppEnv>app_env);

	//　更新
	void Update();

	//　描画
	void Draw();

	//　オブジェクトの追加
	void AddObject(Object::Type type);



private:
	std::forward_list<std::shared_ptr<Object>>m_object;						//　オブジェクト
	std::unordered_map<Object::Type, std::function<void()>>m_create_list;	//　生成するオブジェクトスイッチ
	std::shared_ptr<AppEnv>m_app_env;										//　アプリイベント
	
	//　削除
	void Remove();

	//　生成
	void CreatePlayer();
	void CreateEnemy();

};