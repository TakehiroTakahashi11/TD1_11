#pragma once
#include "Obj.h"
#include "ControllerInput.h"
#include "Gauntlets.h"
#include "Datas.h"

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

private:
	/// @brief 移動処理
	void Move();

	/// @brief 攻撃処理
	void Dash();

	/// @brief 防御処理
	void Guard();

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
	Vector2D GetCenterPosition() { return centerPosition; }
	Vector2D GetJustDodgePosition1() { return JustDodgePosition1; }
	Vector2D GetJustDodgePosition2() { return JustDodgePosition2; }
	Vector2D GetJustDodgePosition3() { return JustDodgePosition3; }
	Vector2D GetJustDodgePosition4() { return JustDodgePosition4; }
	Vector2D GetJustDodgePosition5() { return JustDodgePosition5; }
	Vector2D GetJustDodgePosition6() { return JustDodgePosition6; }
	Vector2D GetVelocity() { return velocity; }
	Vector2D GetDirection() { return direction; }
	bool GetIsDash() { return isDash; }
	bool GetIsGuard() { return isGuard; }
	bool GetIsInvincible() { return isInv; }
	bool GetIsDrawn() { return isDrawn; }
	float GetIsDir();

	void SetDamage(float damage) { health -= damage; taken_damage += damage; isInv = true; }
	void SetIsJustDodge() { justDodge = true; }
	void SetGuardDis(float damage) { stamina -= damage * 3.0f; }
	void SetKnockBack(Vector2D vel) { knockBackVel = vel; isKnockBack = true; knockBackRigidCount = Datas::PLAYER_KNOCKBACK_RIGID; }
	void SetMove() { isDash = false; isGuard = false; }

private:
	// 入力
	Controller::StickMagnitude l_stick_mag;
	Controller::StickMagnitude r_stick_mag;
	// カメラ位置
	Vector2D camera_pos;

	// 中心位置
	Vector2D centerPosition;
	// ジャスト回避判定位置
	Vector2D JustDodgePosition1;
	Vector2D JustDodgePosition2;
	Vector2D JustDodgePosition3;
	Vector2D JustDodgePosition4;
	Vector2D JustDodgePosition5;
	Vector2D JustDodgePosition6;
	// 移動量
	Vector2D velocity;
	// 方向
	Vector2D direction;
	// 速度
	float speed;

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
	// ダッシュアニメーションフラグ
	bool isDashAnim;

	// ガード中か
	bool isGuard;

	// アニメーション
	float move_anim;
};