#pragma once

//========================================
//コピー禁止クラス
//========================================

class Uncopyable{
public:
protected:
	Uncopyable() = default;
private:
	Uncopyable(const Uncopyable&) = delete;
	Uncopyable &operator=(const Uncopyable&) = delete;
};