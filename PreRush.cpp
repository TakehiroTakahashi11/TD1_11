#include "PreRush.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#include "Delta.h"
#include "Game.h"
#include "Player.h"
#include "Datas.h"
#include <Novice.h>

PreRush::PreRush(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

PreRush::~PreRush()
{
}

void PreRush::Init()
{
	elapsedFrame = 0.0f;
	layer = 0;
}

void PreRush::Update()
{
	position = pGame.getPlayer().GetPosition();

	// èIóπèàóù
	if (360.0f < elapsedFrame) {
		isEnd = true;
	}
}

void PreRush::Draw()
{
	if (!isEnd) {
		getCameraMain().DrawQuad({ {position.x - Datas::EFFECTS_PRERUSH_WIDTH * 0.5f, -Datas::EFFECTS_PRERUSH_HEIGHT * 0.5f} ,Datas::EFFECTS_PRERUSH_WIDTH ,Datas::EFFECTS_PRERUSH_HEIGHT }, Datas::PRE_RUSH_TEX);
		getCameraMain().DrawQuad({ {position.x - 24.0f,position.y + 48.0f} ,48.0f ,48.0f }, Datas::RUSH_INDICATE_TEX);
	}
}