#pragma once
#include "../Uncopyable.hpp"
#include "../../lib/texture.hpp"
#include <memory>

//========================================
//���\�[�X�N���X
//========================================
class CResource : private Uncopyable{
public:
	//�@�C���X�^���X�̎擾
	static CResource &GetInstance(){
		static CResource instance;
		return instance;
	}

	//�@�摜

	//�@���y
private:
	CResource();
};

