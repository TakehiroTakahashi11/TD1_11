#pragma once
#include "BaseEffect.h"

class PreRush : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	PreRush(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~PreRush();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:

};
