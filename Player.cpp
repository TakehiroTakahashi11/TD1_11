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
	l_stick_mag = { 0,0 };
	position = { Datas::PLAYER_POS_X, Datas::PLAYER_POS_Y };
	width = Datas::PLAYER_WIDTH;
	height = Datas::PLAYER_HEIGHT;
	speed = Datas::PLAYER_SPEED;
	dash_speed = Datas::PLAYER_DASH_SPEED;
	isDash = false;
	isGuard = false;
}

/// @brief �X�V����
void Player::Update() {
	if (!isDash && !isGuard) {
		Move();// �ړ�����
	}
	Dash();// �U������
	Guard();// �h�䏈��
}

/// @brief �`�揈��
void Player::Draw() {
	getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f}, width, height }, Datas::PLAYER_TEX);// �v���C���[�`��
}

void Player::Move()
{
	velocity = { 0.0f,0.0f };// ������

	if (IsCntMode()) {// �R���g���[���[
		Controller::GetLeftStick(0, l_stick_mag);// ���X�e�B�b�N�擾
		velocity = { static_cast<float>(l_stick_mag.x),static_cast<float>(l_stick_mag.y) };// vector2�ɃL���X�g
	}
	else {// �L�[�{�[�h
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

	// �v�Z
	velocity = velocity.Normalized() * speed;// ���K�����đ��x��������
	position += velocity * Delta::getTotalDelta();// ���ۂɉ��Z
}

void Player::Dash() {
	bool n = false;// �錾

	if (!isDash) {// �_�b�V�����łȂ��Ȃ���͂����
		if (IsCntMode()) {// �R���g���[���[
			if (Controller::IsTriggerButton(0, Controller::rSHOULDER)) {// RB���������Ȃ�
				n = true;// ���͂���
			}
		}
		else {// �L�[�{�[�h
			if (Key::IsTrigger(DIK_SPACE)) {// SPACE���������Ȃ�
				n = true;// ���͂���
			}
		}
	}

	//if (n) {// ���͂��������Ȃ�
	//	velocity = 
	//}
}

void Player::Guard() {
	isGuard = false;// ������

	if (!isDash) {// �_�b�V�����łȂ��Ȃ���͂����
		if (IsCntMode()) {// �R���g���[���[
			if (Controller::IsPressedButton(0, Controller::lSHOULDER)) {// Lb��������Ă���Ȃ�
				isGuard = true;// �K�[�h���ɂ���
			}
		}
		else {// �L�[�{�[�h
			if (Key::IsPressed(DIK_Z)) {// Z��������Ă���Ȃ�
				isGuard = true;// �K�[�h���ɂ���
			}
		}
	}


}