#pragma once
#include "Obj.h"
#include "ControllerInput.h"
#include "Gauntlets.h"
#include "Datas.h"
#include "Delta.h"

class Gauntlets;

class Player : public Obj
{
public:
	/// @brief コンストラクタ
	/// @param pGame ゲームのポインタ
	Player(class Game& pGame);

	/// @brief 初期化処理
	void Init() override;

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;

	enum DashLevel {
		Dash1,
		Dash2,
		Dash3
	};

	enum PLAYER_DIRECTION_STATE {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		RIGHTUP,
		LEFTUP,
		RIGHTDOWN,
		LEFTDOWN
	};

private:
	/// @brief 移動処理
	void Move();

	/// @brief 攻撃処理
	void Dash();

	/// @brief 防御処理
	void Guard();

	/// @brief チャージ攻撃
	void ChargeAttack();

	/// @brief カメラ処理
	void MoveCamera();

	/// @brief ノックバック処理
	void KnockBack();

	/// @brief 壁判定
	void WallCollision();

	/// @brief ジャスト回避
	void CheckJust();


public:// ゲッターセッター

	Vector2D GetPosition() { return position; }
	Vector2D GetJustDodgePosition(int n) { Vector2D p = { 0.0f,Datas::PLAYER_WIDTH * 0.3f }; return JustDodgePosition[n] - p; }
	Vector2D GetVelocity() { return velocity; }
	Vector2D GetDirection() { return direction; }
	bool GetIsDash() { return isDash; }
	bool GetIsGuard() { return isGuard; }
	bool GetIsGuardBreak() { return guard_break; }
	bool GetIsChargeAttack() { return isChargeAttack; }
	bool GetIsInvincible() { return isInv; }
	bool GetIsDrawn() { return isDrawn; }
	float GetIsDir();
	float GetHealth() { return health; }
	float GetStamina() { return stamina; }
	float GetCharge() { return charge; }
	float GetDashAnim() { return dash_anim; }
	PLAYER_DIRECTION_STATE GetDirectionState() { return directionState; }
	bool GetisGameOver() { return isGameOver; }
	bool GetisGameClear() { return isGameClear; }

	void SetDamage(float damage);
	void SetIsJustDodge() { if (!justDodge) { Delta::HitStop(5.0f); } justDodge = true; }
	void AddCharge(float c) { charge += c; }
	void SetGuardDis(float damage) { stamina -= damage; Datas::GUARD_SOUND.PlayOnce(); }
	void SetKnockBack(Vector2D vel) { knockBackVel = vel; isKnockBack = true; knockBackRigidCount = Datas::PLAYER_KNOCKBACK_RIGID; }
	void SetMove();
	void SetisGameOver();
	void SetisGameClear();

private:
	bool isGameOver;
	bool isGameOverProc;
	float gameOverFrame;

	bool isGameClear;
	bool isGameClearProc;
	float gameClearFrame;

	// 経過
	float elapsedFrame;
	float beforeElapsedFrame;

	// 入力
	Controller::StickMagnitude l_stick_mag;
	Controller::StickMagnitude r_stick_mag;
	// カメラ位置
	Vector2D camera_pos;

	Vector2D beforePosition;
	// ジャスト回避判定位置
	Vector2D JustDodgePosition[13];
	// 移動量
	Vector2D velocity;
	// 方向
	Vector2D direction;
	// 速度
	float speed;
	// アニメーション
	float anim;

	// 最大体力
	float healthMax;
	// 体力
	float health;
	// 現在受けたダメージ量
	float taken_damage;

	// スタミナ最大値
	float staminaMax;
	// スタミナ
	float stamina;
	// ガードブレイク
	bool guard_break;

	// ジャスト回避したか
	bool justDodge;

	// チャージアタック中か
	bool isChargeAttack;
	// 溜め
	float charge;

	// 無敵状態か
	bool isInv;
	// 無敵状態のカウンター
	float inv_count;
	// 描画するか
	bool isDrawn;

	// ノックバック移動量
	Vector2D knockBackVel;
	// ノックバック硬直カウント
	float knockBackRigidCount;
	// ノックバックされているか
	bool isKnockBack;

	// ダッシュの長さ
	float dash_length;
	// ダッシュ速度
	float dash_speed;
	// ダッシュ中か
	bool isDash;

	// ガード中か
	bool isGuard;

	// アニメーション
	float move_anim;
	float dash_anim;
	float justDodge_anim;

	//方向ステイト
	PLAYER_DIRECTION_STATE directionState;

};