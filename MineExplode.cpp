#include "MineExplode.h"
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

MineExplode::MineExplode(Game& game, Vector2D pos) : BaseBullet(game, pos)
{
	BaseInit(pos);
}

MineExplode::~MineExplode()
{
}

void MineExplode::Init()
{
	elapsedFrame = 0.0f;
}

void MineExplode::Update()
{
	if (elapsedFrame < 100.0f) {// 予兆
		
	}
	else {
		// 当たり判定
		if (!pGame.getPlayer().GetIsInvincible()) {
			if ((position.x - Datas::MINE_EXPLODE_SIZE * 0.5f < pGame.getPlayer().GetPosition().x && pGame.getPlayer().GetPosition().x < position.x - Datas::MINE_EXPLODE_SIZE * 0.5f)
				||(position.y - Datas::MINE_EXPLODE_SIZE * 0.5f < pGame.getPlayer().GetPosition().y && pGame.getPlayer().GetPosition().y < position.y - Datas::MINE_EXPLODE_SIZE * 0.5f)) {
				pGame.getPlayer().SetDamage(Datas::MINE_EXPLODE_DAMAGE);
				pGame.getPlayer().SetMove();
				pGame.getPlayer().SetKnockBack((pGame.getPlayer().GetPosition() - position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
				// 音
				// ばくはつエフェクト依頼
			}
		}
	}

	if (elapsedFrame > 150.0f) {
		isEnd = true;
	}
}

void MineExplode::Draw()
{
	if (elapsedFrame < 100.0f) {// 予兆
		getCameraMain().DrawQuad({ {-Datas::STAGE1_WIDTH,position.y - Datas::MINE_EXPLODE_SIZE * 0.5f},Datas::STAGE1_WIDTH * 2.0f ,Datas::MINE_EXPLODE_SIZE }, Datas::PRE_RUSH_TEX);
		getCameraMain().DrawQuad({ {position.x - Datas::MINE_EXPLODE_SIZE * 0.5f,-Datas::STAGE1_HEIGHT},Datas::MINE_EXPLODE_SIZE,Datas::STAGE1_HEIGHT * 2.0f }, Datas::PRE_RUSH_TEX);
	}
	else {
		//　爆発エフェクト
	}
}
