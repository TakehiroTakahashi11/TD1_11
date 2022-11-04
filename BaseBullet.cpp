#include "BaseBullet.h"
#include "Delta.h"
#include "Game.h"
#include "Camera.h"

BaseBullet::BaseBullet(Game& game) : pGame(game)
{
	BaseInit();
}

BaseBullet::BaseBullet(Game& game, Vector2D pos) : pGame(game)
{
	BaseInit(pos);
}

BaseBullet::~BaseBullet()
{
}

void BaseBullet::Init() {}

void BaseBullet::Update() {}

void BaseBullet::Draw() {}

void BaseBullet::BaseInit()
{
	isEnd = true;
	elapsedFrame = 0.0f;
	position = { 0.0f,0.0f };

	Init();
}

void BaseBullet::BaseInit(Vector2D pos)
{
	isEnd = false;
	elapsedFrame = 0.0f;
	position = pos;

	Init();
}

void BaseBullet::BaseUpdate()
{
	if (isEnd) {
		return;
	}

	elapsedFrame += Delta::getTotalDelta();

	Update();
}

void BaseBullet::BaseDraw()
{
	if (isEnd) {
		return;
	}

	Draw();
}

Camera& BaseBullet::getCameraMain() {
	return  pGame.getCameraMain();
}
Camera& BaseBullet::getCameraSub() {
	return  pGame.getCameraSub();
}
Camera& BaseBullet::getCameraUI() {
	return  pGame.getCameraUI();
}