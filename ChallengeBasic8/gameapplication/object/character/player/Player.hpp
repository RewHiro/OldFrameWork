#pragma once
#include "../Character.hpp"

class CPlayer : public CCharacter
{
public:
	CPlayer(std::shared_ptr<AppEnv>app_env);

	//　更新
	void Update();

	//　描画
	void Draw();


private:
	std::shared_ptr<AppEnv>m_app_env;									//　アプリイベントを入れる箱
};

