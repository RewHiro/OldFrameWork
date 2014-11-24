#pragma once
#include "Scene.h"
#include <unordered_map>

//========================================
//�V�[���t�@�N�g���[�N���X
//========================================

class CSceneFactory{
public:
	CSceneFactory(std::shared_ptr<AppEnv>app_env);

	//�@�V�[�����擾
	std::unique_ptr<CScene> GetScene(const CScene::Type type)const{
		return std::move((m_scene_create_list.find(type)->second)());
	};

private:
	std::unordered_map < CScene::Type, std::function < std::unique_ptr<CScene> () >> m_scene_create_list;			//�@�V�[���������X�g
};