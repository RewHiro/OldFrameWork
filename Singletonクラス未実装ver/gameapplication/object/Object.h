#pragma once
#include "../../lib/vector.hpp"
#include <vector>
#include <memory>
#include <list>

//========================================
//オブジェクトクラス(基底クラス)
//========================================

class Object{
public:
	Object() = default;
	virtual ~Object() = default;

	//　状態の種類
	enum class State{
		NONE,				// 存在しない
		LIVE,				//　生きてる
		INVINCIBLE,			//　無敵
		DEATH,				//　死亡
		EFFECT,				//　エフェクト処理
		MOVE				//　移動
	};
	//　更新
	virtual void Update() = 0;
	//　描画
	virtual void Draw() = 0;
	
	//　タスクの終了処理
	bool isRunOut(){
		if (m_state == State::NONE){
			return true;
		}
		else {
			return false;
		}
	}

	//　座標を取得
	Vec2f GetPos(){
		return m_pos;
	}

	//　半径を取得
	Vec2f GetR(){
		return m_r;
	}

	//　状態を取得
	State GetState(){
		return m_state;
	}

	//　当たりをセット
	void SetHit(bool hit){
		m_ishit = hit;
	}

protected:
	bool m_ishit = false;
	int m_alpha;
	int m_hp;
	float m_alphaf;

	Vec2f m_pos;
	Vec2f m_vec;
	Vec2f m_r;					//　半径
	State m_state;
};

typedef std::vector<std::unique_ptr<Object>> ArrayVec;
typedef std::vector<std::shared_ptr<Object>> ArrayList;