#include "Mine.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Delta.h"
#include "Player.h"
#include "Gauntlets.h"
#include "Map.h"
#include <Novice.h>
#include "EffectManager.h"
#include "BulletManager.h"

Mine::Mine(Game& game, Vector2D pos) : BaseBullet(game, pos)
{
	BaseInit(pos);
}

Mine::~Mine()
{
}

void Mine::Init()
{
	isStartAnim = true;
	anim = 0.0f;

	col_rad = Datas::PLAYER_WIDTH * 0.3 + Datas::MINE_SIZE * 0.5f;
}

void Mine::Update()
{
	anim += Delta::getTotalDelta();

	if (isStartAnim) {// 生成アニメーション
		if (anim > 12.0f) {
			isStartAnim = false;
		}
	}
	else {
		// 当たり判定
		if (!pGame.getPlayer().GetIsInvincible()) {
			if ((pGame.getPlayer().GetPosition() - position).Length() < col_rad) {
				pGame.getPlayer().SetDamage(Datas::MINE_DAMAGE);
				pGame.getPlayer().SetMove();
				pGame.getPlayer().SetKnockBack((pGame.getPlayer().GetPosition() - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
				// 音
				// ばくはつエフェクト依頼
				BulletManager::MakeNewBullet(position, kBossAttackMineExplode1);
				isEnd = true;
			}
		}

		// 待機アニメーション
		if (anim > 36.0f) {
			anim = 12.0f;
		}
	}

	if (elapsedFrame > 500.0f) {
		// 音
		// ばくはつエフェクト
		BulletManager::MakeNewBullet(position, kBossAttackMineExplode1);
		isEnd = true;
	}
}

void Mine::Draw()
{
	pGame.getCameraMain().DrawQuad({ {position.x - Datas::MINE_SIZE * 0.5f,position.y - Datas::MINE_SIZE * 0.5f},Datas::MINE_SIZE,Datas::MINE_SIZE }, Datas::MINE_TEX);
}
