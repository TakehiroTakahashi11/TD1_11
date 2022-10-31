#include "GameObject.h"
#include "Player.h"

/// @brief コンストラクタ
/// @param pGame ゲームのポインタ
Player::Player(Game& pGame) 
	: Obj(pGame)
{
	Init();
}

/// @brief 初期化処理
void Player::Init() {
	position = { 0.0f,0.0f };
	velocity = { 0.0f,0.0f };
}

/// @brief 更新処理
void Player::Update() {

}

/// @brief 描画処理
void Player::Draw() {

}