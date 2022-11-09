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

	Vector2D GetPosition() { return position; };
	float GetHealth() { return health; };

private:
	// ノックバック
	void KnockBack();

	// タイムライン
	void TimeLine();

	// 移行減算
	void Migration();

	// アクションenum
	enum BossAction
	{
		kMove1,
		kAttack1,
		kAttack1_1,
		kAttack1_2,
		kThunder1,
		kThunder1_1,

		None
	};

	// アクションセット
	void SetNextAction(BossAction bossaction);

	// アクション
	void Action();

	// 待機アクション
	void Move1();

	// 攻撃1
	void Attack1();
	// 攻撃1_1
	void Attack1_1();
	// 攻撃1_2
	void Attack1_2();


	// 攻撃1
	void Thunder1();
	// 攻撃1_1
	void Thunder1_1();

	// アニメーション
	void Animation();

private:
	// ホームポジション
	Vector2D homePos;
	// 体力
	float health;

	// ノックバック
	bool isKnockBack;
	Vector2D knockBackVel;

	// 経過時間
	float elapsedTime;
	// 最後にアクションした時間
	float lastActionTime;

	// 移行できるか
	bool canMigration;
	// 移行できるまでの時間
	float migrationTime;

	// Move1
	float moveTheta;

	// Attack1
	bool attack1Flag;
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

	// Attack1_1
	bool attack1_1Flag;

	// Attack1_2
	bool attack1_2Flag;

	// Thunder1
	bool thunder1Flag;
	int thunder1num;

	// Thunder1_1
	bool thunder1_1Flag;

	// 浮いているか
	bool isFloating;

	// アニメーション
	float anim;
};