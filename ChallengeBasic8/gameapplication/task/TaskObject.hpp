#pragma once
#include "../object/Object.hpp"
#include "../../lib/appEnv.hpp"
#include <unordered_map>
#include <forward_list>
#include <functional>

class CTaskObject{
public:
	CTaskObject(std::shared_ptr<AppEnv>app_env);

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

	//�@�I�u�W�F�N�g�̒ǉ�
	void AddObject(Object::Type type);



private:
	std::forward_list<std::shared_ptr<Object>>m_object;						//�@�I�u�W�F�N�g
	std::unordered_map<Object::Type, std::function<void()>>m_create_list;	//�@��������I�u�W�F�N�g�X�C�b�`
	std::shared_ptr<AppEnv>m_app_env;										//�@�A�v���C�x���g
	
	//�@�폜
	void Remove();

	//�@����
	void CreatePlayer();
	void CreateEnemy();

};