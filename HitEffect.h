#pragma once
#include "BaseEffect.h"

#define HitEffectMaxNum 30

class HitEffect : public BaseEffect
{
public:
	/// @brief コンストラクタ
	HitEffect(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~HitEffect();

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
	struct HitStruct {
		Vector2D position = {0.0f,0.0f};
		Vector2D size = { 16.0f,16.0f };
		Vector2D velocity = { 0.0f,0.0f };
		float acceleration = 0.15f;
		float theta = 0.0f;
		float elapseFrame = 0.0f;
		bool isEnd = false;
	};

	HitStruct hitEffect[HitEffectMaxNum];
};