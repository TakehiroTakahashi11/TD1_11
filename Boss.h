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

	// アクションenum
	enum BossAction
	{
		kMove,

		None
	};

	// アクション
	void Action();

	// 待機アクション
	void Move();

	// アニメーション
	void Animation();

private:
	// ノックバック
	bool isKnockBack;
	Vector2D knockBackVel;

	// アクション状態
	BossAction nowAction;
	// 予約アクション
	BossAction nextAction;

	// アクション1用回転角
	Vector2D beforePos;
	float moveTheta;

	// 浮いているか
	bool isFloating;

	// アニメーション
	float anim;
};