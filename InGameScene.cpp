#include "InGameScene.h"
#include "Datas.h"
#include "Camera.h"
#include "Quad.h"
#include "KeyMouseInput.h"
#include "Game.h"
#include "EfffectManager.h"
#include "Player.h"
#include "Boss.h"
#include "Game.h"

InGameScene::InGameScene(Game* pGame) : BaseScene(pGame)
{
}

void InGameScene::Init() {
	getCameraMain().setScale(1.0f);

	// 初期化を抜ける
	getGame()->ChangePhase(Game::kUpdate);
}

void InGameScene::Update() {
	getGame()->getPlayer().Update();
	getGame()->getBoss().Update();
}

void InGameScene::Draw() {
	getGame()->getPlayer().Draw();
	getGame()->getBoss().Draw();
}

void InGameScene::Finalise() {

}