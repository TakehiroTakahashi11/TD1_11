#pragma once
#include "BaseEffect.h"

#define BulletDeathMaxNum 5

class BulletDeath : public BaseEffect
{
public:
	/// @brief コンストラクタ
	BulletDeath(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~BulletDeath();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	bool endCheck();

	/******** エフェクト **********/
	//position ... x, y座標
	//startPosition ... 初期座標
	//endPosition ... 終端座標
	//size ... 矩形のサイズ
	//startSize ... 矩形の初期サイズ
	//velocity ... 動く速度
	//acceleration ... 加速度
	//theta ... 回転角
	//elapseFrame ... 存在時間
	//time ... 中心点に向かう時間
	//easeTime ... イージング用時間
	//currentAlpha ... 透明度
	//init ... 初期化
	//isEnd ... エフェクトが終了しているか
	struct BulletDeathStruct {
		Vector2D position;
		Vector2D startPosition;
		Vector2D endPosition;
		Vector2D size;
		Vector2D startSize;
		Vector2D velocity;
		float acceleration;
		float theta;
		float elapseFrame;
		float time;
		float easeTime;
		// unsigned int currentAlpha;

		bool isEnd;
	};

	BulletDeathStruct bulletDeath[BulletDeathMaxNum];
};