#include "GameObject.h"
#include "Player.h"
#include "Camera.h"
#include "KeyMouseInput.h"
#include "Delta.h"
#include <Novice.h>
#include "Gauntlets.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "Game.h"
#include "EffectManager.h"
#include "Map.h"

/// @brief コンストラクタ
/// @param pGame ゲームのポインタ
Player::Player(Game& pGame)
	: Obj(pGame)
{
	Init();
}

/// @brief 初期化処理
void Player::Init() {
	elapsedFrame = 0.0f;
	beforeElapsedFrame = 0.0f;

	width = Datas::PLAYER_WIDTH;
	height = Datas::PLAYER_HEIGHT;

	l_stick_mag = { 0,0 };
	r_stick_mag = { 0,0 };
	camera_pos = { 0.0f,0.0f };

	position = { Datas::PLAYER_POS_X, Datas::PLAYER_POS_Y };
	centerPosition = { Datas::PLAYER_POS_X + Datas::PLAYER_WIDTH * 0.5f, Datas::PLAYER_POS_Y + Datas::PLAYER_HEIGHT * 0.5f };
	JustDodgePosition[0] = { -50000.0f,-50000.0f };
	JustDodgePosition[1] = { -50000.0f,-50000.0f };
	JustDodgePosition[2] = { -50000.0f,-50000.0f };
	JustDodgePosition[3] = { -50000.0f,-50000.0f };
	JustDodgePosition[4] = { -50000.0f,-50000.0f };
	JustDodgePosition[5] = { -50000.0f,-50000.0f };
	JustDodgePosition[6] = { -50000.0f,-50000.0f };
	JustDodgePosition[7] = { -50000.0f,-50000.0f };
	JustDodgePosition[8] = { -50000.0f,-50000.0f };
	JustDodgePosition[9] = { -50000.0f,-50000.0f };
	JustDodgePosition[10] = { -50000.0f,-50000.0f };
	JustDodgePosition[11] = { -50000.0f,-50000.0f };
	JustDodgePosition[12] = { -50000.0f,-50000.0f };
	velocity = { 0.0f,0.0f };
	direction = { 0.0f,1.0f };
	speed = Datas::PLAYER_SPD;

	healthMax = Datas::PLAYER_MAX_HEALTH;
	health = Datas::PLAYER_MAX_HEALTH;
	taken_damage = 0.0f;

	staminaMax = Datas::PLAYER_MAX_STAMINA;
	stamina = Datas::PLAYER_MAX_STAMINA;
	guard_break = false;

	justDodge = false;

	charge = 0.0f;

	isInv = false;
	inv_count = 0.0f;

	knockBackVel = { 0.0f,0.0f };
	knockBackRigidCount = 0.0f;
	isKnockBack = false;

	dash_length = 0.0f;
	dash_speed = Datas::PLAYER_DASH_SPD;
	isDash = false;
	isDashAnim = false;

	isGuard = false;

	move_anim = 0.0f;

	getGauntlets().Init();
}

/// @brief 更新処理
void Player::Update() {// =====================================================================================
	elapsedFrame += Delta::getTotalDelta();
	if (beforeElapsedFrame + 0.5f < elapsedFrame) {
		beforeElapsedFrame = elapsedFrame;
	}

	// 基本処理
	if (!isKnockBack) {// ノックバックされていないなら
		Dash();// ダッシュ処理
		if (!isDash && !guard_break) {// ダッシュ中でないなら
			Guard();// ガード処理
		}
		if (!isDash) {// ダッシュ中、ガード中でないなら
			Move();// 移動処理
		}

		if (!isDash && (velocity.x != 0.0f || velocity.y != 0.0f)) {// ダッシュでなく、かつ方向が変わっていたら
			direction = velocity.Normalized();// 移動量から方向を保存
		}
	}

	// スタミナリジェネ
	if (!isDash && !isGuard) {
		stamina += Datas::PLAYER_STAMINA_REGEN;
	}
	if (Datas::PLAYER_MAX_STAMINA < stamina) {
		stamina = Datas::PLAYER_MAX_STAMINA;
	}
	if (stamina < 0.0f) {
		stamina = 0.0f;
		guard_break = true;
		isGuard = false;
	}
	if (guard_break) {
		if (Datas::PLAYER_GUARD_COOLTIME < stamina) {
			guard_break = false;
		}
	}

	// 仰け反り処理
	if (isKnockBack) {
		KnockBack();
	}

	// 無敵処理
	if (isInv) {
		inv_count += Delta::getTotalDelta();

		if (static_cast<int>(inv_count) % Datas::PLAYER_INV_ANIM_SPD == 0) {
			inv_count += 1.0f;
			isDrawn = !isDrawn;
		}

		if (Datas::PLAYER_MAX_INV < inv_count) {
			inv_count = 0.0f;
			isInv = false;
			isDrawn = true;
		}
	}

	// 中心座標割り出し
	centerPosition = { position.x - Datas::PLAYER_WIDTH * 0.5f, position.y - Datas::PLAYER_HEIGHT * 0.5f };

	// 壁判定
	WallCollision();

	// カメラ追尾
	MoveCamera();
	getCameraMain().setPosition(centerPosition + camera_pos);

	// =====================================================================================
	// ガントレットの更新処理
	getGauntlets().Update();

	// =====================================================================================
	// デバッグ用文字列
	if (Datas::DEBUG_MODE) {
		Novice::ScreenPrintf(0, 100, "health:%.1f/max:%.1f", health, healthMax);
		Novice::ScreenPrintf(0, 140, "stamina:%.1f/max:%.1f", stamina, staminaMax);

		if (isInv) {
			Novice::ScreenPrintf(350, 0, "invincible");
		}
		if (isDash) {
			Novice::ScreenPrintf(350, 0, "Dash");
		}
		if (isGuard) {
			Novice::ScreenPrintf(350, 0, "Guard");
		}
		Novice::ScreenPrintf(0, 40, "PLAYER_POS_X:%.1f", position.x);
		Novice::ScreenPrintf(200, 40, "PLAYER_POS_Y:%.1f", position.y);

		Novice::ScreenPrintf(500, 540, "JUST:%d", justDodge);
	}
	// =====================================================================================
}

/// @brief 描画処理
void Player::Draw() {
	// =====================================================================================
	// プレイヤー描画
	if (isDrawn) {
		Quad temp = My::RotateCenter(position, atan2f(direction.y, direction.x), width, height);// 回転
		getCameraMain().DrawQuad(temp, Datas::PLAYER_TEX, static_cast<int>(move_anim / Datas::PLAYER_ANIM_SPD));// 実際に描画
	}

	// =====================================================================================
	// ガントレット描画
	getGauntlets().Draw();
}

void Player::Move()
{
	if (IsCntMode()) {// コントローラー
		Controller::GetLeftStick(0, l_stick_mag);// 左スティック取得
		velocity = { static_cast<float>(l_stick_mag.x),static_cast<float>(l_stick_mag.y) };// vector2にキャスト
	}
	else {// キーボード
		velocity = { 0.0f,0.0f };// 初期化
		if (Key::IsPressed(DIK_W) || Key::IsPressed(DIK_UP)) {
			velocity.y += 1.0f;
		}
		if (Key::IsPressed(DIK_S) || Key::IsPressed(DIK_DOWN)) {
			velocity.y -= 1.0f;
		}
		if (Key::IsPressed(DIK_D) || Key::IsPressed(DIK_RIGHT)) {
			velocity.x += 1.0f;
		}
		if (Key::IsPressed(DIK_A) || Key::IsPressed(DIK_LEFT)) {
			velocity.x -= 1.0f;
		}
	}

	// 計算
	velocity = velocity.Normalized() * speed;// 正規化して速度をかける
	if (!isGuard) {// ガード中でないなら
		position += velocity * Delta::getTotalDelta();// 実際に加算、移動
	}

	// =====================================================================================
	// アニメーション
	if ((velocity.x != 0.0f || velocity.y != 0.0f) && !isGuard) {
		move_anim += Delta::getTotalDelta();// 動いていたらアニメーション
	}
	else {
		move_anim = 0.0f;
	}

	if (Datas::PLAYER_ANIM_MAX * Datas::PLAYER_ANIM_SPD < move_anim) {// 最大コマ
		move_anim = 0.0f;
	}
}

void Player::Dash() {
	if (!isDash) {// ダッシュ中でないなら入力を取る
		JustDodgePosition[0] = { -50000.0f,-50000.0f };
		JustDodgePosition[1] = { -50000.0f,-50000.0f };
		JustDodgePosition[2] = { -50000.0f,-50000.0f };
		JustDodgePosition[3] = { -50000.0f,-50000.0f };
		JustDodgePosition[4] = { -50000.0f,-50000.0f };
		JustDodgePosition[5] = { -50000.0f,-50000.0f };
		JustDodgePosition[6] = { -50000.0f,-50000.0f };
		JustDodgePosition[7] = { -50000.0f,-50000.0f };
		JustDodgePosition[8] = { -50000.0f,-50000.0f };
		JustDodgePosition[9] = { -50000.0f,-50000.0f };
		JustDodgePosition[10] = { -50000.0f,-50000.0f };
		JustDodgePosition[11] = { -50000.0f,-50000.0f };
		JustDodgePosition[12] = { -50000.0f,-50000.0f };
		if (IsCntMode()) {// コントローラー
			if (Controller::IsTriggerButton(0, Controller::rSHOULDER)) {// RBを押したなら
				isDash = true;// ダッシュ中に変更
				dash_length = 0.0f;// ダッシュした長さを初期化
				JustDodgePosition[0] = centerPosition;
				velocity = direction * dash_speed;// 方向にダッシュ速度をかける
			}
		}
		else {// キーボード
			if (Key::IsTrigger(DIK_SPACE)) {// SPACEを押したなら
				isDash = true;// ダッシュ中に変更
				dash_length = 0.0f;// ダッシュした長さを初期化
				JustDodgePosition[0] = centerPosition;
				velocity = direction * dash_speed;// 方向にダッシュ速度をかける
			}
		}
	}
	else {// ダッシュ中なら
		isGuard = false;// ガードを無効に

		dash_length += Delta::getTotalDelta();// カウントフレーム加算

		if (Datas::PLAYER_DASH_LEN  < dash_length) {// 最大距離までダッシュしたら
			isDash = false;// ダッシュオフ
			JustDodgePosition[0] = { -50000.0f,-50000.0f };
			JustDodgePosition[1] = { -50000.0f,-50000.0f };
			JustDodgePosition[2] = { -50000.0f,-50000.0f };
			JustDodgePosition[3] = { -50000.0f,-50000.0f };
			JustDodgePosition[4] = { -50000.0f,-50000.0f };
			JustDodgePosition[5] = { -50000.0f,-50000.0f };
			JustDodgePosition[6] = { -50000.0f,-50000.0f };
			JustDodgePosition[7] = { -50000.0f,-50000.0f };
			JustDodgePosition[8] = { -50000.0f,-50000.0f };
			JustDodgePosition[9] = { -50000.0f,-50000.0f };
			JustDodgePosition[10] = { -50000.0f,-50000.0f };
			JustDodgePosition[11] = { -50000.0f,-50000.0f };
			JustDodgePosition[12] = { -50000.0f,-50000.0f };
			if (justDodge) {
				CheckJust();
			}
		}
		else if (dash_length < Datas::PLAYER_DASH_LEN) {
			position += velocity * Delta::getTotalDelta();// 実際に加算して移動
			if (beforeElapsedFrame == elapsedFrame) {
				EffectManager::MakeNewEffect(centerPosition, kPlayerBoost);
				if (justDodge) {
					EffectManager::MakeNewEffect(position, kPlayerDash);
				}
				if (JustDodgePosition[1].x == -50000.0f) {
					JustDodgePosition[1] = centerPosition;
				}
				else if (JustDodgePosition[2].x == -50000.0f) {
					JustDodgePosition[2] = centerPosition;
				}
				else if (JustDodgePosition[3].x == -50000.0f) {
					JustDodgePosition[3] = centerPosition;
				}
				else if (JustDodgePosition[4].x == -50000.0f) {
					JustDodgePosition[4] = centerPosition;
				}
				else if (JustDodgePosition[5].x == -50000.0f) {
					JustDodgePosition[5] = centerPosition;
				}
				else if (JustDodgePosition[6].x == -50000.0f) {
					JustDodgePosition[6] = centerPosition;
				}
				else if (JustDodgePosition[7].x == -50000.0f) {
					JustDodgePosition[7] = centerPosition;
				}
				else if (JustDodgePosition[8].x == -50000.0f) {
					JustDodgePosition[8] = centerPosition;
				}
				else if (JustDodgePosition[9].x == -50000.0f) {
					JustDodgePosition[9] = centerPosition;
				}
				else if (JustDodgePosition[10].x == -50000.0f) {
					JustDodgePosition[10] = centerPosition;
				}
				else if (JustDodgePosition[11].x == -50000.0f) {
					JustDodgePosition[11] = centerPosition;
				}
				else if (JustDodgePosition[12].x == -50000.0f) {
					JustDodgePosition[12] = centerPosition;
				}
			}
		}
	}
}

void Player::Guard() {
	isGuard = false;// 初期化

	if (IsCntMode()) {// コントローラー
		if (Controller::IsPressedButton(0, Controller::lSHOULDER)) {// Lbが押されているなら
			isGuard = true;// ガード中にする
			stamina -= Datas::PLAYER_GUARD_STAMINA;
		}
	}
	else {// キーボード
		if (Key::IsPressed(DIK_Z)) {// Zが押されているなら
			isGuard = true;// ガード中にする
			stamina -= Datas::PLAYER_GUARD_STAMINA;
		}
	}
}

void Player::ChargeAttack()
{
	if (IsCntMode()) {// コントローラー
		if (Controller::IsPressedButton(0, Controller::bB)) {// Lbが押されているなら

		}
	}
	else {// キーボード
		if (Key::IsPressed(DIK_X)) {// Zが押されているなら

		}
	}
}

void Player::MoveCamera()
{
	Vector2D r_stk = { 0.0f,0.0f };
	if (IsCntMode()) {// コントローラーなら
		Controller::GetRightStick(0, r_stick_mag);// 左スティック取得
		r_stk = { static_cast<float>(r_stick_mag.x),static_cast<float>(r_stick_mag.y) };// vector2にキャスト
		camera_pos += r_stk * 0.0001f * Datas::PLAYER_CAMARA_SPD;// カメラ移動
	}
	if (r_stk.x == 0.0f && r_stk.y == 0.0f) {// 入力がないなら
		camera_pos -= camera_pos.Normalized() * Datas::PLAYER_CAMARA_SPD;// 真ん中に戻す
		if (camera_pos.Length() <= Datas::PLAYER_CAMARA_SPD + 0.1f) {// 最小値クランプ
			camera_pos.setZero();
		}
	}
	if (Datas::PLAYER_CAMARA_OFFSET < camera_pos.Length()) {// 最大値クランプ
		camera_pos = camera_pos.Normalized() * Datas::PLAYER_CAMARA_OFFSET;
	}
}

void Player::KnockBack()
{
	if (knockBackVel.x != 0.0f || knockBackVel.y != 0.0f) {
		knockBackVel -= knockBackVel.Normalized() * Datas::PLAYER_KNOCKBACK_DIS * Delta::getTotalDelta();
		if (knockBackVel.Length() < Datas::PLAYER_KNOCKBACK_DIS + 0.1f) {
			knockBackVel.setZero();
		}
		position += knockBackVel * Delta::getTotalDelta();
	}
	else if(0.0f < knockBackRigidCount) {
		knockBackRigidCount -= Delta::getTotalDelta();
	}
	else {
		isKnockBack = false;
	}
}

void Player::WallCollision()
{
	switch (getGame().getMap().GetMapNum())
	{
	case 0:
		if (centerPosition.x - Datas::PLAYER_WIDTH * 0.5f < -Datas::STAGE0_WIDTH) {// もし壁より外なら
			centerPosition.x = Datas::PLAYER_WIDTH * 0.5f - Datas::STAGE0_WIDTH;
			position.x = centerPosition.x + Datas::PLAYER_WIDTH * 0.5f;
		}
		if (Datas::STAGE0_WIDTH < centerPosition.x + Datas::PLAYER_WIDTH * 0.5f) {
			centerPosition.x = Datas::STAGE0_WIDTH - Datas::PLAYER_WIDTH * 0.5f;
			position.x = centerPosition.x + Datas::PLAYER_WIDTH * 0.5f;
		}
		if (centerPosition.y - Datas::PLAYER_HEIGHT * 0.5f < -Datas::STAGE0_HEIGHT) {
			centerPosition.y = Datas::PLAYER_HEIGHT * 0.5f - Datas::STAGE0_HEIGHT;
			position.y = centerPosition.y + Datas::PLAYER_HEIGHT * 0.5f;
		}
		if (Datas::STAGE0_HEIGHT < centerPosition.y + Datas::PLAYER_HEIGHT * 0.5f) {
			centerPosition.y = Datas::STAGE0_HEIGHT - Datas::PLAYER_HEIGHT * 0.5f;
			position.y = centerPosition.y + Datas::PLAYER_HEIGHT * 0.5f;
		}
		break;
	case 1:
		if (centerPosition.x - Datas::PLAYER_WIDTH * 0.5f < -Datas::STAGE1_WIDTH) {// もし壁より外なら
			centerPosition.x = Datas::PLAYER_WIDTH * 0.5f - Datas::STAGE1_WIDTH;
			position.x = centerPosition.x + Datas::PLAYER_WIDTH * 0.5f;
		}
		if (Datas::STAGE1_WIDTH < centerPosition.x + Datas::PLAYER_WIDTH * 0.5f) {
			centerPosition.x = Datas::STAGE1_WIDTH - Datas::PLAYER_WIDTH * 0.5f;
			position.x = centerPosition.x + Datas::PLAYER_WIDTH * 0.5f;
		}
		if (centerPosition.y - Datas::PLAYER_HEIGHT * 0.5f < -Datas::STAGE1_HEIGHT) {
			centerPosition.y = Datas::PLAYER_HEIGHT * 0.5f - Datas::STAGE1_HEIGHT;
			position.y = centerPosition.y + Datas::PLAYER_HEIGHT * 0.5f;
		}
		if (Datas::STAGE1_HEIGHT < centerPosition.y + Datas::PLAYER_HEIGHT * 0.5f) {
			centerPosition.y = Datas::STAGE1_HEIGHT - Datas::PLAYER_HEIGHT * 0.5f;
			position.y = centerPosition.y + Datas::PLAYER_HEIGHT * 0.5f;
		}
		break;
	default:
		break;
	}
}

void Player::CheckJust()
{
	charge += Datas::PLAYER_JUSTDODGE_CHARGE;
	justDodge = false;
}

float Player::GetIsDir()
{
	return static_cast<float>(atan2f(direction.y, direction.x) - 90 * M_PI / 180);
}
