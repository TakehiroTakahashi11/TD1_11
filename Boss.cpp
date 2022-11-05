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

	thunder1Elapsed = 0.0f;
	thunder1pos = { 0.0f ,0.0f };
	thunder2pos = { 0.0f ,0.0f };
	thunder3pos = { 0.0f ,0.0f };
	prethunder1_num = -1;
	prethunder2_num = -1;
	prethunder3_num = -1;
	thunder1_created = false;
	thunder2_created = false;
	thunder3_created = false;

	isFloating = false;

	anim = 0.0f;
}

void Boss::Update()
{
	if (Datas::DEBUG_MODE) {
		if (Controller::IsTriggerButton(0,Controller::bB) || Key::IsTrigger(DIK_J)) {
			SetNextAction(kAttack1);
		}
		if (Controller::IsTriggerButton(0, Controller::bA) || Key::IsTrigger(DIK_K)) {
			SetNextAction(kThunder1);
		}
	}

	// �A�N�V����
	Action();

	// �����蔻��
	Collision();

	// �m�b�N�o�b�N
	if (isKnockBack) {
		KnockBack();
	}

	// �A�j���[�V����
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
	if (!isFloating) {// �����ĂȂ��Ȃ�
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

	// ���s
	switch (nowAction)
	{
	case Boss::kMove:
		Move();
		break;
	case Boss::kAttack1:
		Attack1();
		break;
	case Boss::kThunder1:
		Thunder1();
		break;
	case Boss::None:
	default:
		break;
	}

	// �\��A�N�V����������Ȃ�A�ڍs�\�܂ł̔��菈��
	if (nextAction != None) {
		switch (nowAction)
		{
		case Boss::kMove:
			MoveMig();
			break;
		case Boss::kAttack1:
			Attack1Mig();
			break;
		case Boss::kThunder1:
			Thunder1Mig();
			break;
		case Boss::None:
		default:
			canMigration = true;
			break;
		}
	}

	// �ڍs�\�Ȃ�ڍs�����݂̂̏���
	if (nextAction != None && canMigration) {
		Vector2D wid = { Datas::PLAYER_WIDTH * 0.5f,Datas::PLAYER_WIDTH * 0.9f };
		switch (nextAction)
		{
		case Boss::kMove:
			break;
		case Boss::kAttack1:
			break;
		case Boss::kThunder1:
			thunder1pos = getPlayer().GetPosition() - wid;
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
			moveTheta -= static_cast<float>(2.0f * M_PI);
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

void Boss::Thunder1()
{
	thunder1Elapsed += Delta::getTotalDelta();

	if (prethunder1_num == -1) {
		prethunder1_num = EffectManager::MakeNewEffect(thunder1pos, kPreThunder);
	}
	if (!thunder1_created && EffectManager::GetIsEnd(prethunder1_num)) {
		thunder1_created = true;
		EffectManager::MakeNewEffect(thunder1pos, kThunder);
	}

	if (prethunder2_num == -1 && Datas::BOSS_THUNDER1_TIME_DIS < thunder1Elapsed) {
		Vector2D wid = { Datas::PLAYER_WIDTH * 0.5f,Datas::PLAYER_WIDTH * 0.9f };
		thunder2pos = getPlayer().GetPosition() - wid;
		prethunder2_num = EffectManager::MakeNewEffect(thunder2pos, kPreThunder);
	}
	if (!thunder2_created && EffectManager::GetIsEnd(prethunder2_num)) {
		thunder2_created = true;
		EffectManager::MakeNewEffect(thunder2pos, kThunder);
	}

	if (prethunder3_num == -1 && Datas::BOSS_THUNDER1_TIME_DIS * 2 < thunder1Elapsed) {
		Vector2D wid = { Datas::PLAYER_WIDTH * 0.5f,Datas::PLAYER_WIDTH * 0.9f };
		thunder3pos = getPlayer().GetPosition() - wid;
		prethunder3_num = EffectManager::MakeNewEffect(thunder3pos, kPreThunder);
	}
	if (!thunder3_created && EffectManager::GetIsEnd(prethunder3_num)) {
		thunder3_created = true;
		EffectManager::MakeNewEffect(thunder3pos, kThunder);
		SetNextAction(kMove);
	}

}

void Boss::Thunder1Mig()
{
	thunder1Elapsed = 0.0f;
	thunder1pos = { 0.0f ,0.0f };
	thunder2pos = { 0.0f ,0.0f };
	thunder3pos = { 0.0f ,0.0f };
	prethunder1_num = -1;
	prethunder2_num = -1;
	prethunder3_num = -1;
	thunder1_created = false;
	thunder2_created = false;
	thunder3_created = false;
	canMigration = true;
}


void Boss::Animation()
{
	anim += Delta::getTotalDelta() / Datas::BOSS1_ANIM_SPD;
	if (Datas::BOSS1_ANIM_MAX_X * Datas::BOSS1_ANIM_MAX_Y < anim) {
		anim = 0.0f;
	}
}
