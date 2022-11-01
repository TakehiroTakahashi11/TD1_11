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
	width = Datas::PLAYER_WIDTH;
	height = Datas::PLAYER_HEIGHT;
	speed = Datas::PLAYER_SPEED;
	dash_speed = Datas::PLAYER_DASH_SPEED;
	isDash = false;
	isGuard = false;
}

/// @brief 更新処理
void Player::Update() {
	if (!isDash && !isGuard) {
		Move();// 移動処理
	}
	Dash();// 攻撃処理
	Guard();// 防御処理
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

	if (IsDebug()) {
		Novice::ScreenPrintf(0, 0, "CntMode:%d", IsCntMode());
	}

	// 計算
	velocity = velocity.Normalized() * speed;// 正規化して速度をかける
	position += velocity * Delta::getTotalDelta();// 実際に加算
}

void Player::Dash() {
	bool n = false;// 宣言

	if (!isDash) {// ダッシュ中でないなら入力を取る
		if (IsCntMode()) {// コントローラー
			if (Controller::IsTriggerButton(0, Controller::rSHOULDER)) {// RBを押したなら
				n = true;// 入力あり
			}
		}
		else {// キーボード
			if (Key::IsTrigger(DIK_SPACE)) {// SPACEを押したなら
				n = true;// 入力あり
			}
		}
	}

	//if (n) {// 入力があったなら
	//	velocity = 
	//}
}

void Player::Guard() {
	isGuard = false;// 初期化

	if (!isDash) {// ダッシュ中でないなら入力を取る
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


}