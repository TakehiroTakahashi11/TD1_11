#include "Boss.h"
#include "Datas.h"
#include "Player.h"
#include "Camera.h"
#include "MyFunc.h"
#include "EffectManager.h"
#include <Novice.h>

Boss::Boss(Game& pGame) : Obj(pGame)
{
	Init();
}

void Boss::Init()
{
	position = { Datas::BOSS1_POS_X,Datas::BOSS1_POS_Y };
	width = Datas::BOSS1_WIDTH;
	height = Datas::BOSS1_HEIGHT;
	isFloating = false;
}

void Boss::Update()
{
	// “–‚½‚è”»’è
	Collision();
}

void Boss::Draw()
{
	getCameraMain().DrawQuad({ {position.x - width * 0.5f,position.y - height * 0.5f},width,height }, Datas::BOSS1_TEX);
}

void Boss::Collision()
{
	if (!getPlayer().GetIsInvincible() && !isFloating) {// –³“G‚¶‚á‚È‚¢‚È‚ç
		Vector2D center = { Datas::PLAYER_WIDTH * 0.5f, Datas::PLAYER_HEIGHT * 0.5f };
		Vector2D p_pos = getPlayer().GetPosition() - center;
		if (My::CollisonCircletoPoint(position, Datas::BOSS1_COL_WIDTH, Datas::BOSS1_COL_HEIGHT, p_pos)) {
			getPlayer().SetDamage(Datas::BOSS1_HIT_DAMAGE);
			getPlayer().SetKnockBack((p_pos - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
			EffectManager::MakeNewEffect(p_pos, Hit);
		}
	}
}
