#pragma once
#include "../Uncopyable.hpp"
#include "../../lib/vector.hpp"
#include <vector>
#include <memory>
#include <list>

//========================================
//オブジェクトクラス(基底クラス)
//========================================

class Object : private Uncopyable{
public:
	Object() = default;
	virtual ~Object() = default;

	//　更新
	virtual void Update() = 0;
	//　描画
	virtual void Draw() = 0;
	
	//　削除するか
	bool isRemove(){
		if (!m_is_active){
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

	//　座標を取得
	Vec2f GetSize(){
		return m_size;
	}

	enum class Type{
		PLAYER,
		ENEMY
	};

protected:
	int m_alpha;											//　アルファ値(int)
	float m_alphaf;											//　アルファ値(float)
	Vec2f m_pos;											//　位置
	Vec2f m_size;											//　大きさ
	Vec2f m_vec;											//　ベクトル
	bool m_is_active = true;								//	アクティブな状態か
};

typedef std::vector<std::unique_ptr<Object>> ArrayVec;
typedef std::vector<std::shared_ptr<Object>> ArrayList;