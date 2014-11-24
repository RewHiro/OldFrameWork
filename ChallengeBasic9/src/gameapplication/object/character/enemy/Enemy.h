#pragma once
#include "../Character.h"
#include "../../info/ObjectInfoManager.h"
#include <unordered_map>
#include <string>

class CEnemy : public CCharacter{
public:
	CEnemy();

	enum class Type{
		SLIME,
		DRAGON
	};

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

protected:
	int m_count;
	CObjectInfoManager m_info;
	Color m_color;
};

