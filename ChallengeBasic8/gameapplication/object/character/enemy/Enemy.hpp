#pragma once
#include "../Character.hpp"
class CEnemy : public CCharacter{
public:
	CEnemy();

	//　更新
	void Update();

	//　描画
	void Draw();

private:
	int m_count;
};

