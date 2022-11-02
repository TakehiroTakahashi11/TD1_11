#include "Gauntlets.h"
#include "Game.h"
#include "Camera.h"
#include "Datas.h"
#include "Player.h"

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

	if (getPlayer().GetIsGuard()) {// ガード中なら
		pos += getPlayer().GetDirection() * Datas::GAUNTLET_PLAYER_DISTANCE;// 正面に描画
	}

	gauntlets_pos = pos;// 反映
}

void Gauntlets::Draw()
{
	getCameraMain().DrawQuad({ {gauntlets_pos.x - Datas::GAUNTLET_WIDTH * 0.5f,gauntlets_pos.y - Datas::GAUNTLET_HEIGHT * 0.5f},Datas::GAUNTLET_WIDTH,Datas::GAUNTLET_HEIGHT }, Datas::GAUNTLET_TEX, x_anim, 0, 0x000000FF);
}
