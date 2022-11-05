#pragma once
#include "BaseEffect.h"

#define AttackEffectMaxNum 30

class AttackEffect : public BaseEffect
{
public:
	/// @brief コンストラクタ
	AttackEffect(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~AttackEffect();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	bool endCheck();

	/******** エフェクト **********/
	//position ... x, y座標
	//size ... 矩形のサイズ
	//velocity ... 動く速度
	//回転角
	//elapseFrame ... 存在時間
	//isEnd ... エフェクトが終了しているか
	struct AttackStruct {
		Vector2D position = {0.0f,0.0f};
		Vector2D size = { 16.0f,16.0f };
		Vector2D velocity = { 0.0f,0.0f };
		float acceleration = 0.15f;
		float theta = 0.0f;
		float elapseFrame = 0.0f;
		bool isEnd = false;
	};

	AttackStruct attackEffect[AttackEffectMaxNum];
};