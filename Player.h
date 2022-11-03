#pragma once
#include "Obj.h"
#include "ControllerInput.h"
#include "Gauntlets.h"

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

public:// ゲッターセッター

	Vector2D GetPosition() { return position; }
	Vector2D GetVelocity() { return velocity; }
	Vector2D GetDirection() { return direction; }
	bool GetIsDash() { return isDash; }
	bool GetIsGuard() { return isGuard; }
	
	void SetDamage(float damage) { taken_damage = damage; }

private:
	// 入力
	Controller::StickMagnitude l_stick_mag;

	// 移動量
	Vector2D velocity;
	// 方向
	Vector2D direction;
	// 速度
	float speed;

	// 体力
	float health;
	// 現在受けたダメージ量
	float taken_damage;

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
};