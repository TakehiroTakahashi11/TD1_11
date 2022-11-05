#include "Boss.h"
#include "Datas.h"
#include "Player.h"
#include "Camera.h"
#include "MyFunc.h"
#include "EffectManager.h"
#include <Novice.h>
#include "Delta.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "KeyMouseInput.h"
#include "BulletManager.h"

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

	elapsedTime = 0.0f;
	lastKnockBackTime = 0.0f;
	lastActionTime = 0.0f;

	nowAction = None;
	nextAction = kMove;

	beforePos = { 0.0f,0.0f };
	moveTheta = 0.0f;

	attack1Elapsed = 0.0f;
	attack1bullet1Time = 0.0f;
	attack1bullet2Time = 0.0f;
	attack1bullet3Time = 0.0f;
	attack1bullet4Time = 0.0f;
	attack1bullet5Time = 0.0f;
	attack1bullet6Time = 0.0f;
	attack1bullet7Time = 0.0f;
	attack1bullet8Time = 0.0f;
	attack1bullet9Time = 0.0f;
	attack1bullet10Time = 0.0f;
	bullet_handle = 0;

	isFloating = false;

	anim = 0.0f;
}

void Boss::Update()
{
	if (Datas::DEBUG_MODE) {
		if (Key::IsTrigger(DIK_J)) {
			SetNextAction(kAttack1);
		}
	}

	// アクション
	Action();

	// 当たり判定
	Collision();

	// ノックバック
	if (isKnockBack) {
		KnockBack();
	}

	// アニメーション
	Animation();

	if (Datas::DEBUG_MODE) {
		Novice::ScreenPrintf(300, 40, "bosspos:%.1f", position.x);
		Novice::ScreenPrintf(450, 40, "bosspos:%.1f", position.y);
		Novice::ScreenPrintf(300, 60, " bossknockBackvelx:%.1f", knockBackVel.x);
		Novice::ScreenPrintf(450, 60, " bossknockBackvely:%.1f", knockBackVel.y);
	}
}

void Boss::Draw()
{
	getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f},width,height }, Datas::BOSS1_TEX,
		static_cast<int>(anim) % Datas::BOSS1_ANIM_MAX_X, anim < Datas::BOSS1_ANIM_MAX_X ? 0 : 1);
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
				getPlayer().SetKnockBack((p_pos - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
				getPlayer().SetMove();
				EffectManager::MakeNewEffect(p_pos, kHit);
			}
		}
		else {
			if (My::CollisonCircletoPoint(position, Datas::BOSS1_COL_WIDTH, Datas::BOSS1_COL_HEIGHT, p_pos)) {
				getPlayer().SetDamage(Datas::BOSS1_HIT_DAMAGE);
				getPlayer().SetKnockBack((p_pos - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
				getPlayer().SetMove();
				EffectManager::MakeNewEffect(p_pos, kHit);
			}
		}
	}
}

void Boss::KnockBack()
{
	if (knockBackVel.x != 0.0f || knockBackVel.y != 0.0f) {
		knockBackVel -= knockBackVel.Normalized() * Datas::GAUNTLET_KNOCKBACK_DIS * Delta::getTotalDelta();
		if (knockBackVel.Length() < Datas::GAUNTLET_KNOCKBACK_DIS + 0.1f) {
			knockBackVel.setZero();
		}
		position += knockBackVel * Delta::getTotalDelta();
	}
	else {
		isKnockBack = false;
		beforePos = position;
		moveTheta = 0.0f;
	}
}

void Boss::SetNextAction(BossAction bossaction)
{
	nextAction = bossaction;
}

void Boss::Action()
{
	canMigration = false;

	// 実行
	switch (nowAction)
	{
	case Boss::kMove:
		Move();
		break;
	case Boss::kAttack1:
		Attack1();
		break;
	case Boss::None:
	default:
		break;
	}

	// 予約アクションがあるなら、移行可能までの判定処理
	if (nextAction != None) {
		switch (nowAction)
		{
		case Boss::kMove:
			MoveMig();
			break;
		case Boss::kAttack1:
			Attack1Mig();
			break;
		case Boss::None:
		default:
			canMigration = true;
			break;
		}
	}

	// 移行可能なら移行時一回のみの処理
	if (nextAction != None && canMigration) {
		switch (nextAction)
		{
		case Boss::kMove:
			break;
		case Boss::kAttack1:
			break;
		case Boss::None:
		default:
			break;
		}
		nowAction = nextAction;
		nextAction = None;
	}
}

void Boss::Move()
{
	if (!isKnockBack) {
		moveTheta += Datas::BOSS1_MOVE_SPD;
		if (2.0f * M_PI < moveTheta) {
			moveTheta -= 2.0f * M_PI;
		}
		position.y = beforePos.y + sinf(moveTheta) * Datas::BOSS1_MOVE_AMP;
	}
}

void Boss::MoveMig()
{
	if ((-Datas::BOSS1_MOVE_SPD < moveTheta && moveTheta < Datas::BOSS1_MOVE_SPD)
		|| (-Datas::BOSS1_MOVE_SPD < moveTheta - M_PI && moveTheta - M_PI < Datas::BOSS1_MOVE_SPD)) {
		beforePos = position;
		moveTheta = 0.0f;
		canMigration = true;
	}
}

void Boss::Attack1()
{
	attack1Elapsed += Delta::getTotalDelta();
	if (attack1bullet1Time == 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		EffectManager::MakeNewEffect(position, kThunder);
		attack1bullet1Time = attack1Elapsed;
	}
	if (attack1bullet2Time == 0.0f && attack1Elapsed - attack1bullet1Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet1Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet2Time = attack1Elapsed;
	}
	if (attack1bullet3Time == 0.0f && attack1Elapsed - attack1bullet2Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet2Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet3Time = attack1Elapsed;
	}
	if (attack1bullet4Time == 0.0f && attack1Elapsed - attack1bullet3Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet3Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet4Time = attack1Elapsed;
	}
	if (attack1bullet5Time == 0.0f && attack1Elapsed - attack1bullet4Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet4Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet5Time = attack1Elapsed;
	}
	if (attack1bullet6Time == 0.0f && attack1Elapsed - attack1bullet5Time > Datas::BOSS_ATTACK1_WAVE_DIS && attack1bullet5Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet6Time = attack1Elapsed;
	}
	if (attack1bullet7Time == 0.0f && attack1Elapsed - attack1bullet6Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet6Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet7Time = attack1Elapsed;
	}
	if (attack1bullet8Time == 0.0f && attack1Elapsed - attack1bullet7Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet7Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet8Time = attack1Elapsed;
	}
	if (attack1bullet9Time == 0.0f && attack1Elapsed - attack1bullet8Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet8Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet9Time = attack1Elapsed;
	}
	if (attack1bullet10Time == 0.0f && attack1Elapsed - attack1bullet9Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet9Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet10Time = attack1Elapsed;
		SetNextAction(kMove);
	}

}

void Boss::Attack1Mig()
{
	attack1Elapsed = 0.0f;
	attack1bullet1Time = 0.0f;
	attack1bullet2Time = 0.0f;
	attack1bullet3Time = 0.0f;
	attack1bullet4Time = 0.0f;
	attack1bullet5Time = 0.0f;
	attack1bullet6Time = 0.0f;
	attack1bullet7Time = 0.0f;
	attack1bullet8Time = 0.0f;
	attack1bullet9Time = 0.0f;
	attack1bullet10Time = 0.0f;
	canMigration = true;
}


void Boss::Animation()
{
	anim += Delta::getTotalDelta() / Datas::BOSS1_ANIM_SPD;
	if (Datas::BOSS1_ANIM_MAX_X * Datas::BOSS1_ANIM_MAX_Y < anim) {
		anim = 0.0f;
	}
}
