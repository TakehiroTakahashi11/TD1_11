#include "InGameScene.h"
#include "Datas.h"
#include "Camera.h"
#include "Quad.h"
#include "KeyMouseInput.h"
#include "Game.h"
#include "EfffectManager.h"
#include "Player.h"
#include "Game.h"

InGameScene::InGameScene(Game& pGame) : BaseScene(pGame)
{
}

void InGameScene::Init() {
	getCameraMain().setScale(1.0f);
	// EffectManager::MakeNewEffect({ 100.0f,100.0f }, Click);

	// èâä˙âªÇî≤ÇØÇÈ
	getGame().ChangePhase(Game::kUpdate);
}

void InGameScene::Update() {
	getGame().getPlayer().Update();
}

void InGameScene::Draw() {
	// getCameraUI().DrawQuad({ {0,0},1920,1080 }, Datas::BackGroundTex,0,0,BLACK);
	getGame().getPlayer().Draw();
}

void InGameScene::Finalise() {

}