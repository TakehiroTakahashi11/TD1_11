#pragma once
#include "BaseEffect.h"

class PreThunder : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	PreThunder(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~PreThunder();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	float elapsedSub;
};
