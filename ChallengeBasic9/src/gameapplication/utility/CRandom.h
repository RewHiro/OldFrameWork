#pragma once
#include <random>
#include <vector>

//=====================================
//�����_���N���X
//=====================================

class CRandom{
public:

	CRandom();

	static CRandom& GetInstance(){
		static CRandom instance;
		return instance;
	}

	//�@�V�[�h�̐ݒ�
	void SetSeed(const unsigned long seed);

	//�@��l���z�̃����_��(����)
	double Uniform(const double min, const double max);

	//�@��l���z�̃����_��(����)
	float Uniform(const float min, const float max);

	//�@��l���z�̃����_��(����)
	int Uniform(const int min, const int max);

	//�@�x���k�[�C���z(�w�肵���m����true���o���A0.00~1.00)
	bool Bernulli(const float probability);

	//�@���K���z
	//�@exexpectation�F���Ғl
	//�@error�F�W���΍�(�덷)
	double Gaussian(const double expectation, const double error);

	int Gaussian(const int expectation, const int error);

	//�@�I����
	int Select(const std::vector<int> &select);


private:
	std::mt19937 engine;
};