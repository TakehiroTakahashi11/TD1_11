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
	getCameraMain().setScale(1.0f);

	// �������𔲂���
	getGame().ChangePhase(Game::kUpdate);
}

void InGameScene::Update() {
	// if(�`���[�g���A���I��){
	getGame().getMap().SetMapNum(1);// �X�e�[�W1��
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

	// �r�l�b�g
	Novice::SetBlendMode(kBlendModeMultily);
	getCameraUI().DrawQuad({ {0,0},1920,1080 }, Datas::VINETT_TEX);
	Novice::SetBlendMode(kBlendModeNormal);

	// �G�t�F�N�g�`��
	BulletManager::Draw();
	EffectManager::Draw2();

	// UI
	Novice::ScreenPrintf(10, 860, "health:%.1f", getPlayer().GetHealth());
	getCameraUI().DrawQuad({ {150,200},getPlayer().GetHealth(),30 }, Datas::BackGroundTex,0,0,RED);
	Novice::ScreenPrintf(10, 910, "guard:%.1f", getPlayer().GetStamina());
	getCameraUI().DrawQuad({ {150,150},getPlayer().GetStamina(),30 }, Datas::BackGroundTex,0,0,BLUE);
	Novice::ScreenPrintf(10, 960, "charge:%.1f", getPlayer().GetCharge());
	getCameraUI().DrawQuad({ {150,100},getPlayer().GetCharge(),30 }, Datas::BackGroundTex);
}

void InGameScene::Finalise() {

}