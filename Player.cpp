#include "GameObject.h"
#include "Player.h"
#include "Camera.h"
#include "Datas.h"
#include "ControllerInput.h"
#include "KeyMouseInput.h"
#include "Delta.h"
#include "Novice.h"
#include "Gauntlets.h"
#define _USE_MATH_DEFINES
#include <math.h>

/// @brief コンストラクタ
/// @param pGame ゲームのポインタ
Player::Player(Game& pGame) 
	: Obj(pGame)
{
	Init();
}

/// @brief 初期化処理
void Player::Init() {
	l_stick_mag = { 0,0 };
	position = { Datas::PLAYER_POS_X, Datas::PLAYER_POS_Y };
	velocity = { 0.0f,0.0f };
	direction = { 0.0f,0.0f };
	width = Datas::PLAYER_WIDTH;
	height = Datas::PLAYER_HEIGHT;
	speed = Datas::PLAYER_SPD;
	dash_length = 0.0f;
	dash_speed = Datas::PLAYER_DASH_SPD;
	isDash = false;
	isGuard = false;
	enum_direction = kUp;
	getGauntlets().Init();
}

/// @brief 更新処理
void Player::Update() {
	Dash();// 攻撃処理

	if (!isDash) {// ダッシュ中でないなら
		Guard();// 防御処理
	}
	if (!isDash) {// ダッシュ中、ガード中でないなら
		Move();// 移動処理
	}

	if (!isDash && (velocity.x != 0.0f || velocity.y != 0.0f)) {// ダッシュでなく、かつ方向が変わっていたら
		direction = velocity.Normalized();// 移動量から方向を保存
		enum_direction = DirectionConv();// enumに変換して保存
	}

	getGauntlets().Update();// ガントレットの更新処理

	if (Datas::DEBUG_MODE) {// デバッグ用文字列
		Novice::ScreenPrintf(0, 0, "isController:%d", IsCntMode());
		if (isDash) {
			Novice::ScreenPrintf(50, 0, "Dash");
		}
		if (isGuard) {
			Novice::ScreenPrintf(50, 0, "Guard");
		}
		Novice::ScreenPrintf(0, 40, "position:%.1f", position.x);
		Novice::ScreenPrintf(150, 40, "position:%.1f", position.y);
		Novice::ScreenPrintf(0, 60, "velocity:%.1f", velocity.x);
		Novice::ScreenPrintf(150, 60, "velocity:%.1f", velocity.y);
		Novice::ScreenPrintf(0, 80, "direction:%.1f", direction.x);
		Novice::ScreenPrintf(150, 80, "direction:%.1f", direction.y);
	}
}

/// @brief 描画処理
void Player::Draw() {
	if (!getGauntlets().GetIsBreak() && direction.x < 0) {// プレイヤーが左向きならば
		getGauntlets().Draw();// プレイヤーより後に描画

		if (Datas::DEBUG_MODE) {// デバッグ用文字列
			Novice::ScreenPrintf(0, 140, "gauntlet_wo_ushiro_ni_byouga");
		}
	}

	// プレイヤー描画
	switch (enum_direction)
	{
	case Player::kDown:
		getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_DOWN_TEX, move_anim / Datas::PLAYER_ANIM_SPD);
		break;
	case Player::kR:
		getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_RIGHT_TEX, move_anim / Datas::PLAYER_ANIM_SPD);
		break;
	case Player::kL:
		getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_LEFT_TEX, move_anim / Datas::PLAYER_ANIM_SPD);
		break;
	case Player::kDownR:
		getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_DOWN_RIGHT_TEX, move_anim / Datas::PLAYER_ANIM_SPD);
		break;
	case Player::kDownL:
		getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_DOWN_LEFT_TEX, move_anim / Datas::PLAYER_ANIM_SPD);
		break;
	case Player::kUpR:
		getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_UP_RIGHT_TEX, move_anim / Datas::PLAYER_ANIM_SPD);
		break;
	case Player::kUpL:
		getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_UP_LEFT_TEX, move_anim / Datas::PLAYER_ANIM_SPD);
		break;
	default:
	case Player::kUp:
		getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_UP_TEX,move_anim / Datas::PLAYER_ANIM_SPD);
		break;
	}

	if (!getGauntlets().GetIsBreak() && 0 <= direction.x) {// プレイヤーが右向きならば
		getGauntlets().Draw();// プレイヤーより前に描画

		if (Datas::DEBUG_MODE) {// デバッグ用文字列
			Novice::ScreenPrintf(0, 140, "gauntlet_wo_mae_ni_byouga");
		}
	}
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

	// アニメーション
	if (velocity.x != 0.0f || velocity.y != 0.0f) {
		move_anim += Delta::getTotalDelta();// 動いていたらアニメーション
	}
	else {
		move_anim = 0.0f;
	}

	if (3.0f * Datas::PLAYER_ANIM_SPD < move_anim) {// 最大コマ
		move_anim = 0.0f;
	}
}

void Player::Dash() {
	if (!isDash) {// ダッシュ中でないなら入力を取る
		if (IsCntMode()) {// コントローラー
			if (Controller::IsTriggerButton(0, Controller::rSHOULDER)) {// RBを押したなら
				isDash = true;// ダッシュ中に変更
				dash_length = 0.0f;// ダッシュした長さを初期化
				velocity = direction * dash_speed;// 方向にダッシュ速度をかける
			}
		}
		else {// キーボード
			if (Key::IsTrigger(DIK_SPACE)) {// SPACEを押したなら
				isDash = true;// ダッシュ中に変更
				dash_length = 0.0f;// ダッシュした長さを初期化
				velocity = direction * dash_speed;// 方向にダッシュ速度をかける
			}
		}
	}
	else {// ダッシュ中なら
		dash_length += Delta::getTotalDelta();// カウントフレーム加算

		if (Datas::PLAYER_DASH_START_RIGID + Datas::PLAYER_DASH_LEN + Datas::PLAYER_DASH_END_RIGID < dash_length) {// 最大距離までダッシュして、硬直も終わったら
			isDash = false;// ダッシュオフ
		}
		else if (Datas::PLAYER_DASH_LEN < dash_length) {// 最大距離までダッシュしたら
			// 硬直
			// 何かしらのなにか、アニメーションだの
		}
		else if(Datas::Datas::PLAYER_DASH_START_RIGID < dash_length) {// 最初の硬直が終わってたら
			position += velocity * Delta::getTotalDelta();// 実際に加算して移動
		}
		else {
			// 硬直
			// 何かしらのなにか、アニメーションだの
		}
	}
}

void Player::Guard() {
	isGuard = false;// 初期化

	if (IsCntMode()) {// コントローラー
		if (Controller::IsPressedButton(0, Controller::lSHOULDER)) {// Lbが押されているなら
			isGuard = true;// ガード中にする
		}
	}
	else {// キーボード
		if (Key::IsPressed(DIK_Z)) {// Zが押されているなら
			isGuard = true;// ガード中にする
		}
	}
}

Player::DirectionEnum Player::DirectionConv()
{
	Vector2D vec[4];
	float rad;
	for (int i = 0; i < 4; i++) {
		rad = ((22.5 + i * 45) * M_PI) / 180;
		vec[i].x = cosf(rad);
		vec[i].y = sinf(rad);
	}
	float dot_result[8];
	for (int i = 0; i < 4; i++) {
		dot_result[i] = vec[i].Dot(direction);
		dot_result[i + 4] = -dot_result[i];
	}

	if (dot_result[0] > 0 && dot_result[3] >= 0){
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(270, 80, "Up");
		}
		return DirectionEnum::kUp;
	}
	if (dot_result[1] > 0 && dot_result[4] >= 0) {
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(270, 80, "UpLeft");
		}
		return DirectionEnum::kUpL;
	}
	if (dot_result[2] > 0 && dot_result[5] >= 0) {
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(270, 80, "Left");
		}
		return DirectionEnum::kL;
	}
	if (dot_result[3] > 0 && dot_result[6] >= 0) {
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(270, 80, "DownLeft");
		}
		return DirectionEnum::kDownL;
	}
	if (dot_result[4] > 0 && dot_result[7] >= 0) {
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(270, 80, "Down");
		}
		return DirectionEnum::kDown;
	}
	if (dot_result[5] > 0 && dot_result[0] >= 0) {
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(270, 80, "DownRight");
		}
		return DirectionEnum::kDownR;
	}
	if (dot_result[6] > 0 && dot_result[1] >= 0) {
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(270, 80, "Right");
		}
		return DirectionEnum::kR;
	}
	if (dot_result[7] > 0 && dot_result[2] >= 0) {
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(270, 80, "UpRight");
		}
		return DirectionEnum::kUpR;
	}

	return DirectionEnum::kUp;
}
