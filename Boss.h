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
		kAttack1,
		kThunder1,

		None
	};

	// アクションセット
	void SetNextAction(BossAction bossaction);

	// アクション
	void Action();

	// 待機アクション
	void Move();
	void MoveMig();

	// 攻撃1
	void Attack1();
	void Attack1Mig();

	// 攻撃1
	void Thunder1();
	void Thunder1Mig();

	// アニメーション
	void Animation();

private:
	// ノックバック
	bool isKnockBack;
	Vector2D knockBackVel;

	// 経過時間
	float elapsedTime;
	// 最後にノックバックした時間
	float lastKnockBackTime;
	// 最後にアクションした時間
	float lastActionTime;

	// アクション状態
	BossAction nowAction;
	// 予約アクション
	BossAction nextAction;
	// 移行できるか
	bool canMigration;

	// Move
	Vector2D beforePos;
	float moveTheta;

	// Attack1
	float attack1Elapsed;
	float attack1bullet1Time;
	float attack1bullet2Time;
	float attack1bullet3Time;
	float attack1bullet4Time;
	float attack1bullet5Time;
	float attack1bullet6Time;
	float attack1bullet7Time;
	float attack1bullet8Time;
	float attack1bullet9Time;
	float attack1bullet10Time;

	// Thunder1
	float thunder1Elapsed;
	Vector2D thunder1pos;
	Vector2D thunder2pos;
	Vector2D thunder3pos;
	int prethunder1_num;
	int prethunder2_num;
	int prethunder3_num;
	bool thunder1_created;
	bool thunder2_created;
	bool thunder3_created;

	// 浮いているか
	bool isFloating;

	// アニメーション
	float anim;
};