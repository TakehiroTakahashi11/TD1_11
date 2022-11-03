#include "Boss.h"
#include "Datas.h"
#include "Player.h"
#include "Camera.h"
#include "MyFunc.h"
#include "EffectManager.h"
#include <Novice.h>
#include "Delta.h"

Boss::Boss(Game& pGame) : Obj(pGame)
{
	Init();
}

void Boss::Init()
{
	position = { Datas::BOSS1_POS_X,Datas::BOSS1_POS_Y };
	width = Datas::BOSS1_WIDTH;
	height = Datas::BOSS1_HEIGHT;
	isKnockBack = false;
	knockBackVel = { 0.0f,0.0f };
	isFloating = false;
}

void Boss::Update()
{
	// 当たり判定
	Collision();

	// ノックバック
	if (isKnockBack) {
		KnockBack();
	}

	if (Datas::DEBUG_MODE) {
		Novice::ScreenPrintf(300, 40, "position:%.1f", position.x);
		Novice::ScreenPrintf(450, 40, "position:%.1f", position.y);
		Novice::ScreenPrintf(300, 60, " knockBackvel:%.1f", knockBackVel.x);
		Novice::ScreenPrintf(450, 60, " knockBackvel:%.1f", knockBackVel.y);
	}
}

void Boss::Draw()
{
	getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f},width,height }, Datas::BOSS1_TEX);
}

void Boss::Collision()
{
	PtoBCollision();
}

void Boss::PtoBCollision()
{
	if (!getPlayer().GetIsInvincible() && !isFloating) {// 無敵じゃないなら
		Vector2D center = { Datas::PLAYER_WIDTH * 0.5f, Datas::PLAYER_HEIGHT * 0.5f };
		Vector2D p_pos = getPlayer().GetPosition() - center;
		if (getPlayer().GetIsDash()) {
			if (My::CollisonCircletoPoint(position, Datas::BOSS1_COL_WIDTH, Datas::BOSS1_COL_HEIGHT, p_pos)) {
				knockBackVel = (position - p_pos).Normalized() * Datas::GAUNTLET_KNOCKBACK_POWER;
				isKnockBack = true;
				getPlayer().SetKnockBack((p_pos - position).Normalized() * Datas::GAUNTLET_KNOCKBACK_POWER);
				getPlayer().SetMove();
				EffectManager::MakeNewEffect(p_pos, Hit);
			}
		}
		else {
			if (My::CollisonCircletoPoint(position, Datas::BOSS1_COL_WIDTH, Datas::BOSS1_COL_HEIGHT, p_pos)) {
				getPlayer().SetDamage(Datas::BOSS1_HIT_DAMAGE);
				getPlayer().SetKnockBack((p_pos - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
				getPlayer().SetMove();
				EffectManager::MakeNewEffect(p_pos, Hit);
			}
		}
	}
}

void Boss::KnockBack()
{
	if (knockBackVel.x != 0.0f || knockBackVel.y != 0.0f) {
		knockBackVel -= knockBackVel.Normalized() * Datas::PLAYER_KNOCKBACK_DIS * Delta::getTotalDelta();
		if (knockBackVel.Length() < Datas::PLAYER_KNOCKBACK_DIS + 0.1f) {
			knockBackVel.setZero();
		}
		position += knockBackVel * Delta::getTotalDelta();

		if (Datas::DEBUG_MODE) {
			Novice::ScreenPrintf(400, 0, "BOSS_KNOCKBACK");
		}
	}
	else {
		isKnockBack = false;
	}
}