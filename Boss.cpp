#include "Boss.h"
#include "Datas.h"
#include "Camera.h"

Boss::Boss(Game* pGame) : Obj(pGame)
{
	Init();
}

void Boss::Init()
{
	position = { Datas::BOSS_POS_X,Datas::BOSS_POS_Y };
	width = Datas::BOSS_WIDTH;
	height = Datas::BOSS_HEIGHT;
}

void Boss::Update()
{
}

void Boss::Draw()
{
	getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f},width,height }, Datas::BOSS_TEX);
}
