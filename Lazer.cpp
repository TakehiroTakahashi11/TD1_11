#include "Lazer.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Delta.h"
#include "Player.h"
#include "Gauntlets.h"
#include "Map.h"
#include <Novice.h>
#include "EffectManager.h"
#include "BulletManager.h"
#include "Boss.h"

Lazer::Lazer(Game& game, Vector2D pos) : BaseBullet(game, pos)
{
	BaseInit(pos);
}

Lazer::~Lazer()
{
}

void Lazer::Init()
{
	bossPos = pGame.getBoss().GetPosition();
	dir = position - bossPos;
}

void Lazer::Update()
{
	anim += Delta::getTotalDelta();


}

void Lazer::Draw()
{
	// pGame.getCameraMain().DrawQuad({  }, Datas::LASER_TEX);
}
