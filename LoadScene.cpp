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
	if (Datas::GetIsEnd) {
		// �t�@�C�i���C�Y�Ɉڍs
		getGame().ChangePhase(Game::kFinalise);
		// �X���b�h�Ɠ���
		mThread.join();
	}
}
void LoadScene::Draw() {
	Novice::DrawBox(0, 0, 1920, 1080, 0.0f, BLACK, kFillModeSolid);
}
void LoadScene::Finalise() {
	getGame().ChangeScene(Game::kInGameScene);
	getGame().ChangePhase(Game::kInit);
}