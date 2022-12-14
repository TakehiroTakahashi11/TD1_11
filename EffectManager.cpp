#include "Game.h"
#include "EffectManager.h"
#include "BaseEffect.h"
#include "HitEffect.h"
#include "AttackEffect.h"
#include "Thunder.h"
#include "PreThunder.h"
#include "PlayerDashAnim.h"
#include "PlayerBoost.h"
#include "MagicCircleThunder.h"
#include "BulletDeath.h"
#include "BossAttack1Anim.h"
#include "PreRush.h"
#include "PrePreRush.h"

void EffectManager::Init(Game& Game)
{
	// ポインタを保存
	pGame = &Game;

	// 一旦ベースエフェクトで初期化
	for (int i = 0; i < effectArraySize; i++) {
		effects[i] = new BaseEffect(*pGame);
		effects[i]->BaseInit();
	}

}

void EffectManager::Update()
{
	for (int i = 0; i < effectArraySize; i++) {
		effects[i]->BaseUpdate();
	}
}

void EffectManager::Draw0()
{
	for (int i = 0; i < effectArraySize; i++) {
		if (effects[i]->GetIsLayer() == 0) {
			effects[i]->BaseDraw();
		}
	}
}

void EffectManager::Draw1()
{
	for (int i = 0; i < effectArraySize; i++) {
		if (effects[i]->GetIsLayer() == 1) {
			effects[i]->BaseDraw();
		}
	}
}

void EffectManager::Draw2()
{
	for (int i = 0; i < effectArraySize; i++) {
		if (effects[i]->GetIsLayer() == 2) {
			effects[i]->BaseDraw();
		}
	}
}

void EffectManager::Finalise()
{
	for (int i = 0; i < effectArraySize; i++) {
		delete effects[i];
	}
}

int EffectManager::MakeNewEffect(Vector2D position, EffectType effectType)
{
	// 追加するまでループ
	while (true) {
		// 検索
		nextIndex++;
		if (nextIndex >= effectArraySize) {
			nextIndex = 0;
		}

		// 終わっていたら追加
		if (effects[nextIndex]->GetIsEnd()) {
			// 処理に合わせてcase変更、追加
			switch (effectType)
			{
			case EffectType::kHit:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new HitEffect(*pGame, position);// 追加
				break;
			case EffectType::kAtttack:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new AttackEffect(*pGame, position);// 追加
				break;
			case EffectType::kThunder:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new Thunder(*pGame, position);// 追加
				break;
			case EffectType::kPreThunder:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new PreThunder(*pGame, position);// 追加
				break;
			case EffectType::kPrePreThunder:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new MagicCircleThunder(*pGame, position);// 追加
				break;
			case EffectType::kPlayerDash:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new PlayerDashAnim(*pGame, position);// 追加
				break;
			case EffectType::kPlayerBoost:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new PlayerBoost(*pGame, position);// 追加
				break;
			case EffectType::kBulletDeath:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new BulletDeath(*pGame, position);// 追加
				break;
			case EffectType::kPrePreBullet:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new BossAttack1Anim(*pGame, position);// 追加
				break;
			case EffectType::kPreRush:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new PreRush(*pGame, position);// 追加
				break;
			case EffectType::kPrePreRush:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new PrePreRush(*pGame, position);// 追加
				break;
			case EffectType::NoneEffect:
			default:
				break;
			}
			// 追加できたらループを抜ける
			break;
		}

	}

	return nextIndex;// 管理用intを返す
}

void EffectManager::SetEnd(int effectNum)
{
	effects[effectNum]->SetEnd();
}

bool EffectManager::GetIsEnd(int effectNum)
{
	if (effectNum == -1) {
		return false;
	}
	return effects[effectNum]->GetIsEnd();
}

// エフェクトの配列
BaseEffect* EffectManager::effects[effectArraySize];
// 次に追加するエフェクトの添字
int EffectManager::nextIndex;
// ゲームのポインタ
Game* EffectManager::pGame = nullptr;