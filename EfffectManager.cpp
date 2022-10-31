#include "Game.h"
#include "EfffectManager.h"
#include "ClickEffect.h"

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

void EffectManager::Draw()
{
	for (int i = 0; i < effectArraySize; i++) {
		effects[i]->BaseDraw();
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
			case EffectType::Click:
				delete effects[nextIndex];// 入ってるのをdelete
				effects[nextIndex] = new ClickEffect(*pGame, position);// 追加
				break;
			case EffectType::None:
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
	return effects[effectNum]->GetIsEnd();
}

// エフェクトの配列
BaseEffect* EffectManager::effects[effectArraySize];
// 次に追加するエフェクトの添字
int EffectManager::nextIndex;
// ゲームのポインタ
Game* EffectManager::pGame = nullptr;