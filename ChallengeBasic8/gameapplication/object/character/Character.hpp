#pragma once
#include "../Object.hpp"
#include "../../resource/Resource.hpp"
#include "../../../lib/appEnv.hpp"

class CCharacter : public Object{
public:
	CCharacter():
		m_res(CResource::GetInstance()){}

protected:
	Vec2f m_hit_pos;													//�@�����蔻��̈ʒu
	Vec2f m_hit_size;													//�@�����蔻��̑傫��
	CResource& m_res;

};

