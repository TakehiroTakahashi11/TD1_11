#include "BaseEffect.h"
#include "Delta.h"
#include "Game.h"
#include "Camera.h"

BaseEffect::BaseEffect(Game& game): pGame(game)
{
	BaseInit();
}

BaseEffect::BaseEffect(Game& game, Vector2D pos) : pGame(game)
{
	BaseInit(pos);
}

BaseEffect::~BaseEffect()
{
}

void BaseEffect::Init(){}

void BaseEffect::Update(){}

void BaseEffect::Draw(){}

void BaseEffect::BaseInit()
{
	isEnd = true;
	elapsedFrame = 0.0f;
	position = { 0.0f,0.0f };

	Init();
}

void BaseEffect::BaseInit(Vector2D pos)
{
	isEnd = false;
	elapsedFrame = 0.0f;
	position = pos;

	Init();
}

void BaseEffect::BaseUpdate()
{
	if (isEnd) {
		return;
	}

	elapsedFrame += Delta::getTotalDelta();

	Update();
}

void BaseEffect::BaseDraw()
{
	if (isEnd) {
		return;
	}

	Draw();
}

Camera& BaseEffect::getCameraMain() {
	return  pGame.getCameraMain();
}
Camera& BaseEffect::getCameraSub() {
	return  pGame.getCameraSub();
}
Camera& BaseEffect::getCameraUI() {
	return  pGame.getCameraUI();
}