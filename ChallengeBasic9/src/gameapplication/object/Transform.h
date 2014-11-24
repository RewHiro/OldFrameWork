#pragma once
#include "../../lib/vector.hpp"

class CTransform{
public:
	CTransform() = default;
	CTransform(Vec2f pos, Vec2f rotate, Vec2f scale) :
		m_pos(pos),
		m_rotate(rotate),
		m_scale(scale){}

	//�@�ʒu���擾
	Vec2f GetPos()const{ return m_pos; }

	//�@X�̍��W���擾
	float GetPosX()const{ return m_pos.x(); }

	//�@Y�̍��W���擾
	float GetPosY()const{ return m_pos.y(); }

	//�@��]�����擾
	Vec2f GetRotate()const{ return m_rotate; }

	//�@�傫�����擾
	Vec2f GetScale()const{ return m_scale; }

	//�@�������擾
	float GetScaleX()const{ return m_scale.x(); }

	//�@�c�����擾
	float GetScaleY()const{ return m_scale.y(); }

	//�@�ʒu��ݒ�
	void Position(const Vec2f& value){
	m_pos = value;
	}
	void Position(const float x,const float y){
		m_pos.x() = x;
		m_pos.y() = y;
	}

	//�@�ړ�
	void Translate(const Vec2f& value){
		m_pos += value;
	}
	//�@�ړ�
	void Translate(const float x,const float y){
		m_pos.x() += x;
		m_pos.y() += y;
	}

	//�@��]����ݒ�
	void Rotation(const Vec2f& value){
		m_rotate = value;
	}
	//�@��]����ݒ�
	void Rotation(const float x,const float y){
		m_rotate.x() = x;
		m_rotate.y() = y;
	}

	//�@��]
	void Rotate(const Vec2f& value){
		m_rotate += value;
	}
	//�@��]
	void Rotate(const float x,const float y){
		m_rotate.x() += x;
		m_rotate.y() += y;
	}

	//�@�傫����ݒ�
	void Scaling(const Vec2f& value){
		m_scale = value;
	}
	//�@�傫����ݒ�
	void Scaling(const float x,const float y){
		m_scale.x() = x;
		m_scale.y() = y;
	}

	//�@�T�C�Y�ύX
	void Scale(const Vec2f& value){
		m_scale += value;
	}
	//�@�T�C�Y�ύX
	void Scale(const float x,const float y){
		m_scale.x() += x;
		m_scale.y() += y;
	}

private:
	Vec2f m_pos;				//�@�ʒu
	Vec2f m_rotate;				//�@��]��
	Vec2f m_scale;				//�@�傫��
};