#pragma once
#include "BaseEffect.h"

class PrePreRush : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	PrePreRush(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~PrePreRush();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:

};
