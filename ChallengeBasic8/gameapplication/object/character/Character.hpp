#pragma once
#include "../Object.hpp"
#include "../../resource/Resource.hpp"
#include "../../../lib/appEnv.hpp"

class CCharacter : public Object{
public:
	CCharacter():
		m_res(CResource::GetInstance()){}

protected:
	Vec2f m_hit_pos;													//@“–‚½‚è”»’è‚ÌˆÊ’u
	Vec2f m_hit_size;													//@“–‚½‚è”»’è‚Ì‘å‚«‚³
	CResource& m_res;

};

