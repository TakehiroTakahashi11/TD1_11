#pragma once
#include "BaseEffect.h"

class PreRush : public BaseEffect
{
public:
	/// @brief コンストラクタ
	PreRush(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~PreRush();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:

};
