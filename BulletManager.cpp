#include "Game.h"
#include "BulletManager.h"
#include "BossAttack1.h"
#include "BossAttack2.h"
#include "Mine.h"
#include "Enemy1.h"

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
			case BulletType::kBossAttack1_1:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position,1);// 追加
				break;
			case BulletType::kBossAttack1_2:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 2);// 追加
				break;
			case BulletType::kBossAttack1_3:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 3);// 追加
				break;
			case BulletType::kBossAttack1_4:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 4);// 追加
				break;
			case BulletType::kBossAttack1_5:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 5);// 追加
				break;
			case BulletType::kBossAttack1_6:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 6);// 追加
				break;
			case BulletType::kBossAttack1_7:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 7);// 追加
				break;
			case BulletType::kBossAttack1_8:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 8);// 追加
				break;
			case BulletType::kBossAttack1_9:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 9);// 追加
				break;
			case BulletType::kBossAttack1_10:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 10);// 追加
				break;
			case BulletType::kBossAttack2:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new BossAttack2(*pGame, position);// 追加
				break;
			case BulletType::kBossAttackMine1:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new Mine(*pGame, position);// 追加
				break;
			case BulletType::kBossAttackEnemy1:
				delete bullets[nextIndex];// 入ってるのをdelete
				bullets[nextIndex] = new Enemy1(*pGame, position);// 追加
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