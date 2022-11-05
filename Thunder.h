#pragma once
#include "BaseEffect.h"

class Thunder : public BaseEffect
{
public:
	/// @brief コンストラクタ
	Thunder(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~Thunder();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Vector2D col_pos;
};
