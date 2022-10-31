#include "BaseField.h"
#include "Delta.h"
#include "Game.h"
#include "Camera.h"

BaseField::BaseField(Game& game) : pGame(game)
{
	BaseInit();
}

BaseField::BaseField(Game& game, Vector2D pos, Vector2D wid) : pGame(game)
{
	BaseInit(pos,wid);
}

BaseField::~BaseField()
{
}

void BaseField::Init() {}

void BaseField::BaseInit()
{
	isEnd = true;
	position = { 0.0f,0.0f };

	Init();
}

void BaseField::BaseInit(Vector2D pos, Vector2D wid)
{
	isEnd = false;
	position = pos;
	width = wid;

	Init();
}