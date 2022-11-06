#pragma once
#include "BaseEffect.h"

class PlayerDashAnim : public BaseEffect
{
public:
	/// @brief コンストラクタ
	PlayerDashAnim(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~PlayerDashAnim();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	float theta;
	Vector2D pos;
};
