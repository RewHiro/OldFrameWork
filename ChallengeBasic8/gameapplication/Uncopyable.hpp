#pragma once

//========================================
//�R�s�[�֎~�N���X
//========================================

class Uncopyable{
public:
protected:
	Uncopyable() = default;
private:
	Uncopyable(const Uncopyable&) = delete;
	Uncopyable &operator=(const Uncopyable&) = delete;
};