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
#include "Map.h"
#include "Game.h"

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
	beforeAction = None;

	moveTheta = 0.0f;
	dashCoolTime = 0.0f;

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

	attack2Flag = false;
	attack2Elapsed = 0.0f;
	attack2bullet1Time = 0.0f;
	attack2bullet2Time = 0.0f;
	attack2bullet3Time = 0.0f;
	attack2bullet4Time = 0.0f;
	attack2bullet5Time = 0.0f;
	attack2bullet6Time = 0.0f;
	attack2bullet7Time = 0.0f;
	attack2bullet8Time = 0.0f;
	attack2bullet9Time = 0.0f;
	attack2bullet10Time = 0.0f;

	rush1Flag = false;
	rush1Elapsed = 0.0f;
	rush_ef_num = -1;

	rush1_2Flag = false;

	rush2Flag = false;
	rush2Elapsed = 0.0f;
	rush2_ef_num = -1;

	thunder1Flag = false;

	thunder1_1Flag = false;

	mine1Flag = false;
	mine1Elapsed = 0.0f;
	mine1 = -1;
	mine2 = -1;
	mine3 = -1;

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

	if (0 < tremblingFrame) {
		tremblingFrame -= Delta::getDeltaTime();
		trembPos.x = My::RandomF(-45.0f, 45.0f, 1);
		trembPos.y = My::RandomF(-45.0f, 45.0f, 1);
	}
	else {
		tremblingFrame = 0.0f;
		trembPos = { 0.0f,0.0f };
	}

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
	getCameraMain().DrawQuad({ {position.x - width * 0.5f + trembPos.x,position.y - height * 0.5f + trembPos.y},width,height }, Datas::BOSS1_TEX,
		static_cast<int>(anim) % Datas::BOSS1_ANIM_MAX_X, anim < Datas::BOSS1_ANIM_MAX_X ? 0 : 1);
}

void Boss::Collision()
{
	PtoBCollision();
}

void Boss::PtoBCollision()
{
	Vector2D p_pos = getPlayer().GetPosition();
	if (getPlayer().GetIsChargeAttack()) {
		if (My::CollisonCircletoPoint(position, Datas::BOSS1_COL_WIDTH, Datas::BOSS1_COL_HEIGHT, getGauntlets().GetPosition())) {
			knockBackVel = (position - p_pos).Normalized() * 300.0f;
			isKnockBack = true;
			Vector2D temp = { (p_pos - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER };
			getPlayer().SetKnockBack(temp);
			getPlayer().SetMove();
			getGauntlets().SetEndChargeAtk();
			EffectManager::MakeNewEffect(p_pos - (temp * 8.5f), kAtttack);
			getPlayer().AddCharge(Datas::PLAYER_ATTACK_CHARGE);
			health -= Datas::PLAYER_ATTACK_DAMAGE;

			tremblingFrame = Datas::BOSS1_ATTACK_HITSTOP;

			Delta::HitStop(Datas::BOSS1_ATTACK_HITSTOP);
			// 音
			Datas::PLAYER_PUNCH_SOUND.PlayOnce();
		}

	}
	else if (getPlayer().GetIsDash() && !getPlayer().GetIsGuardBreak()) {// 攻撃
		if (My::CollisonCircletoPoint(position, Datas::BOSS1_COL_WIDTH, Datas::BOSS1_COL_HEIGHT, p_pos + getPlayer().GetDirection() * 50.0f)) {
			Vector2D temp = { (p_pos - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER };
			getPlayer().SetKnockBack(temp);
			getPlayer().SetMove();
			EffectManager::MakeNewEffect(p_pos - (temp * 8.5f), kAtttack);
			getPlayer().AddCharge(Datas::PLAYER_ATTACK_CHARGE);
			health -= Datas::PLAYER_ATTACK_DAMAGE;

			tremblingFrame = Datas::BOSS1_ATTACK_HITSTOP;

			Delta::HitStop(Datas::BOSS1_ATTACK_HITSTOP);
			// 音
			Datas::PLAYER_PUNCH_SOUND.PlayOnce();
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

			// 音
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
		if (getGame().getMap().IsWall(position, { width,height })) {
			isKnockBack = false;
			Delta::HitStop(60.0f);
			getCameraMain().CameraShake({ 15.0f,15.0f }, { -0.5f,-0.5f }, 60.0f);
		}
	}
	else {
		isKnockBack = false;
		homePos = position;
		moveTheta = 0.0f;
	}
}

void Boss::TimeLine()
{
	// AI
	if (canMigration) {
		if (beforeAction == kAttack1_1 || beforeAction == kAttack1_2 || beforeAction == kAttack2) {
			if ((position - getPlayer().GetPosition()).Length() < Datas::BOSS_TIMELINE_DISTANCE_1) {// 距離が近いなら
				SetNextAction(None);
				return;
			}
		}

		if (beforeAction == kRush1 || beforeAction == kRush1_2) {
			switch (My::Random(0, 1))
			{
			case 0:
				SetNextAction(kThunder1);
				break;
			case 1:
				SetNextAction(None);
				break;
			default:
				break;
			}
			return;
		}

		if (beforeAction == kRush2) {
			SetNextAction(kRush1);
			return;
		}

		if (beforeAction == kThunder1) {
			if ((position - getPlayer().GetPosition()).Length() < Datas::BOSS_TIMELINE_DISTANCE_1) {// 距離が近いなら
				switch (My::Random(0, 1))
				{
				case 0:
					SetNextAction(kAttack1_2);
					break;
				case 1:
					SetNextAction(kRush2);
					break;
				default:
					break;
				}
				return;
			}
			else {
				switch (My::Random(0, 1))
				{
				case 0:
					SetNextAction(kAttack1_1);
					break;
				case 1:
					SetNextAction(kAttack2);
					break;
				default:
					break;
				}
				return;
			}
		}

		if (mine1 == -1) {
			SetNextAction(kMine1);
			return;
		}
		else {// 地雷が一つも無いなら
			if (BulletManager::GetIsEnd(mine1) &&
				BulletManager::GetIsEnd(mine2) &&
				BulletManager::GetIsEnd(mine3)) {
				SetNextAction(kMine1);
				return;
			}
		}

		if ((position - getPlayer().GetPosition()).Length() < Datas::BOSS_TIMELINE_DISTANCE_1) {// 距離が近いなら
			switch (My::Random(0, 6))
			{
			case 0:
				SetNextAction(kAttack1_2);
				break;
			case 1:
				SetNextAction(kAttack1_2);
				break;
			case 2:
				SetNextAction(kAttack1);
				break;
			case 3:
				SetNextAction(kAttack1_1);
				break;
			case 4:
				SetNextAction(kAttack2);
				break;
			case 5:
				SetNextAction(kRush1);
				break;
			default:
				SetNextAction(kRush1_2);
				break;
			}
			return;
		}
		else if ((position - getPlayer().GetPosition()).Length() < Datas::BOSS_TIMELINE_DISTANCE_2) {
			switch (My::Random(0, 6))
			{
			case 0:
				SetNextAction(kAttack1_2);
				break;
			case 1:
				SetNextAction(kAttack1);
				break;
			case 2:
				SetNextAction(kAttack2);
				break;
			case 3:
				SetNextAction(kRush1);
				break;
			case 4:
				SetNextAction(kRush2);
				break;
			case 5:
				SetNextAction(kThunder1);
				break;
			default:
				SetNextAction(kThunder1);
				break;
			}
			return;
		}
		else {
			switch (My::Random(0, 6))
			{
			case 0:
				SetNextAction(kAttack1_2);
				break;
			case 1:
				SetNextAction(kThunder1);
				break;
			case 2:
				SetNextAction(kAttack1_1);
				break;
			case 3:
				SetNextAction(kAttack1);
				break;
			case 4:
				SetNextAction(kRush1);
				break;
			case 5:
				SetNextAction(kRush2);
				break;
			default:
				SetNextAction(kRush2);
				break;
			}
			return;
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
	beforeAction = bossaction;

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
			migrationTime = Datas::BOSS_ATTACK1_2_OFFSET;
			EffectManager::MakeNewEffect(position, kPrePreBullet);
		}
		break;
	case Boss::kAttack2:
		if (!attack2Flag) {
			attack2Flag = true;
			attack2Elapsed = 0.0f;
			attack2bullet1Time = -1.0f;
			attack2bullet2Time = 0.0f;
			attack2bullet3Time = 0.0f;
			attack2bullet4Time = 0.0f;
			attack2bullet5Time = 0.0f;
			attack2bullet6Time = 0.0f;
			attack2bullet7Time = 0.0f;
			attack2bullet8Time = 0.0f;
			attack2bullet9Time = 0.0f;
			attack2bullet10Time = 0.0f;
			canMigration = false;
			migrationTime = Datas::BOSS_ATTACK2_OFFSET;
		}
		break;
	case Boss::kRush1:
		if (!rush1Flag) {
			rush1Flag = true;
			rush1Elapsed = 0.0f;
			rush_ef_num = -1;
			boss_rush.SetStart(position.y);
			boss_rush.SetEnd(1500);
			boss_rush.SetVel(0.02f);
			boss_rush.SetT(0.0f);
			boss_rush.SetMode(Easing::kOutQuad);
			canMigration = false;
			migrationTime = Datas::BOSS_RUSH1_OFFSET;
		}
		break;
	case Boss::kRush1_2:
		if (!rush1_2Flag) {
			rush1_2Flag = true;
			rush1Elapsed = 0.0f;
			rush_ef_num = -1;
			boss_rush.SetStart(position.y);
			boss_rush.SetEnd(1500);
			boss_rush.SetVel(0.007f);
			boss_rush.SetT(0.0f);
			boss_rush.SetMode(Easing::kInElastic);
			canMigration = false;
			migrationTime = Datas::BOSS_RUSH1_2_OFFSET;
		}
		break;
	case Boss::kRush2:
		if (!rush2Flag) {
			rush2Flag = true;
			rush2Elapsed = 0.0f;
			rush2_ef_num = -1;
			boss_rush2_X.SetStart(homePos.x);
			boss_rush2_Y.SetStart(homePos.y);
			boss_rush2_X.SetEnd(getPlayer().GetPosition().x);
			boss_rush2_Y.SetEnd(getPlayer().GetPosition().y);
			boss_rush2_X.SetVel(0.06f);
			boss_rush2_Y.SetVel(0.06f);
			boss_rush2_X.SetT(0.0f);
			boss_rush2_Y.SetT(0.0f);
			boss_rush2_X.SetMode(Easing::kInQuad);
			boss_rush2_Y.SetMode(Easing::kInQuad);
			canMigration = false;
			migrationTime = Datas::BOSS_RUSH2_OFFSET;
			tremblingFrame = 20.0f;
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
	case Boss::kMine1:
		if (!mine1Flag) {
			mine1Flag = true;
			canMigration = false;
			mine1Elapsed = 0.0f;
			migrationTime = Datas::BOSS_MINE1_OFFSET;
		}
		break;
	case Boss::None:
	default:
		canMigration = false;
		migrationTime = Datas::BOSS_ATTACK1_OFFSET * 0.25f;
		break;
	}
}

void Boss::Action()
{
	if (!isKnockBack && !rush1Flag && !rush1_2Flag && !rush2Flag) {
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
	if (attack2Flag) {
		Attack2();
	}
	if (rush1Flag) {
		Rush1();
	}
	if (rush1_2Flag) {
		Rush1_2();
	}
	if (rush2Flag) {
		Rush2();
	}
	if (thunder1Flag) {
		Thunder1();
	}
	if (thunder1_1Flag) {
		Thunder1_1();
	}
	if (mine1Flag) {
		Mine1();
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
	if (attack1bullet1Time == -1.0f && attack1Elapsed > 145.0f) {
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

void Boss::Attack2()
{
	attack2Elapsed += Delta::getTotalDelta();
	if (attack2bullet1Time == -1.0f && attack1Elapsed > 100.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet1Time = attack2Elapsed;
	}
	if (attack2bullet2Time == 0.0f && attack2Elapsed - attack2bullet1Time > Datas::BOSS_ATTACK2_SHOOT_DIS && attack2bullet1Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet2Time = attack2Elapsed;
	}
	if (attack2bullet3Time == 0.0f && attack2Elapsed - attack2bullet2Time > Datas::BOSS_ATTACK2_SHOOT_DIS && attack2bullet2Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet3Time = attack2Elapsed;
	}
	if (attack2bullet4Time == 0.0f && attack2Elapsed - attack2bullet3Time > Datas::BOSS_ATTACK2_SHOOT_DIS && attack2bullet3Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet4Time = attack2Elapsed;
	}
	if (attack2bullet5Time == 0.0f && attack2Elapsed - attack2bullet4Time > Datas::BOSS_ATTACK2_SHOOT_DIS && attack2bullet4Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet5Time = attack2Elapsed;
	}
	if (attack2bullet6Time == 0.0f && attack2Elapsed - attack2bullet5Time > Datas::BOSS_ATTACK2_SHOOT_DIS && attack2bullet5Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet6Time = attack2Elapsed;
	}
	if (attack2bullet7Time == 0.0f && attack2Elapsed - attack2bullet6Time > Datas::BOSS_ATTACK2_SHOOT_DIS && attack2bullet6Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet7Time = attack2Elapsed;
	}
	if (attack2bullet8Time == 0.0f && attack2Elapsed - attack2bullet7Time > Datas::BOSS_ATTACK2_SHOOT_DIS && attack2bullet7Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet8Time = attack2Elapsed;
	}
	if (attack2bullet9Time == 0.0f && attack2Elapsed - attack2bullet8Time > Datas::BOSS_ATTACK2_SHOOT_DIS && attack2bullet8Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet9Time = attack2Elapsed;
	}
	if (attack2bullet10Time == 0.0f && attack2Elapsed - attack2bullet9Time > Datas::BOSS_ATTACK2_SHOOT_DIS && attack2bullet9Time != 0.0f) {
		BulletManager::MakeNewBullet(position, kBossAttack2);
		attack2bullet10Time = attack2Elapsed;
		attack2Flag = false;
	}
}

void Boss::Rush1()
{
	rush1Elapsed += Delta::getTotalDelta();

	boss_rush.Move(Delta::getTotalDelta());

	position.y = boss_rush.p;

	if (boss_rush.IsEnd() == true && boss_rush.GetEnd() == 1500) {

		if (rush_ef_num == -1) {
			rush_ef_num = EffectManager::MakeNewEffect(getPlayer().GetPosition(), kPreRush);
		}
		if (rush1Elapsed >= 150) {
			EffectManager::SetEnd(rush_ef_num);
			rush_ef_num = EffectManager::MakeNewEffect(getPlayer().GetPosition(), kPrePreRush);
			position.x = getPlayer().GetPosition().x;
			boss_rush.SetStart(1500);
			boss_rush.SetEnd(-1500);
			boss_rush.SetVel(0.01f);
			boss_rush.SetMode(Easing::kInOutQuart);
		}
	}

	if (boss_rush.IsEnd() == true && boss_rush.GetEnd() == -1500) {

		boss_rush.SetStart(-1500);
		boss_rush.SetEnd(0.0f);
		boss_rush.SetVel(0.005f);
		boss_rush.SetMode(Easing::kInOutQuart);
		EffectManager::SetEnd(rush_ef_num);
	}

	if (boss_rush.IsEnd() == true && boss_rush.GetEnd() == 0.0f) {
		rush1Flag = false;
		rush1Elapsed = 0.0f;
		homePos = position;
	}
}

void Boss::Rush1_2()
{
	rush1Elapsed += Delta::getTotalDelta();

	boss_rush.Move(Delta::getTotalDelta());

	position.y = boss_rush.p;

	if (boss_rush.IsEnd() == true && boss_rush.GetEnd() == 1500) {
		if (rush1Elapsed >= 500) {
			position.x = My::RandomF(-Datas::STAGE1_WIDTH + width, Datas::STAGE1_WIDTH - width,1);
			if (rush_ef_num == -1) {
				rush_ef_num = EffectManager::MakeNewEffect(position, kPrePreRush);
			}
			boss_rush.SetStart(1500);
			boss_rush.SetEnd(-1500);
			boss_rush.SetVel(0.01f);
			boss_rush.SetMode(Easing::kInOutQuart);
		}
	}

	if (boss_rush.IsEnd() == true && boss_rush.GetEnd() == -1500) {

		boss_rush.SetStart(-1500);
		boss_rush.SetEnd(0.0f);
		boss_rush.SetVel(0.005f);
		boss_rush.SetMode(Easing::kInOutQuart);
		EffectManager::SetEnd(rush_ef_num);
	}

	if (boss_rush.IsEnd() == true && boss_rush.GetEnd() == 0.0f) {
		rush1_2Flag = false;
		rush1Elapsed = 0.0f;
		homePos = position;
	}
}

void Boss::Rush2()
{
	rush2Elapsed += Delta::getTotalDelta();
	rush2_ef_num = -1;

	if (rush2Elapsed > 40.0f) {
		boss_rush2_X.Move(Delta::getTotalDelta());
		boss_rush2_Y.Move(Delta::getTotalDelta());
	}

	position = { boss_rush2_X.p, boss_rush2_Y.p };

	if (boss_rush2_X.IsEnd() || boss_rush2_Y.IsEnd()) {
		homePos = position;
		rush2Flag = false;
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

void Boss::Mine1()
{
	mine1Elapsed += Delta::getTotalDelta();

	if (mine1Elapsed > 60.0f) {
		mine1 = BulletManager::MakeNewBullet({ My::RandomF(-800.0f,800.0f,1),My::RandomF(400.0f,900.0f,1) }, kBossAttackMine1);
		mine2 = BulletManager::MakeNewBullet({ My::RandomF(-100.0f,-900.0f,1),My::RandomF(400.0f,-900.0f,1) }, kBossAttackMine1);
		mine3 = BulletManager::MakeNewBullet({ My::RandomF(400.0f,900.0f,1),My::RandomF(400.0f,-900.0f,1) }, kBossAttackMine1);
		mine1Flag = false;
	}
}

void Boss::Animation()
{
	
}
