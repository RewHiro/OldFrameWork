#include "Enemy.hpp"


CEnemy::CEnemy():
m_count(0)
{
}

//　更新
void CEnemy::Update(){
	if (!m_is_active)return;
	m_count++;
	if (m_count == 180){
		m_is_active = false;
	}
}

//　描画
void CEnemy::Draw(){
	if (!m_is_active)return;
	drawCircle(100, 0, 60, 60, 20, 5, Color(1, 1, 0));
}