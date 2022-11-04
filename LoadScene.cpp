#include "LoadScene.h"
#include "Game.h"
#include <Novice.h>
#include "Datas.h"

LoadScene::LoadScene(Game& pGame) : BaseScene(pGame)
{
}

void LoadScene::Init() {
	getGame().ChangePhase(Game::kUpdate);
	mThread = std::thread(Datas::LoadTexture);
}
void LoadScene::Update() {
	if (Datas::GetIsEnd()) {
		// ファイナライズに移行
		getGame().ChangePhase(Game::kFinalise);
		// スレッドと同期
		mThread.join();
	}

	if (Datas::DEBUG_MODE) {
		Novice::ScreenPrintf(500, 500, "loading : %d / %d", Datas::GetPer(), Datas::Max_Per);
	}
}
void LoadScene::Draw() {
	Novice::DrawBox(0, 0, 1920, 1080, 0.0f, BLACK, kFillModeSolid);
}
void LoadScene::Finalise() {
	getGame().ChangeScene(Game::kInGameScene);
	getGame().ChangePhase(Game::kInit);
}