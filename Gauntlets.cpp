#include "Gauntlets.h"
#include "Game.h"
#include "Camera.h"
#include "Datas.h"
#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "MyFunc.h"
#include "Quad.h"

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
}

void Gauntlets::Update()
{
	Vector2D pos = getPlayer().GetPosition();// �v���C���[���W�擾
	Vector2D dir = getPlayer().GetDirection();

	if (getPlayer().GetIsGuard()) {// �K�[�h���Ȃ�
		pos += dir * Datas::GAUNTLET_PLAYER_GUARD_DISTANCE;
	}
	else if (getPlayer().GetIsDash()) {// �_�b�V�����Ȃ�
		pos += dir * Datas::GAUNTLET_PLAYER_DASH_DISTANCE;
	}
	else {// ���[�u���Ȃ�
		dir = dir.Rotated(270 * M_PI / 180);
		pos += dir * Datas::GAUNTLET_PLAYER_MOVE_DISTANCE;
	}

	Vector2D center = { Datas::PLAYER_WIDTH * 0.5f, Datas::PLAYER_HEIGHT * 0.5f };
	gauntlets_pos = pos + center;// ���f
}

void Gauntlets::Draw()
{
	Quad temp = { {0.0f,0.0f},0.0f,0.0f };

	if (getPlayer().GetIsGuard()) {// �K�[�h���Ȃ�
		temp = My::RotateCenter(gauntlets_pos, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x) + 90 * M_PI / 180, Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
	else if (getPlayer().GetIsDash()) {// �_�b�V�����Ȃ�
		temp = My::RotateCenter(gauntlets_pos, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x), Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
	else {// ���[�u���Ȃ�
		temp = My::RotateCenter(gauntlets_pos, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x), Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
}