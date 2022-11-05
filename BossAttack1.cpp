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

BossAttack1::BossAttack1(Game& game, Vector2D pos) : BaseBullet(game, pos)
{
	BaseInit(pos);
}

BossAttack1::~BossAttack1()
{
}

void BossAttack1::Init()
{
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		//弾が向かう方向
		bossAttack1[i].theta = static_cast<float>(i * (360 / BossAttack1MaxNum) * (M_PI / 180.0f));

		//弾の位置、速度、サイズ初期化
		bossAttack1[i].velocity = { cosf(bossAttack1[i].theta), sinf(bossAttack1[i].theta) };
		bossAttack1[i].position = position + bossAttack1[i].velocity * Datas::BOSS_ATTACK1_DIS;
		bossAttack1[i].size = { Datas::BOSS_ATTACK1_SIZE, Datas::BOSS_ATTACK1_SIZE };


		//弾表示
		bossAttack1[i].isEnd = false;
	}
}

void BossAttack1::Update()
{
	// 当たり判定用宣言
	Vector2D p_pos = pGame.getPlayer().GetPosition();
	p_pos = { p_pos.x - Datas::PLAYER_HEIGHT * 0.5f,p_pos.y - Datas::PLAYER_HEIGHT * 0.5f };
	Vector2D g_pos = pGame.getGauntlets().GetPosition();
	bool isDash = pGame.getPlayer().GetIsDash();
	bool isGuard = pGame.getPlayer().GetIsGuard();

	// 弾検索
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		if (bossAttack1[i].isEnd == false) {
			if (bossAttack1[i].position.x - bossAttack1[i].size.x < -Datas::STAGE1_WIDTH
				|| Datas::STAGE1_WIDTH < bossAttack1[i].position.x + bossAttack1[i].size.x
				|| bossAttack1[i].position.y - bossAttack1[i].size.y < -Datas::STAGE1_HEIGHT
				|| Datas::STAGE1_HEIGHT < bossAttack1[i].position.y + bossAttack1[i].size.y) {// もし壁より外なら
				//エフェクト終了
				bossAttack1[i].isEnd = true;
			}

			// 移動処理
			bossAttack1[i].position += bossAttack1[i].velocity * Datas::BOSS_ATTACK1_SPEED * Delta::getTotalDelta();

			// 当たり判定
			if (!isDash) {
				if (!isGuard) {
					if (Datas::PLAYER_HEIGHT * 0.25f + bossAttack1[i].size.x * 0.4f > (bossAttack1[i].position - p_pos).Length()) {
						pGame.getPlayer().SetDamage(Datas::BOSS_ATTACK1_DAMAGE);
					}
				}
				else {
					/*if () {

					}*/
					if (Datas::PLAYER_HEIGHT * 0.3f + bossAttack1[i].size.x * 0.5f > (bossAttack1[i].position - p_pos).Length()) {
						pGame.getPlayer().SetDamage(Datas::BOSS_ATTACK1_DAMAGE);
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
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		if (!bossAttack1[i].isEnd) {
			getCameraMain().DrawQuad({ {bossAttack1[i].position.x - bossAttack1[i].size.x * 0.5f,bossAttack1[i].position.y - bossAttack1[i].size.y * 0.5f},
				bossAttack1[i].size.x,bossAttack1[i].size.y }, Datas::BOSS_ATTACK1_TEX);
		}
	}
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
