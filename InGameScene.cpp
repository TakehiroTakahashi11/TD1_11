#include "InGameScene.h"
#include "Datas.h"
#include "Camera.h"
#include "Quad.h"
#include "KeyMouseInput.h"
#include "Game.h"
#include "EffectManager.h"
#include "Player.h"
#include "Boss.h"
#include "Game.h"
#include "Map.h"
#include "BulletManager.h"

InGameScene::InGameScene(Game& pGame) : BaseScene(pGame)
{
}

void InGameScene::Init() {
	getCameraMain().setScale(0.6f);

	// 初期化を抜ける
	getGame().ChangePhase(Game::kUpdate);
}

void InGameScene::Update() {
	// if(チュートリアル終了){
	getGame().getMap().SetMapNum(1);// ステージ1に
	// }

	getGame().getPlayer().Update();
	getGame().getBoss().Update();
}

void InGameScene::Draw() {
	getGame().getMap().Draw();
	EffectManager::Draw0();
	getGame().getPlayer().Draw();
	getGame().getBoss().Draw();
	EffectManager::Draw1();

	// エフェクト描画
	BulletManager::Draw();
	EffectManager::Draw2();

	// ビネット
	getCameraUI().DrawQuad({ {0,0},1920,1080 }, Datas::VINETT_TEX);

	// UI
	Novice::ScreenPrintf(10, 860, "health:%.1f", getPlayer().GetHealth());
	getCameraUI().DrawQuad({ {150,200},getPlayer().GetHealth(),30 }, Datas::BackGroundTex,0,0,RED);
	Novice::ScreenPrintf(10, 910, "guard:%.1f", getPlayer().GetStamina());
	getCameraUI().DrawQuad({ {150,150},getPlayer().GetStamina(),30 }, Datas::BackGroundTex,0,0,BLUE);
	Novice::ScreenPrintf(10, 960, "charge:%.1f", getPlayer().GetCharge());
	getCameraUI().DrawQuad({ {150,100},getPlayer().GetCharge(),30 }, Datas::BackGroundTex);

	Novice::ScreenPrintf(10, 760, "boss:%.1f", getBoss().GetHealth());
	getCameraUI().DrawQuad({ {150,300},getBoss().GetHealth() * 2.0f,30}, Datas::BackGroundTex);
}

void InGameScene::Finalise() {

}