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
	position = { Datas::SCREEN_HALF_WIDTH - width * 0.5f, height * 0.5f };
}

/// @brief 更新処理
void Player::Update() {
	
}

/// @brief 描画処理
void Player::Draw() {
	getCameraMain().DrawQuad({ {position}, width, height }, Datas::BackGroundTex);// プレイヤー描画
}

void Player::Move()
{
}
