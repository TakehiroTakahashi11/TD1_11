#include "Enemy1.h"
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

Enemy1::Enemy1(Game& game, Vector2D pos) : BaseBullet(game, pos)
{
	BaseInit(pos);
}

Enemy1::~Enemy1()
{
}

void Enemy1::Init()
{
	isStartAnim = true;
	col_rad = Datas::PLAYER_WIDTH * 0.4f + Datas::ENEMY1_SIZE * 0.5f;
}

void Enemy1::Update()
{
	for (int i = 0; i < Enemy1MaxNum; i++) {
		enemy1Struct[i].anim += Delta::getTotalDelta();

		/*if (isStartAnim) {
			enemy1Struct[i].position +
		}
		else {

		}*/

		// 当たり判定
		if (!pGame.getPlayer().GetIsInvincible()) {
			if ((pGame.getPlayer().GetPosition() - enemy1Struct[i].position).Length() < col_rad && !pGame.getPlayer().GetIsInvincible()) {
				if (pGame.getPlayer().GetIsDash()) {

					// 音
					// ばくはつエフェクト依頼
					isEnd = true;
				}
				else {
					pGame.getPlayer().SetDamage(Datas::ENEMY1_DAMAGE);
					pGame.getPlayer().SetMove();
					pGame.getPlayer().SetKnockBack((pGame.getPlayer().GetPosition() - enemy1Struct[i].position).Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
				}
			}
		}

		// 待機アニメーション
		if (enemy1Struct[i].anim > 36.0f) {
			enemy1Struct[i].anim = 12.0f;
		}
	}
}

void Enemy1::Draw()
{
	for (int i = 0; i < Enemy1MaxNum; i++) {
		pGame.getCameraMain().DrawQuad({ {position.x - Datas::ENEMY1_SIZE * 0.5f,position.y - Datas::ENEMY1_SIZE * 0.5f},Datas::ENEMY1_SIZE,Datas::ENEMY1_SIZE }, Datas::ENEMY1_TEX);
	}
}
