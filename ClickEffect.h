#pragma once
#include "BaseEffect.h"

#define ClickEffectMaxNum 200

class ClickEffect : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	ClickEffect(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~ClickEffect();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	struct ClickStruct {
		Vector2D pos;
		Vector2D velocity;
	};

	ClickStruct Effect[ClickEffectMaxNum];
};