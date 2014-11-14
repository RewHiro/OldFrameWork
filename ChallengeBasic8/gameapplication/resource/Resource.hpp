#pragma once
#include "../Uncopyable.hpp"
#include "../../lib/texture.hpp"
#include <memory>

//========================================
//リソースクラス
//========================================
class CResource : private Uncopyable{
public:
	//　インスタンスの取得
	static CResource &GetInstance(){
		static CResource instance;
		return instance;
	}

	//　画像

	//　音楽
private:
	CResource();
};

