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

	/******** エフェクト **********/
	//position ... x, y座標
	//size ... 矩形のサイズ
	//velocity ... 動く速度
	//回転角
	//elapseFrame ... 存在時間
	//isEnd ... エフェクトが終了しているか
	struct HitStruct {
		Vector2D position;
		Vector2D size;
		Vector2D velocity;
		float acceleration;
		float theta;
		float elapseFrame;
		bool isEnd;
	};

	HitStruct hitEffect[HitEffectMaxNum];
};