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
	alpha = 0x00;
	uiY.SetMode(Easing::kInBounce);
}

void InGameScene::Update() {

	getGame().getPlayer().Update();
	getGame().getBoss().Update();

	if (getPlayer().GetisGameOver() || getPlayer().GetisGameClear()) {
		alpha -= Delta::getTotalDelta() * 3.0f;
		if (alpha < 0x66) {
			alpha = 0x66;
		}
		if (uiY.GetEnd() != 500.0f) {
			uiY.SetStart(1500.0f);
			uiY.SetEnd(500.0f);
		}
		if (uiY.GetEnd() == 500.0f && uiY.IsEnd()) {
			uiY.SetStart(500.0f);
		}
		uiY.Move(Delta::getTotalDelta());
	}
	else {
		alpha += Delta::getTotalDelta() * 3.0f;
		if (alpha > 0xFF) {
			alpha = 0xFF;
		}
	}

	if (getPlayer().GetisGameOver()) {
		if (IsCntMode()) {
			if (Controller::IsTriggerButton(0, Controller::bB)) {
				getPlayer().SetisGameOver();
				alpha = 0x00;
			}
		}
		else {
			if (Key::IsTrigger(DIK_SPACE)) {
				getPlayer().SetisGameOver();
				alpha = 0x00;
			}
		}
	}
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


	// ui
	getCameraUI().DrawQuad({ {30,890}, 400 * (getPlayer().GetHealth() / Datas::PLAYER_MAX_HEALTH), 160}, Datas::UI_HEALTH_TEX);

	getCameraUI().DrawQuad({ {30,890}, 400, 160}, Datas::UI_TEX);

	// 暗く
	getCameraUI().DrawQuad({ {0,0},1920,1080 }, Datas::BackGroundTex, 0, 0, BLACK - alpha);

	// ゲームオーバー
	if (getPlayer().GetisGameOver()) {
		getCameraUI().DrawQuad({ {1920 / 2 - 350,uiY.p}, 700, 500 }, Datas::GAMEOVER_TEX);
	}

	if (!getBoss().GetisnTutorial()) {
		if (!getBoss().GetmoveTutorial()) {
			if (IsCntMode()) {
				Novice::ScreenPrintf(1400, 500, "tutorial : move [R stick]");
			}
			else {
				Novice::ScreenPrintf(1400, 500, "tutorial : move [WASD]");
			}
		}
		else if (!getBoss().GetdashTutorial()) {
			if (IsCntMode()) {
				Novice::ScreenPrintf(1400, 500, "tutorial : dash [R button]");
			}
			else {
				Novice::ScreenPrintf(1400, 500, "tutorial : dash [SPACE]");
			}
		}
		else if (!getBoss().GetguardTutorial()) {
			if (IsCntMode()) {
				Novice::ScreenPrintf(1400, 500, "tutorial : guard [L button]");
			}
			else {
				Novice::ScreenPrintf(1400, 500, "tutorial : guard [Z]");
			}
		}
		else if (!getBoss().GetjustTutorial()) {
			if (IsCntMode()) {
				Novice::ScreenPrintf(1400, 500, "tutorial : justDodge [R button]");
			}
			else {
				Novice::ScreenPrintf(1400, 500, "tutorial : justDodge [SPACE]");
			}
		}
		else if (!getBoss().GetchargeTutorial()) {
			if (IsCntMode()) {
				Novice::ScreenPrintf(1400, 500, "tutorial : chargeAttack [B]");
			}
			else {
				Novice::ScreenPrintf(1400, 500, "tutorial : chargeAttack [X]");
			}
		}
	}
}

void InGameScene::Finalise() {

}