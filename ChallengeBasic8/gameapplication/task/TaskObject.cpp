#include "TaskObject.hpp"
#include "../object/character/player/Player.hpp"
#include "../object/character/enemy/Enemy.hpp"

CTaskObject::CTaskObject(std::shared_ptr<AppEnv>app_env):
m_app_env(app_env)
{
	m_create_list.emplace(Object::Type::PLAYER, std::bind(&CTaskObject::CreatePlayer, this));
	m_create_list.emplace(Object::Type::ENEMY, std::bind(&CTaskObject::CreateEnemy, this));
}

//　更新
void CTaskObject::Update(){
	for (auto& object : m_object){
		object->Update();
	}
	Remove();
}

//　描画
void CTaskObject::Draw(){
	for (auto& object : m_object){
		object->Draw();
	}
}

//　オブジェクトの追加
void CTaskObject::AddObject(Object::Type type){
	(m_create_list.find(type)->second)();
}

//　削除
void CTaskObject::Remove(){
	m_object.remove_if([](std::shared_ptr<Object>object){return object->isRemove(); });
}

//　プレイヤーの生成
void CTaskObject::CreatePlayer(){
	m_object.emplace_front(std::make_shared<CPlayer>(m_app_env));
}

//　エネミーの生成
void CTaskObject::CreateEnemy(){
	m_object.emplace_front(std::make_shared<CEnemy>());
}