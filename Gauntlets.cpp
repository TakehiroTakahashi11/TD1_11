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

Gauntlets::Gauntlets(Game& game) : Obj(game)
{
	Init();
}

Gauntlets::~Gauntlets()
{
}

void Gauntlets::Init()
{
	x_anim = 0;
	gauntlets_pos = { 0.0f,0.0f };
	isBreak = false;
	guard_dir = 0.0f;
	dash_dis = 0.0f;
}

void Gauntlets::Update()
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
		dir = dir.Rotated((guard_dir + 270) * M_PI / 180);
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
		dir = dir.Rotated((dash_dir + 270) * M_PI / 180);
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
		dir = dir.Rotated((dash_dir + guard_dir + 270) * M_PI / 180);
		pos += dir * Datas::GAUNTLET_PLAYER_MOVE_DISTANCE;
	}

	Vector2D center = { Datas::PLAYER_WIDTH * 0.5f, Datas::PLAYER_HEIGHT * 0.5f };
	gauntlets_pos = pos + center;// ���f
}

void Gauntlets::Draw()
{
	Quad temp = { {0.0f,0.0f},0.0f,0.0f };

	if (getPlayer().GetIsGuard()) {// �K�[�h���Ȃ�
		temp = My::RotateCenter(gauntlets_pos, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x) + guard_dir * M_PI / 180, Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
	else if (getPlayer().GetIsDash()) {// �_�b�V�����Ȃ�
		temp = My::RotateCenter(gauntlets_pos, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x), Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
	else {// ���[�u���Ȃ�
		temp = My::RotateCenter(gauntlets_pos, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x) + guard_dir * M_PI / 180, Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
}