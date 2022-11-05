#pragma once
#include "BaseEffect.h"

class PreThunder : public BaseEffect
{
public:
	/// @brief コンストラクタ
	PreThunder(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~PreThunder();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	float elapsedSub;
};
