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
	Vector2D pos = getPlayer().GetPosition();// プレイヤー座標取得
	Vector2D dir = getPlayer().GetDirection();

	if (getPlayer().GetIsGuard()) {// ガード中なら
		pos += dir * Datas::GAUNTLET_PLAYER_GUARD_DISTANCE;
	}
	else if (getPlayer().GetIsDash()) {// ダッシュ中なら
		pos += dir * Datas::GAUNTLET_PLAYER_DASH_DISTANCE;
	}
	else {// ムーブ中なら
		dir = dir.Rotated(270 * M_PI / 180);
		pos += dir * Datas::GAUNTLET_PLAYER_MOVE_DISTANCE;
	}

	Vector2D center = { Datas::PLAYER_WIDTH * 0.5f, Datas::PLAYER_HEIGHT * 0.5f };
	gauntlets_pos = pos + center;// 反映
}

void Gauntlets::Draw()
{
	Quad temp = { {0.0f,0.0f},0.0f,0.0f };

	if (getPlayer().GetIsGuard()) {// ガード中なら
		temp = My::RotateCenter(gauntlets_pos, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x) + 90 * M_PI / 180, Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
	else if (getPlayer().GetIsDash()) {// ダッシュ中なら
		temp = My::RotateCenter(gauntlets_pos, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x), Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
	else {// ムーブ中なら
		temp = My::RotateCenter(gauntlets_pos, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x), Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
}