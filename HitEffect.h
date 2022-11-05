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

	bool endCheck();

	/******** �G�t�F�N�g **********/
	//position ... x, y���W
	//size ... ��`�̃T�C�Y
	//velocity ... �������x
	//��]�p
	//elapseFrame ... ���ݎ���
	//isEnd ... �G�t�F�N�g���I�����Ă��邩
	struct HitStruct {
		Vector2D position = {0.0f,0.0f};
		Vector2D size = { 16.0f,16.0f };
		Vector2D velocity = { 0.0f,0.0f };
		float acceleration = 0.15f;
		float theta = 0.0f;
		float elapseFrame = 0.0f;
		bool isEnd = false;
	};

	HitStruct hitEffect[HitEffectMaxNum];
};