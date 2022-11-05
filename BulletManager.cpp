#include "Game.h"
#include "BulletManager.h"
#include "BossAttack1.h"

void BulletManager::Init(Game& Game)
{
	// ポインタを保存
	pGame = &Game;

	// 一旦ベースエフェクトで初期化
	for (int i = 0; i < bulletArraySize; i++) {
		 bullets[i] = new BaseBullet(*pGame);
		 bullets[i]->BaseInit();
	}

}

void BulletManager::Update()
{
	for (int i = 0; i < bulletArraySize; i++) {
		bullets[i]->BaseUpdate();
	}
}

void BulletManager::Draw()
{
	for (int i = 0; i < bulletArraySize; i++) {
		bullets[i]->BaseDraw();
	}
}

void BulletManager::Finalise()
{
	for (int i = 0; i < bulletArraySize; i++) {
		delete  bullets[i];
	}
}

int BulletManager::MakeNewBullet(Vector2D position, BulletType bulletType)
{
	// 追加するまでループ
	while (true) {
		// 検索
		nextIndex++;
		if (nextIndex >= bulletArraySize) {
			nextIndex = 0;
		}

		// 終わっていたら追加
		if (bullets[nextIndex]->GetIsEnd()) {
			// 処理に合わせてcase変更、追加
			switch (bulletType)
			{
			case BulletType::kBossAttack1:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position);// 追加
				break;
			case BulletType::NoneBullet:
			default:
				break;
			}
			// 追加できたらループを抜ける
			break;
		}

	}

	return nextIndex;// 管理用intを返す
}

void BulletManager::SetEnd(int bulletNum)
{
	bullets[bulletNum]->SetEnd();
}

bool BulletManager::GetIsEnd(int bulletNum)
{
	return bullets[bulletNum]->GetIsEnd();
}

// エフェクトの配列
BaseBullet* BulletManager::bullets[bulletArraySize];
// 次に追加するエフェクトの添字
int BulletManager::nextIndex;
// ゲームのポインタ
Game* BulletManager::pGame = nullptr;