#include "GameObject.h"
#include "Player.h"

/// @brief �R���X�g���N�^
/// @param pGame �Q�[���̃|�C���^
Player::Player(Game& pGame) 
	: Obj(pGame)
{
	Init();
}

/// @brief ����������
void Player::Init() {
	position = { 0.0f,0.0f };
	velocity = { 0.0f,0.0f };
}

/// @brief �X�V����
void Player::Update() {

}

/// @brief �`�揈��
void Player::Draw() {

}