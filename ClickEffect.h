#pragma once
#include "BaseEffect.h"

#define ClickEffectMaxNum 200

class ClickEffect : public BaseEffect
{
public:
	/// @brief コンストラクタ
	ClickEffect(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~ClickEffect();

	// 継承

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