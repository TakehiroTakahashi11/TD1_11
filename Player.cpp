#include "GameObject.h"
#include "Player.h"
#include "Camera.h"
#include "Datas.h"
#include "ControllerInput.h"
#include "KeyMouseInput.h"
#include "Delta.h"
#include "Novice.h"

/// @brief �R���X�g���N�^
/// @param pGame �Q�[���̃|�C���^
Player::Player(Game& pGame) 
	: Obj(pGame)
{
	Init();
}

/// @brief ����������
void Player::Init() {
	position = { Datas::SCREEN_HALF_WIDTH - width * 0.5f, height * 0.5f };
}

/// @brief �X�V����
void Player::Update() {
	
}

/// @brief �`�揈��
void Player::Draw() {
	getCameraMain().DrawQuad({ {position}, width, height }, Datas::BackGroundTex);// �v���C���[�`��
}

void Player::Move()
{
}
