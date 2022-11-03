#pragma once
#include "BaseEffect.h"

#define HitEffectMaxNum 30

class HitEffect : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	HitEffect(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~HitEffect();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	/******** �G�t�F�N�g **********/
	//position ... x, y���W
	//size ... ��`�̃T�C�Y
	//velocity ... �������x
	//��]�p
	//elapseFrame ... ���ݎ���
	//isEnd ... �G�t�F�N�g���I�����Ă��邩
	struct HitStruct {
		Vector2D position;
		Vector2D size;
		Vector2D velocity;
		float acceleration;
		float theta;
		float elapseFrame;
		bool isEnd;
	};

	HitStruct hitEffect[HitEffectMaxNum];
};