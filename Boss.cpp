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
	homePos = { 0.0f,0.0f };
	health = Datas::BOSS1_HEALTH_MAX;

	width = Datas::BOSS1_WIDTH;
	height = Datas::BOSS1_HEIGHT;

	isKnockBack = false;
	knockBackVel = { 0.0f,0.0f };

	elapsedTime = 0.0f;
	lastActionTime = 0.0f;

	canMigration = false;
	migrationTime = 120.0f;

	moveTheta = 0.0f;

	attack1Flag = false;
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

	attack1_1Flag = false;

	attack1_2Flag = false;

	thunder1Flag = false;

	thunder1_1Flag = false;

	isFloating = false;

	anim = 0.0f;
}

void Boss::Update()
{
	// 移行可能か計算
	Migration();

	// アクション管理タイムライン
	TimeLine();

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
		Novice::ScreenPrintf(0, 0, "BOSS_POS_X:%.1f", position.x);
		Novice::ScreenPrintf(200, 0, "BOSS_POS_Y:%.1f", position.y);
	}
}

void Boss::Draw()
{
	Novice::SetBlendMode(kBlendModeAdd);
	getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f},width,height }, Datas::BOSS1_VINNET_TEX);
	Novice::SetBlendMode(kBlendModeNormal);
	getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f},width,height }, Datas::BOSS1_TEX,
		static_cast<int>(anim) % Datas::BOSS1_ANIM_MAX_X, anim < Datas::BOSS1_ANIM_MAX_X ? 0 : 1);
}

void Boss::Collision()
{
	PtoBCollision();
}

void Boss::PtoBCollision()
{
	if (!isFloating) {// 浮いてないなら
		Vector2D center = { Datas::PLAYER_WIDTH * 0.5f, Datas::PLAYER_HEIGHT * 0.5f };
		Vector2D p_pos = getPlayer().GetPosition() - center;
		if (getPlayer().GetIsDash()) {
			if (My::CollisonCircletoPoint(position, Datas::BOSS1_COL_WIDTH, Datas::BOSS1_COL_HEIGHT, p_pos)) {
				knockBackVel = (position - p_pos).Normalized() * Datas::GAUNTLET_KNOCKBACK_POWER;
				isKnockBack = true;
				Vector2D temp = { (p_pos - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER };
				getPlayer().SetKnockBack(temp);
				getPlayer().SetMove();
				EffectManager::MakeNewEffect(p_pos - (temp * 8.5f), kAtttack);
				getPlayer().AddCharge(Datas::PLAYER_ATTACK_CHARGE);
				health -= Datas::PLAYER_ATTACK_DAMAGE;
			}
		}
		else {
			if (My::CollisonCircletoPoint(position, Datas::BOSS1_COL_WIDTH, Datas::BOSS1_COL_HEIGHT, p_pos)) {
				if (!getPlayer().GetIsInvincible()) {
					getPlayer().SetDamage(Datas::BOSS1_HIT_DAMAGE);
				}
				Vector2D temp = { (p_pos - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER };
				getPlayer().SetKnockBack((p_pos - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
				getPlayer().SetMove();
				EffectManager::MakeNewEffect(p_pos - (temp * 2.0f), kHit);
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
		homePos = position;
		moveTheta = 0.0f;
	}
}

void Boss::TimeLine()
{
	if (canMigration) {
		if ((position - getPlayer().GetCenterPosition()).Length() < Datas::BOSS_TIMELINE_DISTANCE_1) {
			switch (My::Random(1, 5))
			{
			case 1:
				SetNextAction(kAttack1);
				break;
			case 2:
				SetNextAction(kAttack1_1);
				break;
			case 3:
				SetNextAction(kAttack1_2);
				break;
			case 4:
				SetNextAction(kAttack1_1);
				break;
			case 5:
			default:
				SetNextAction(kAttack1_2);
				break;
			}
		}
		else if ((position - getPlayer().GetCenterPosition()).Length() < Datas::BOSS_TIMELINE_DISTANCE_2) {
			switch (My::Random(1, 5))
			{
			case 1:
				SetNextAction(kAttack1);
				break;
			case 2:
				SetNextAction(kThunder1);
				break;
			case 3:
				SetNextAction(kAttack1);
				break;
			case 4:
				SetNextAction(kThunder1);
				break;
			case 5:
			default:
				SetNextAction(None);
				break;
			}
		}
		else {
			switch (My::Random(1, 5))
			{
			case 1:
				SetNextAction(kThunder1);
				break;
			case 2:
				SetNextAction(kThunder1_1);
				break;
			case 3:
				SetNextAction(kThunder1);
				break;
			case 4:
				SetNextAction(kThunder1_1);
				break;
			case 5:
			default:
				SetNextAction(None);
				break;
			}
		}
	}
}

void Boss::Migration()
{
	migrationTime -= Delta::getTotalDelta();

	if (migrationTime < 0.0f) {
		migrationTime = 0.0f;
		canMigration = true;
	}
	if (canMigration) {
		migrationTime = 0.0f;
	}
}

void Boss::SetNextAction(BossAction bossaction)
{
	switch (bossaction)
	{
	case Boss::kAttack1:
		if (!attack1Flag) {
			attack1Flag = true;
			attack1Elapsed = 0.0f;
			attack1bullet1Time = -1.0f;
			attack1bullet2Time = 0.0f;
			attack1bullet3Time = 0.0f;
			attack1bullet4Time = 0.0f;
			attack1bullet5Time = 0.0f;
			attack1bullet6Time = 0.0f;
			attack1bullet7Time = 0.0f;
			attack1bullet8Time = 0.0f;
			attack1bullet9Time = 0.0f;
			attack1bullet10Time = 0.0f;
			canMigration = false;
			migrationTime = Datas::BOSS_ATTACK1_OFFSET;
		}
		break;
	case Boss::kAttack1_1:
		if (!attack1_1Flag) {
			attack1_1Flag = true;
			attack1Elapsed = 0.0f;
			attack1bullet1Time = -1.0f;
			attack1bullet2Time = 0.0f;
			attack1bullet3Time = 0.0f;
			attack1bullet4Time = 0.0f;
			attack1bullet5Time = 0.0f;
			attack1bullet6Time = 0.0f;
			attack1bullet7Time = 0.0f;
			attack1bullet8Time = 0.0f;
			attack1bullet9Time = 0.0f;
			attack1bullet10Time = 0.0f;
			canMigration = false;
			migrationTime = Datas::BOSS_ATTACK1_OFFSET;
		}
		break;
	case Boss::kAttack1_2:
		if (!attack1_2Flag) {
			attack1_2Flag = true;
			attack1Elapsed = 0.0f;
			attack1bullet1Time = -1.0f;
			attack1bullet2Time = 0.0f;
			attack1bullet3Time = 0.0f;
			attack1bullet4Time = 0.0f;
			attack1bullet5Time = 0.0f;
			attack1bullet6Time = 0.0f;
			attack1bullet7Time = 0.0f;
			attack1bullet8Time = 0.0f;
			attack1bullet9Time = 0.0f;
			attack1bullet10Time = 0.0f;
			canMigration = false;
			migrationTime = Datas::BOSS_ATTACK1_OFFSET;
		}
		break;
	case Boss::kThunder1:
		if (!thunder1Flag) {
			thunder1Flag = true;;
			thunder1num = -1;
			canMigration = false;
			migrationTime = Datas::BOSS_THUNDER1_OFFSET;
		}
		break;
	case Boss::kThunder1_1:
		if (!thunder1_1Flag) {
			thunder1_1Flag = true;
			thunder1num = -1;
			canMigration = false;
			migrationTime = Datas::BOSS_THUNDER1_OFFSET;
		}
		break;
	case Boss::None:
	default:
		canMigration = false;
		migrationTime = Datas::BOSS_ATTACK1_OFFSET;
		break;
	}
}

void Boss::Action()
{
	if (!isKnockBack) {
		Move1();
	}

	if (attack1Flag) {
		Attack1();
	}
	if (attack1_1Flag) {
		Attack1_1();
	}
	if (attack1_2Flag) {
		Attack1_2();
	}
	if (thunder1Flag) {
		Thunder1();
	}
	if (thunder1_1Flag) {
		Thunder1_1();
	}
}

void Boss::Move1()
{
	position.y = homePos.y + sinf(moveTheta) * Datas::BOSS1_MOVE_AMP;
	moveTheta += Datas::BOSS1_MOVE_SPD * Delta::getTotalDelta();

	if (2.0f * M_PI < moveTheta) {
		moveTheta -= static_cast<float>(2.0f * M_PI);
	}
}

void Boss::Attack1()
{
	attack1Elapsed += Delta::getTotalDelta();
	if (attack1bullet1Time == -1.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
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
		attack1Flag = false;
	}
}

void Boss::Attack1_1()
{
	attack1Elapsed += Delta::getTotalDelta();
	if (attack1bullet1Time == -1.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet1Time = attack1Elapsed;
	}
	if (attack1bullet2Time == 0.0f && attack1Elapsed - attack1bullet1Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet1Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_1);
		attack1bullet2Time = attack1Elapsed;
	}
	if (attack1bullet3Time == 0.0f && attack1Elapsed - attack1bullet2Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet2Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_2);
		attack1bullet3Time = attack1Elapsed;
	}
	if (attack1bullet4Time == 0.0f && attack1Elapsed - attack1bullet3Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet3Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_3);
		attack1bullet4Time = attack1Elapsed;
	}
	if (attack1bullet5Time == 0.0f && attack1Elapsed - attack1bullet4Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet4Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_4);
		attack1bullet5Time = attack1Elapsed;
	}
	if (attack1bullet6Time == 0.0f && attack1Elapsed - attack1bullet5Time > Datas::BOSS_ATTACK1_WAVE_DIS && attack1bullet5Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_5);
		attack1bullet6Time = attack1Elapsed;
	}
	if (attack1bullet7Time == 0.0f && attack1Elapsed - attack1bullet6Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet6Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_6);
		attack1bullet7Time = attack1Elapsed;
	}
	if (attack1bullet8Time == 0.0f && attack1Elapsed - attack1bullet7Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet7Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_7);
		attack1bullet8Time = attack1Elapsed;
	}
	if (attack1bullet9Time == 0.0f && attack1Elapsed - attack1bullet8Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet8Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_8);
		attack1bullet9Time = attack1Elapsed;
	}
	if (attack1bullet10Time == 0.0f && attack1Elapsed - attack1bullet9Time > Datas::BOSS_ATTACK1_SHOOT_DIS && attack1bullet9Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_9);
		attack1bullet10Time = attack1Elapsed;
		attack1_1Flag = false;
	}
}

void Boss::Attack1_2()
{
	attack1Elapsed += Delta::getTotalDelta();
	if (attack1bullet1Time == -1.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack1_9);
		BulletManager::MakeNewBullet(position, kBossAttack1_8);
		BulletManager::MakeNewBullet(position, kBossAttack1_7);
		BulletManager::MakeNewBullet(position, kBossAttack1_6);
		BulletManager::MakeNewBullet(position, kBossAttack1_5);
		BulletManager::MakeNewBullet(position, kBossAttack1_4);
		BulletManager::MakeNewBullet(position, kBossAttack1_3);
		BulletManager::MakeNewBullet(position, kBossAttack1_2);
		BulletManager::MakeNewBullet(position, kBossAttack1_1);
		BulletManager::MakeNewBullet(position, kBossAttack1);
		attack1bullet1Time = attack1Elapsed;
		attack1_2Flag = false;
	}
}

void Boss::Thunder1()
{
	if (thunder1num == -1) {
		thunder1num = EffectManager::MakeNewEffect(position, kPrePreThunder);
	}
	if (EffectManager::GetIsEnd(thunder1num)) {
		thunder1Flag = false;
	}
}

void Boss::Thunder1_1()
{
	if (thunder1num == -1) {
		thunder1num = EffectManager::MakeNewEffect(position, kPrePreThunder);
	}
	if (EffectManager::GetIsEnd(thunder1num)) {
		thunder1_1Flag = false;
	}
}

void Boss::Animation()
{
	anim += Delta::getTotalDelta() / Datas::BOSS1_ANIM_SPD;
	if (Datas::BOSS1_ANIM_MAX_X * Datas::BOSS1_ANIM_MAX_Y < anim) {
		anim = 0.0f;
	}
}
