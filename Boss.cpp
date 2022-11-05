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

	nowAction = None;
	nextAction = kMove;

	beforePos = { 0.0f,0.0f };
	moveTheta = 0.0f;

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
		Novice::ScreenPrintf(300, 40, "position:%.1f", position.x);
		Novice::ScreenPrintf(450, 40, "position:%.1f", position.y);
		Novice::ScreenPrintf(300, 60, " knockBackvel:%.1f", knockBackVel.x);
		Novice::ScreenPrintf(450, 60, " knockBackvel:%.1f", knockBackVel.y);
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
	}
	else {
		isKnockBack = false;
		beforePos = position;
	}
}

void Boss::SetNextAction(BossAction bossaction)
{
	nextAction = bossaction;
}

void Boss::Action()
{
	// 辻褄合わせ移行処理等
	switch (nextAction)
	{
	case Boss::kMove:
		beforePos = position;
		moveTheta = 0.0f;
		break;
	case Boss::kAttack1:
		BulletManager::MakeNewBullet(position,kBossAttack1);
		break;
	case Boss::None:
	default:
		break;
	}

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

	if (nextAction != None) {// 予約アクションがあるなら
		nowAction = nextAction;
		nextAction = None;
	}
}

void Boss::Move()
{
	if (!isKnockBack) {
		moveTheta += Datas::BOSS1_MOVE_SPD;
		if (360.0f < moveTheta) {
			moveTheta -= 360.0f;
		}
		position.y = beforePos.y + sinf(moveTheta) * Datas::BOSS1_MOVE_AMP;
	}
}

void Boss::Attack1()
{
	SetNextAction(kMove);
}


void Boss::Animation()
{
	anim += Delta::getTotalDelta() / Datas::BOSS1_ANIM_SPD;
	if (Datas::BOSS1_ANIM_MAX_X * Datas::BOSS1_ANIM_MAX_Y < anim) {
		anim = 0.0f;
	}
}
