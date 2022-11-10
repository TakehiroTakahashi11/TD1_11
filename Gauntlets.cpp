#include "Gauntlets.h"
#include "Game.h"
#include "Camera.h"
#include "Datas.h"
#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "MyFunc.h"
#include "Quad.h"
#include "Delta.h"
#include <Novice.h>

Gauntlets::Gauntlets(Game& game) : Obj(game)
{
	Init();
}

Gauntlets::~Gauntlets()
{
}

void Gauntlets::Init()
{
	position = { 0.0f,0.0f };

	guard_dir = 0.0f;
	dash_dis = 0.0f;
	dash_dir = 0.0f;

	x_anim = 0;

	chargeAttackFrame = 0.0f;
	chargeAttackSpeed = 0.0f;

	chargePos = { 0.0f,0.0f };
}

void Gauntlets::Update()
{
	Animation();
}

void Gauntlets::Draw()
{
	if (!getPlayer().GetIsGuardBreak()) {
		Vector2D dir = getPlayer().GetDirection();
		dir = dir.Rotated(-90 * M_PI / 180);
		Vector2D p_pos = getPlayer().GetPosition();
		Player::PLAYER_DIRECTION_STATE state = getPlayer().GetDirectionState();

		if (getPlayer().GetIsGuard()) {
			dir = dir.Rotated(90 * M_PI / 180);
			switch (state)
			{
			case Player::UP:
				state = Player::LEFT;
				break;
			case Player::DOWN:
				state = Player::RIGHT;
				break;
			case Player::LEFT:
				state = Player::DOWN;
				break;
			case Player::RIGHT:
				state = Player::UP;
				break;
			case Player::RIGHTUP:
				state = Player::LEFTUP;
				break;
			case Player::LEFTUP:
				state = Player::LEFTDOWN;
				break;
			case Player::RIGHTDOWN:
				state = Player::RIGHTUP;
				break;
			case Player::LEFTDOWN:
				state = Player::RIGHTDOWN;
				break;
			default:
				break;
			}
		}

		Vector2D g_pos = p_pos + dir * Datas::GAUNTLET_PLAYER_MOVE_DISTANCE;
		Quad temp = { {g_pos.x - Datas::GAUNTLET_WIDTH * 0.5f,g_pos.y - Datas::GAUNTLET_HEIGHT * 0.5f}, Datas::GAUNTLET_WIDTH , Datas::GAUNTLET_HEIGHT };

		if (getPlayer().GetIsDash()) {
			temp = temp.Translation(-g_pos).Rotation(90 * M_PI / 180).Translation(g_pos);
		}

		switch (state)
		{
		case Player::UP:
			getCameraMain().DrawQuad(temp, Datas::GAUNTLET_UP_TEX);
			break;
		case Player::DOWN:
			getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DOWN_TEX);
			break;
		case Player::LEFT:
			getCameraMain().DrawQuad(temp, Datas::GAUNTLET_LEFT_TEX);
			break;
		case Player::RIGHT:
			getCameraMain().DrawQuad(temp, Datas::GAUNTLET_RIGHT_TEX);
			break;
		case Player::RIGHTUP:
			getCameraMain().DrawQuad(temp, Datas::GAUNTLET_RIGHTUP_TEX);
			break;
		case Player::LEFTUP:
			getCameraMain().DrawQuad(temp, Datas::GAUNTLET_LEFTUP_TEX);
			break;
		case Player::RIGHTDOWN:
			getCameraMain().DrawQuad(temp, Datas::GAUNTLET_RIGHTDOWN_TEX);
			break;
		case Player::LEFTDOWN:
			getCameraMain().DrawQuad(temp, Datas::GAUNTLET_LEFTDOWN_TEX);
			break;
		default:
			break;
		}
	}
	else {
		// temp = My::RotateCenter(position, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x) + static_cast<float>(guard_dir * M_PI / 180), Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		// getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
		// ��ꂽ�K���g���b�g�`��
	}
}

bool Gauntlets::ChargeAttack()
{
	if (InitFlag) {
		chargePos = getPlayer().GetPosition();
		InitFlag = false;
		chargeAttackFrame = 0.0f;
		chargeAttackSpeed = 0.0f;
	}

	chargeAttackFrame += Delta::getDeltaTime();
	Vector2D dir = getPlayer().GetDirection();

	if (chargeAttackFrame < 50.0f) {
		Delta::MoveDynDelta(-0.15f);
		chargeAttackSpeed -= 0.3f * Delta::getTotalDelta();
	}
	else if (chargeAttackFrame < 60.0f) {
		Delta::SetDynDelta(1.0f);
		chargeAttackSpeed = 70.0f;
	}

	chargePos += dir * chargeAttackSpeed;

	if (60.0f < chargeAttackFrame) {// �I������
		chargeAttackFrame = 0.0f;
		InitFlag = true;
		return true;
	}
	return false;
}

void Gauntlets::Animation()
{
	Vector2D pos = getPlayer().GetPosition();// �v���C���[���W�擾
	Vector2D dir = getPlayer().GetDirection();

	if (getPlayer().GetIsGuard()) {// �K�[�h���Ȃ�
		// �K�[�h�A�j���[�V�����p
		if (guard_dir < 90.0f) {// �p�x��90��菬�����Ȃ��
			guard_dir += Datas::GAUNTLET_GUARD_DIR_SPD * Delta::getTotalDelta();// ��]
		}
		else {// �ȏ�Ȃ�
			guard_dir = 90.0f;// �Œ�
		}

		// �v�Z
		dir = dir.Rotated(static_cast<float>((guard_dir + 270) * M_PI / 180));
		pos += dir * Datas::GAUNTLET_PLAYER_GUARD_DISTANCE;
	}
	else if (getPlayer().GetIsDash()) {// �_�b�V�����Ȃ�
		// �_�b�V���A�j���[�V�����p
		if (dash_dis < 1.0f) {// �A�j���[�V�����������Ă��Ȃ��Ȃ�
			dash_dis += Datas::GAUNTLET_DASH_DIS_SPD * Delta::getTotalDelta();// ��]
		}
		else {// �ȏ�Ȃ�
			dash_dis = 1.0f;// �Œ�
		}
		if (dash_dir < 75.0f) {
			dash_dir = 75.0f;
		}
		if (dash_dir < 90.0f) {// �p�x��90��菬�����Ȃ��
			dash_dir += Datas::GAUNTLET_DASH_DIR_SPD * Delta::getTotalDelta();// ��]
		}
		else {// �ȏ�Ȃ�
			dash_dir = 90.0f;// �Œ�
		}

		// �v�Z
		dir = dir.Rotated(static_cast<float>((dash_dir + 270) * M_PI / 180));
		pos += dir * (Datas::GAUNTLET_PLAYER_DASH_DISTANCE * dash_dis);
	}
	else {// ���[�u���Ȃ�
		// �K�[�h�A�j���[�V�����p
		if (0.0f < guard_dir) {// �p�x��0�x���傫���Ȃ�
			guard_dir -= Datas::GAUNTLET_GUARD_DIR_SPD * Delta::getTotalDelta();// ��]
		}
		else {// �ȉ��Ȃ�
			guard_dir = 0.0f;// �Œ�
		}

		// �_�b�V���A�j���[�V�����p
		if (0.0f < dash_dis) {// �A�j���[�V�����������Ă��Ȃ��Ȃ�
			dash_dis -= Datas::GAUNTLET_DASH_DIS_SPD * Delta::getTotalDelta();// ��]
		}
		else {// �ȉ��Ȃ�
			dash_dis = 0.0f;// �Œ�
		}

		if (75.0f < dash_dir) {
			dash_dir = 75.0f;
		}
		if (0.0f < dash_dir) {// �p�x��0���傫���Ȃ��
			dash_dir -= Datas::GAUNTLET_DASH_DIR_SPD * Delta::getTotalDelta();// ��]
		}
		else {// �ȉ��Ȃ�
			dash_dir = 0.0f;// �Œ�
		}

		// �v�Z
		dir = dir.Rotated(static_cast<float>((dash_dir + guard_dir + 270) * M_PI / 180));
		pos += dir * Datas::GAUNTLET_PLAYER_MOVE_DISTANCE;
	}

	Vector2D center = { Datas::PLAYER_WIDTH * 0.5f, Datas::PLAYER_HEIGHT * 0.5f };
	position = pos + center;// ���f
}
