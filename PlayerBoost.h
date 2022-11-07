#pragma once
#include "BaseEffect.h"

#define PlayerBoostMaxNum 3

class PlayerBoost : public BaseEffect
{
public:
	/// @brief コンストラクタ
	PlayerBoost(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~PlayerBoost();

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
	//acceleration ... 加速度
	//theta ... 回転角
	//elapseFrame ... 存在時間
	//time ... 中心点に向かう時間
	//easeTime ... イージング用時間
	//currentAlpha ... 透明度
	//init ... 初期化
	//isEnd ... エフェクトが終了しているか
	struct PlayerBoostStruct {
		Vector2D position;
		Vector2D startPosition;
		Vector2D size;
		Vector2D velocity;
		float acceleration;
		float theta;
		float elapseFrame;
		float time;
		float easeTime;
		unsigned int currentAlpha;

		bool init;
		bool isEnd;
	};

	PlayerBoostStruct boostEffect[PlayerBoostMaxNum];
};