#pragma once
#include "Obj.h"

class Boss : public Obj
{
public:
	/// @brief コンストラクタ
	/// @param pGame ゲームのポインタ
	Boss(class Game& pGame);

	/// @brief 初期化処理
	void Init() override;

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;

	/// @brief 衝突判定
	void Collision();

	/// @brief プレイヤーとボスの判定
	void PtoBCollision();

private:
	// ノックバック
	void KnockBack();

	// アニメーション
	void Animation();

	// アクション
	void Action();

	// 待機アクション
	void Action1();

private:
	// ノックバック
	bool isKnockBack;
	Vector2D knockBackVel;

	// 浮いているか
	bool isFloating;

	// アニメーション
	float anim;
};