#pragma once
#include "../lib/appEnv.hpp"
#include "../lib/random.hpp"
#include <memory>

//========================================
//�R�s�[�֎~�N���X
//========================================

class Uncopyable{
protected:
	Uncopyable() = default;
	//Uncopyable(std::shared_ptr<AppEnv>app_env, std::shared_ptr<Random>random){}
	~Uncopyable() = default;
private:
	Uncopyable(const Uncopyable &) = delete;
	Uncopyable &operator=(const Uncopyable &) = delete;
};