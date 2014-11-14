#pragma once
#include "../Object.hpp"
#include "../../resource/Resource.hpp"
#include "../../../lib/appEnv.hpp"

class CCharacter : public Object{
public:
	CCharacter():
		m_res(CResource::GetInstance()){}

protected:
	Vec2f m_hit_pos;													//　当たり判定の位置
	Vec2f m_hit_size;													//　当たり判定の大きさ
	CResource& m_res;

};

