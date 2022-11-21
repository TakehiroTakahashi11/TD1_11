#include "BossAttack2.h"
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

BossAttack2::BossAttack2(Game& game, Vector2D pos) : BaseBullet(game, pos)
{
	BaseInit(pos);
}

BossAttack2::~BossAttack2()
{
}

void BossAttack2::Init()
{
	for (int i = 0; i < BossAttack2MaxNum; i++) {
		//弾が向かう方向
		Vector2D dir = position - pGame.getPlayer().GetPosition();
		switch (i)
		{
		case 1:
			dir = dir.Rotated(0.5f * M_PI);
			break;
		case 2:
			dir = dir.Rotated(M_PI);
			break;
		case 3:
			dir = dir.Rotated(1.5f * M_PI);
			break;
		case 0:
		default:
			break;
		}
		bossAttack2[i].theta = atan2f(-dir.y, -dir.x);

		//弾の位置、速度、サイズ初期化
		bossAttack2[i].velocity = { cosf(bossAttack2[i].theta), sinf(bossAttack2[i].theta) };
		bossAttack2[i].position = position + bossAttack2[i].velocity * Datas::BOSS_ATTACK1_DIS;
		bossAttack2[i].size = { Datas::BOSS_ATTACK1_SIZE, Datas::BOSS_ATTACK1_SIZE };


		//弾表示
		bossAttack2[i].isEnd = false;
	}

	// 音
}

void BossAttack2::Update()
{
	// 当たり判定用宣言
	Vector2D p_pos = pGame.getPlayer().GetPosition();
	Vector2D g_pos = pGame.getGauntlets().GetPosition();
	bool isDash = pGame.getPlayer().GetIsDash();
	bool isGuard = pGame.getPlayer().GetIsGuard();
	bool isInv = pGame.getPlayer().GetIsInvincible();

	// 弾検索
	for (int i = 0; i < BossAttack2MaxNum; i++) {
		if (bossAttack2[i].isEnd == false) {
			if (pGame.getMap().IsWall(bossAttack2[i].position, bossAttack2[i].size)) {// もし壁より外なら
				//エフェクト終了
				bossAttack2[i].isEnd = true;
				EffectManager::MakeNewEffect(bossAttack2[i].position, kBulletDeath);
			}

			// 移動処理
			bossAttack2[i].position += bossAttack2[i].velocity * Datas::BOSS_ATTACK2_SPEED * Delta::getTotalDelta();

			// 当たり判定
			if (!isInv) {
				Vector2D p = { 0.0f,Datas::PLAYER_WIDTH * 0.3f };

				if (!isGuard) {
					if (isDash) {
						if (Datas::PLAYER_HEIGHT * 0.3f + bossAttack2[i].size.x * 0.4f > (bossAttack2[i].position - (pGame.getPlayer().GetJustDodgePosition(0))).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack2[i].size.x * 0.4f > (bossAttack2[i].position - pGame.getPlayer().GetJustDodgePosition(1)).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack2[i].size.x * 0.4f > (bossAttack2[i].position - pGame.getPlayer().GetJustDodgePosition(2)).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack2[i].size.x * 0.4f > (bossAttack2[i].position - pGame.getPlayer().GetJustDodgePosition(3)).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack2[i].size.x * 0.4f > (bossAttack2[i].position - pGame.getPlayer().GetJustDodgePosition(4)).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack2[i].size.x * 0.4f > (bossAttack2[i].position - pGame.getPlayer().GetJustDodgePosition(5)).Length()) {
							pGame.getPlayer().SetIsJustDodge();
						}
					}
					else {
						if (Datas::PLAYER_HEIGHT * 0.2f + bossAttack2[i].size.x * 0.4f > (bossAttack2[i].position - (p_pos - p)).Length()) {
							Vector2D temp = pGame.getPlayer().GetPosition() - p - position;
							pGame.getPlayer().SetKnockBack(temp.Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
							pGame.getPlayer().SetDamage(Datas::BOSS_ATTACK1_DAMAGE);
						}
					}
				}
				else {
					if (Datas::PLAYER_HEIGHT * 0.2f + bossAttack2[i].size.x * 0.5f > (bossAttack2[i].position - p_pos).Length()) {
						if (0 > bossAttack2[i].velocity.Dot(pGame.getPlayer().GetDirection())) {// 
							// 吸収
							pGame.getPlayer().SetGuardDis(Datas::BOSS_ATTACK1_DAMAGE);
							bossAttack2[i].isEnd = true;
							EffectManager::MakeNewEffect(bossAttack2[i].position, kBulletDeath);
						}
						else {
							pGame.getPlayer().SetDamage(Datas::BOSS_ATTACK1_DAMAGE);
						}
					}
				}
			}
		}

	}

	// 終了処理
	if (endCheck()) {
		isEnd = true;
	}
}

void BossAttack2::Draw()
{
	Novice::SetBlendMode(kBlendModeAdd);
	for (int i = 0; i < BossAttack2MaxNum; i++) {
		if (!bossAttack2[i].isEnd) {
			getCameraMain().DrawQuad({ {bossAttack2[i].position.x - bossAttack2[i].size.x * 0.5f,bossAttack2[i].position.y - bossAttack2[i].size.y * 0.5f},
				bossAttack2[i].size.x,bossAttack2[i].size.y }, Datas::BOSS_ATTACK1_TEX);
		}
	}
	Novice::SetBlendMode(kBlendModeNormal);
}

bool BossAttack2::endCheck()
{
	for (int i = 0; i < BossAttack2MaxNum; i++) {
		if (!bossAttack2[i].isEnd) {// 終わっていないなら抜ける
			return false;
		}
	}
	return true;
}
