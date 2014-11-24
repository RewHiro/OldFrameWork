#pragma once
#include "../Uncopyable.h"
#include "../../lib/texture.hpp"
#include "../../lib/audio.hpp"
#include <memory>
#include <unordered_map>

//========================================
//���\�[�X�N���X
//========================================

class CResource : private Uncopyable{
public:
	//�@�C���X�^���X�̎擾
	static CResource& GetInstance(){
		static CResource instance;
		return instance;
	}

	enum class BG{
		TITLE,
		STAGE
	};

	enum class BGM{
		TITLE,
		STAGE
	};

	enum class SE{
	};

	//�@�w�i���擾
	Texture GetBG(const BG name)const{
		return m_bg.find(name)->second;
	}

	//�@BGM���擾
	std::shared_ptr<Media> GetBGM(const BGM name)const{
		return m_bgm.find(name)->second;
	}

private:
	CResource();
	std::unordered_map<BG, Texture>m_bg;								//�@�w�i
	std::unordered_map<BGM, std::shared_ptr<Media>>m_bgm;				//�@bgm

	//�@�w�i�̒ǉ�
	void RegistBG();

	//�@BGM�̒ǉ�
	void RegistBGM();
};

typedef CResource::BG BG;
typedef CResource::BGM BGM;