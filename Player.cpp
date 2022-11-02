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

/// @brief �X�V����
void Player::Update() {
	Dash();// �U������
	Guard();// �h�䏈��
	if (!isDash && !isGuard) {
		Move();// �ړ�����
	}

	if (!isDash && (velocity.x != 0.0f || velocity.y != 0.0f)) {// �_�b�V���łȂ��A�ړ����Ă�����
		direciton = velocity.Normalized();// �ړ��ʂ��������ۑ�
	}

	if (Datas::DEBUG_MODE) {// �f�o�b�O�p������
		Novice::ScreenPrintf(0, 0, "isController:%d", IsCntMode());
		Novice::ScreenPrintf(0, 40, "position:%.1f", position.x);
		Novice::ScreenPrintf(100, 40, "position:%.1f", position.y);
		Novice::ScreenPrintf(0, 70, "velocity:%.1f", velocity.x);
		Novice::ScreenPrintf(100, 70, "velocity:%.1f", velocity.y);
		Novice::ScreenPrintf(0, 100, "direction:%.1f", direciton.x);
		Novice::ScreenPrintf(100, 100, "direction:%.1f", direciton.y);
	}
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

	// �v�Z
	velocity = velocity.Normalized() * speed;// ���K�����đ��x��������
	position += velocity * Delta::getTotalDelta();// ���ۂɉ��Z
}

void Player::Dash() {
	if (!isDash) {// �_�b�V�����łȂ��Ȃ���͂����
		if (IsCntMode()) {// �R���g���[���[
			if (Controller::IsTriggerButton(0, Controller::rSHOULDER)) {// RB���������Ȃ�
				isDash = true;// �_�b�V�����ɕύX
				dash_length = 0.0f;// �_�b�V������������������
				velocity = direciton * dash_speed;// �����Ƀ_�b�V�����x��������
			}
		}
		else {// �L�[�{�[�h
			if (Key::IsTrigger(DIK_SPACE)) {// SPACE���������Ȃ�
				isDash = true;// �_�b�V�����ɕύX
				dash_length = 0.0f;// �_�b�V������������������
				velocity = direciton * dash_speed;// �����Ƀ_�b�V�����x��������
			}
		}
	}
	else {// �_�b�V�����Ȃ�
		dash_length += Delta::getTotalDelta();// �J�E���g�t���[�����Z

		if (Datas::PLAYER_DASH_START_RIGID + Datas::PLAYER_DASH_LEN + Datas::PLAYER_DASH_END_RIGID < dash_length) {// �ő勗���܂Ń_�b�V�����āA�d�����I�������
			isDash = false;// �_�b�V���I�t
		}
		else if (Datas::PLAYER_DASH_LEN < dash_length) {// �ő勗���܂Ń_�b�V��������
			// �d��
			// ��������̂Ȃɂ��A�A�j���[�V��������
		}
		else if(Datas::Datas::PLAYER_DASH_START_RIGID < dash_length) {// �ŏ��̍d�����I����Ă���
			position += velocity * Delta::getTotalDelta();// ���ۂɉ��Z���Ĉړ�
		}
		else {
			// �d��
			// ��������̂Ȃɂ��A�A�j���[�V��������
		}
	}
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