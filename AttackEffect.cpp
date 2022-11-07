#include "AttackEffect.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Delta.h"
#include <Novice.h>

AttackEffect::AttackEffect(Game& game, Vector2D pos) : BaseEffect(game,pos)
{
	BaseInit(pos);
}

AttackEffect::~AttackEffect()
{
}

void AttackEffect::Init()
{
	layer = 2;
	for (int i = 0; i < AttackEffectMaxNum; i++) {
		//エフェクトの位置、速度、サイズ初期化
		attackEffect[i].position = position;
		attackEffect[i].velocity = { My::RandomF(5.0f, 7.0f, 1), My::RandomF(5.0f, 7.0f, 1) };
		attackEffect[i].size = { Datas::EFFECTS_ATK_SIZE, Datas::EFFECTS_ATK_SIZE };

		//エフェクトが向かう方向をランダムにする
		attackEffect[i].theta = static_cast<float>(My::Random(0, 360));
		attackEffect[i].theta = static_cast<float>(attackEffect[i].theta * (M_PI / 180.0f));

		//エフェクト表示
		attackEffect[i].isEnd = false;
		attackEffect[i].acceleration = 0.08f;
	}
}

void AttackEffect::Update()
{
	for (int i = 0; i < AttackEffectMaxNum; i++) {
		if (attackEffect[i].isEnd == false) {
			//エフェクトのサイズx,yのどちらかが0になったら
			if (attackEffect[i].size.x <= 0 || attackEffect[i].size.y <= 0) {
				//エフェクト終了
				attackEffect[i].isEnd = true;
			}

			attackEffect[i].position.x += (cosf(attackEffect[i].theta) * attackEffect[i].velocity.x) * Delta::getTotalDelta();
			attackEffect[i].position.y += -(sinf(attackEffect[i].theta) * attackEffect[i].velocity.y) * Delta::getTotalDelta();

			attackEffect[i].velocity.x += attackEffect[i].acceleration * Delta::getTotalDelta();
			attackEffect[i].velocity.y += attackEffect[i].acceleration * Delta::getTotalDelta();

			attackEffect[i].size -= {Datas::EFFECTS_ATK_SPD, Datas::EFFECTS_ATK_SPD};
		}
	}


	// 終了処理
	if (endCheck()) {
		isEnd = true;
	}
}

void AttackEffect::Draw()
{
	for (int i = 0; i < AttackEffectMaxNum; i++) {
		if (!attackEffect[i].isEnd) {
			getCameraMain().DrawQuad({ {attackEffect[i].position.x - attackEffect[i].size.x * 0.5f,attackEffect[i].position.y - attackEffect[i].size.y * 0.5f},
				attackEffect[i].size.x,attackEffect[i].size.y }, Datas::EFFECTS_ATK_TEX,0,0,RED);
		}
	}
}

bool AttackEffect::endCheck()
{
	for (int i = 0; i < AttackEffectMaxNum; i++) {
		if (!attackEffect[i].isEnd) {// 終わっていないなら抜ける
			return false;
		}
	}
	return true;
}
