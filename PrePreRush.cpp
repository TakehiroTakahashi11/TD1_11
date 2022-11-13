#include "PrePreRush.h"
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

PrePreRush::PrePreRush(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

PrePreRush::~PrePreRush()
{
}

void PrePreRush::Init()
{
	elapsedFrame = 0.0f;
	layer = 0;
}

void PrePreRush::Update()
{
	// èIóπèàóù
	if (360.0f < elapsedFrame) {
		isEnd = true;
	}
}

void PrePreRush::Draw()
{
	if (!isEnd) {
		getCameraMain().DrawQuad({ {position.x - Datas::EFFECTS_PRERUSH_WIDTH * 0.5f, -Datas::EFFECTS_PRERUSH_HEIGHT * 0.5f} ,Datas::EFFECTS_PRERUSH_WIDTH ,Datas::EFFECTS_PRERUSH_HEIGHT }, Datas::PRE_RUSH_TEX);
	}
}