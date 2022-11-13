#pragma once
#include "BaseEffect.h"

class PrePreRush : public BaseEffect
{
public:
	/// @brief コンストラクタ
	PrePreRush(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~PrePreRush();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:

};
