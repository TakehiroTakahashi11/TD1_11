#include "BulletDeath.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Delta.h"
#include <Novice.h>

BulletDeath::BulletDeath(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

BulletDeath::~BulletDeath()
{
}

void BulletDeath::Init()
{
	layer = 2;
	for (int i = 0; i < BulletDeathMaxNum; i++) {
		bulletDeath[i].theta = My::Random((360 / BulletDeathMaxNum) * (i + 1) - 30, (360 / BulletDeathMaxNum) * (i + 1) + 30);
		bulletDeath[i].theta = bulletDeath[i].theta * (M_PI / 180.0f);

		//エフェクトの位置、速度、サイズ初期化
		bulletDeath[i].position = position;
		bulletDeath[i].size = { My::RandomF(3.0f, 15.0f,0), My::RandomF(3.0f, 15.0f,0) };
		bulletDeath[i].startSize = { bulletDeath[i].size.x, bulletDeath[i].size.y };

		//始端の座標と終端の座標の決定
		bulletDeath[i].startPosition = { bulletDeath[i].position.x, bulletDeath[i].position.y };
		bulletDeath[i].endPosition = { position.x + cosf(bulletDeath[i].theta) * My::RandomF(40, 80,0), position.y + sinf(bulletDeath[i].theta) * My::RandomF(40, 80,0) };

		//イージング用time変数の初期化
		bulletDeath[i].time = 0.0f;

		//透明度の初期化
		// bulletDeath[i].currentAlpha = 0xFF;

		//エフェクト表示
		bulletDeath[i].isEnd = false;
	}
}

void BulletDeath::Update()
{
	for (int i = 0; i < BulletDeathMaxNum; i++) {
		///粒子エフェクトが指定された位置まで移動したら
		if (bulletDeath[i].time <= 1.0f) {

			//粒子エフェクトのイージング処理
			bulletDeath[i].time += 0.03f * Delta::getTotalDelta();
			bulletDeath[i].easeTime = 1.0f - powf(1.0f - bulletDeath[i].time, 3.0f);

			//座標
			bulletDeath[i].position.x = (1.0 - bulletDeath[i].easeTime) * bulletDeath[i].startPosition.x + bulletDeath[i].easeTime * bulletDeath[i].endPosition.x;
			bulletDeath[i].position.y = (1.0 - bulletDeath[i].easeTime) * bulletDeath[i].startPosition.y + bulletDeath[i].easeTime * bulletDeath[i].endPosition.y;

			//透明度
			// bulletDeath[i].currentAlpha = (1.0 - bulletDeath[i].easeTime) * 0xFF + bulletDeath[i].easeTime * 0x00;

			//大きさ
			bulletDeath[i].size.x = (1.0 - bulletDeath[i].easeTime) * bulletDeath[i].startSize.x + bulletDeath[i].easeTime * 0;
			bulletDeath[i].size.y = (1.0 - bulletDeath[i].easeTime) * bulletDeath[i].startSize.y + bulletDeath[i].easeTime * 0;
		}

		if (elapsedFrame > 100 || bulletDeath[i].time >= 1.0f) {
			//エフェクト消去
			bulletDeath[i].isEnd = true;
		}
	}


	// 終了処理
	if (endCheck()) {
		isEnd = true;
	}
}

void BulletDeath::Draw()
{
	Novice::SetBlendMode(kBlendModeAdd);
	for (int i = 0; i < BulletDeathMaxNum; i++) {
		if (!bulletDeath[i].isEnd) {
			getCameraMain().DrawQuad({ {bulletDeath[i].position.x - bulletDeath[i].size.x * 0.5f,bulletDeath[i].position.y - bulletDeath[i].size.y * 0.5f}, bulletDeath[i].size.x ,bulletDeath[i].size.y }, Datas::BULLET_DEATH_TEX);
		}
	}
	Novice::SetBlendMode(kBlendModeNormal);
}

bool BulletDeath::endCheck()
{
	for (int i = 0; i < BulletDeathMaxNum; i++) {
		if (!bulletDeath[i].isEnd) {// 終わっていないなら抜ける
			return false;
		}
	}
	return true;
}
