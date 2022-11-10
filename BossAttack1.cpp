#include "BossAttack1.h"
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

BossAttack1::BossAttack1(Game& game, Vector2D pos, int n) : BaseBullet(game, pos)
{
	t = n;
	BaseInit(pos);
}

BossAttack1::~BossAttack1()
{
}

void BossAttack1::Init()
{
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		//弾が向かう方向
		switch (t)
		{
		case 0:
			bossAttack1[i].theta = static_cast<float>(i * (360 / BossAttack1MaxNum) * (M_PI / 180.0f));
			break;
		case 1:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		case 2:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		case 3:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		case 4:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		case 5:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		case 6:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		case 7:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		case 8:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		case 9:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		case 10:
			bossAttack1[i].theta = static_cast<float>((i * (360 / BossAttack1MaxNum) + 3.0f * t) * (M_PI / 180.0f));
			break;
		default:
			break;
		}

		//弾の位置、速度、サイズ初期化
		bossAttack1[i].velocity = { cosf(bossAttack1[i].theta), sinf(bossAttack1[i].theta) };
		bossAttack1[i].position = position + bossAttack1[i].velocity * Datas::BOSS_ATTACK1_DIS;
		bossAttack1[i].size = { Datas::BOSS_ATTACK1_SIZE, Datas::BOSS_ATTACK1_SIZE };


		//弾表示
		bossAttack1[i].isEnd = false;
	}

	// 音
}

void BossAttack1::Update()
{
	// 当たり判定用宣言
	Vector2D p_pos = pGame.getPlayer().GetPosition();
	Vector2D g_pos = pGame.getGauntlets().GetPosition();
	bool isDash = pGame.getPlayer().GetIsDash();
	bool isGuard = pGame.getPlayer().GetIsGuard();
	bool isInv = pGame.getPlayer().GetIsInvincible();

	// 弾検索
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		if (bossAttack1[i].isEnd == false) {
			if (pGame.getMap().IsWall(bossAttack1[i].position, bossAttack1[i].size)) {// もし壁より外なら
				//エフェクト終了
				bossAttack1[i].isEnd = true;
				EffectManager::MakeNewEffect(bossAttack1[i].position, kBulletDeath);
			}

			// 移動処理
			bossAttack1[i].position += bossAttack1[i].velocity * Datas::BOSS_ATTACK1_SPEED * Delta::getTotalDelta();

			// 当たり判定
			if (!isInv) {
				Vector2D p = { 0.0f,Datas::PLAYER_WIDTH * 0.3f };

				if (!isGuard) {
					if (isDash) {
						if (Datas::PLAYER_HEIGHT * 0.3f + bossAttack1[i].size.x * 0.4f > (bossAttack1[i].position - (pGame.getPlayer().GetJustDodgePosition(0))).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack1[i].size.x * 0.4f > (bossAttack1[i].position - pGame.getPlayer().GetJustDodgePosition(1)).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack1[i].size.x * 0.4f > (bossAttack1[i].position - pGame.getPlayer().GetJustDodgePosition(2)).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack1[i].size.x * 0.4f > (bossAttack1[i].position - pGame.getPlayer().GetJustDodgePosition(3)).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack1[i].size.x * 0.4f > (bossAttack1[i].position - pGame.getPlayer().GetJustDodgePosition(4)).Length()
							|| Datas::PLAYER_HEIGHT * 0.3f + bossAttack1[i].size.x * 0.4f > (bossAttack1[i].position - pGame.getPlayer().GetJustDodgePosition(5)).Length()) {
							pGame.getPlayer().SetIsJustDodge();
						}
					}
					else {
						if (Datas::PLAYER_HEIGHT * 0.2f + bossAttack1[i].size.x * 0.4f > (bossAttack1[i].position - (p_pos - p)).Length()) {
							Vector2D temp = pGame.getPlayer().GetPosition() - p - position;
							pGame.getPlayer().SetKnockBack(temp.Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
							pGame.getPlayer().SetDamage(Datas::BOSS_ATTACK1_DAMAGE);
						}
					}
				}
				else {
					if (Datas::PLAYER_HEIGHT * 0.2f + bossAttack1[i].size.x * 0.5f > (bossAttack1[i].position - p_pos).Length()) {
						//if () {// 
						//	// 吸収
						//	pGame.getPlayer().SetGuardDis(Datas::BOSS_ATTACK1_DAMAGE);
						//	//
						//	bossAttack1[i].isEnd = true;
						//	EffectManager::MakeNewEffect(bossAttack1[i].position, kBulletDeath);
						//}
						//else if () {
						//	pGame.getPlayer().SetDamage(Datas::BOSS_ATTACK1_DAMAGE);
						//}
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

void BossAttack1::Draw()
{
	Novice::SetBlendMode(kBlendModeAdd);
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		if (!bossAttack1[i].isEnd) {
			getCameraMain().DrawQuad({ {bossAttack1[i].position.x - bossAttack1[i].size.x * 0.5f,bossAttack1[i].position.y - bossAttack1[i].size.y * 0.5f},
				bossAttack1[i].size.x,bossAttack1[i].size.y }, Datas::BOSS_ATTACK1_TEX);
		}
	}
	Novice::SetBlendMode(kBlendModeNormal);
}

bool BossAttack1::endCheck()
{
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		if (!bossAttack1[i].isEnd) {// 終わっていないなら抜ける
			return false;
		}
	}
	return true;
}
