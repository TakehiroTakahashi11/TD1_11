#include "GameObject.h"
#include "Player.h"
#include "Camera.h"
#include "Datas.h"
#include "ControllerInput.h"
#include "KeyMouseInput.h"
#include "Delta.h"
#include "Novice.h"
#include "Gauntlets.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <cmath>

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

	// カメラ追尾
	 getCameraMain().setPosition(position);

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
	// プレイヤー描画
	Quad temp = My::RotateCenter(position, atan2f(direction.y, direction.x), width, height);// 回転
	getCameraMain().DrawQuad(temp, Datas::PLAYER_TEX, move_anim / Datas::PLAYER_ANIM_SPD);// 実際に描画

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

	// アニメーション
	if (velocity.x != 0.0f || velocity.y != 0.0f) {
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
	switch (My::VectorDirection8(direction))
	{
	default:
	case 0:
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(300, 80, "Up");
		}
		return DirectionEnum::kUp;
		break;
	case 1:
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(300, 80, "UpLeft");
		}
		return DirectionEnum::kUpL;
		break;
	case 2:
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(300, 80, "Left");
		}
		return DirectionEnum::kL;
		break;
	case 3:
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(300, 80, "DownLeft");
		}
		return DirectionEnum::kDownL;
		break;
	case 4:
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(300, 80, "Down");
		}
		return DirectionEnum::kDown;
		break;
	case 5:
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(300, 80, "DownRight");
		}
		return DirectionEnum::kDownR;
		break;
	case 6:
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(300, 80, "Right");
		}
		return DirectionEnum::kR;
		break;
	case 7:
		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(300, 80, "UpRight");
		}
		return DirectionEnum::kUpR;
		break;
	}

	return DirectionEnum::kUp;
}
