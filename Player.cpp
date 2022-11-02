#include "GameObject.h"
#include "Player.h"
#include "Camera.h"
#include "Datas.h"
#include "ControllerInput.h"
#include "KeyMouseInput.h"
#include "Delta.h"
#include "Novice.h"

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
	direciton = { 0.0f,0.0f };
	width = Datas::PLAYER_WIDTH;
	height = Datas::PLAYER_HEIGHT;
	speed = Datas::PLAYER_SPD;
	dash_length = 0.0f;
	dash_speed = Datas::PLAYER_DASH_SPD;
	isDash = false;
	isGuard = false;
}

/// @brief 更新処理
void Player::Update() {
	Dash();// 攻撃処理

	if (!isDash) {// ダッシュ中でないなら
		Guard();// 防御処理
	}
	if (!isDash && !isGuard) {// ダッシュ中、ガード中でないなら
		Move();// 移動処理
	}

	if (!isDash && (velocity.x != 0.0f || velocity.y != 0.0f)) {// ダッシュでなく、移動していたら
		direciton = velocity.Normalized();// 移動量から方向を保存
	}

	if (Datas::DEBUG_MODE) {// デバッグ用文字列
		Novice::ScreenPrintf(0, 0, "isController:%d", IsCntMode());
		Novice::ScreenPrintf(0, 40, "position:%.1f", position.x);
		Novice::ScreenPrintf(150, 40, "position:%.1f", position.y);
		Novice::ScreenPrintf(0, 70, "velocity:%.1f", velocity.x);
		Novice::ScreenPrintf(150, 70, "velocity:%.1f", velocity.y);
		Novice::ScreenPrintf(0, 100, "direction:%.1f", direciton.x);
		Novice::ScreenPrintf(150, 100, "direction:%.1f", direciton.y);
	}
}

/// @brief 描画処理
void Player::Draw() {
	getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_TEX);// プレイヤー描画
}

void Player::Move()
{
	velocity = { 0.0f,0.0f };// 初期化

	if (IsCntMode()) {// コントローラー
		Controller::GetLeftStick(0, l_stick_mag);// 左スティック取得
		velocity = { static_cast<float>(l_stick_mag.x),static_cast<float>(l_stick_mag.y) };// vector2にキャスト
	}
	else {// キーボード
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
	position += velocity * Delta::getTotalDelta();// 実際に加算
}

void Player::Dash() {
	if (!isDash) {// ダッシュ中でないなら入力を取る
		if (IsCntMode()) {// コントローラー
			if (Controller::IsTriggerButton(0, Controller::rSHOULDER)) {// RBを押したなら
				isDash = true;// ダッシュ中に変更
				dash_length = 0.0f;// ダッシュした長さを初期化
				velocity = direciton * dash_speed;// 方向にダッシュ速度をかける
			}
		}
		else {// キーボード
			if (Key::IsTrigger(DIK_SPACE)) {// SPACEを押したなら
				isDash = true;// ダッシュ中に変更
				dash_length = 0.0f;// ダッシュした長さを初期化
				velocity = direciton * dash_speed;// 方向にダッシュ速度をかける
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