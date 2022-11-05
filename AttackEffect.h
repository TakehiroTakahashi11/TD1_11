#pragma once
#include "BaseEffect.h"

#define AttackEffectMaxNum 30

class AttackEffect : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	AttackEffect(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~AttackEffect();

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
	struct AttackStruct {
		Vector2D position = {0.0f,0.0f};
		Vector2D size = { 16.0f,16.0f };
		Vector2D velocity = { 0.0f,0.0f };
		float acceleration = 0.15f;
		float theta = 0.0f;
		float elapseFrame = 0.0f;
		bool isEnd = false;
	};

	AttackStruct attackEffect[AttackEffectMaxNum];
};