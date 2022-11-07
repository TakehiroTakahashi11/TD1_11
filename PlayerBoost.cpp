#include "PlayerBoost.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Delta.h"

PlayerBoost::PlayerBoost(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

PlayerBoost::~PlayerBoost()
{
}

void PlayerBoost::Init()
{
	for (int i = 0; i < PlayerBoostMaxNum; i++) {
		//エフェクトの位置、速度、サイズ初期化
		boostEffect[i].position = { My::RandomF(position.x - 15.0f, position.x + 15.0f, 1), My::RandomF(position.y - 15.0f, position.y + 15.0f, 1) };
		boostEffect[i].size = { 20, 20 };

		//透明度
		boostEffect[i].currentAlpha = 50;

		//エフェクト表示
		boostEffect[i].isEnd = false;

		//初期化フラグfalse
		boostEffect[i].init = false;
	}
}

void PlayerBoost::Update()
{
	for (int i = 0; i < PlayerBoostMaxNum; i++) {
		if (boostEffect[i].currentAlpha < 0x00 || boostEffect[i].size.x <= 0 || boostEffect[i].size.y <= 0) {

			//エフェクト消去
			boostEffect[i].isEnd = true;

			boostEffect[i].currentAlpha = 0;

			//経過フレーム初期化
			boostEffect[i].elapseFrame = 0.0f;
		}

		if (boostEffect[i].isEnd == false) {

			boostEffect[i].size.x -= 0.50f;
			boostEffect[i].size.y -= 0.50f;

			boostEffect[i].currentAlpha -= 6;

			//経過フレーム加算
			boostEffect[i].elapseFrame += Delta::getTotalDelta();

		}
	}

	// 終了処理
	if (endCheck()) {
		isEnd = true;
	}
}

void PlayerBoost::Draw()
{
	for (int i = 0; i < PlayerBoostMaxNum; i++) {
		if (!boostEffect[i].isEnd) {
			getCameraMain().DrawQuad({ {boostEffect[i].position.x - boostEffect[i].size.x * 0.5f,boostEffect[i].position.y - boostEffect[i].size.y * 0.5f},boostEffect[i].size.x,boostEffect[i].size.y },
				Datas::PLAYER_BOOST_TEX,0,0,0xFFFFFF00 + boostEffect[i].currentAlpha);
		}
	}
}

bool PlayerBoost::endCheck()
{
	for (int i = 0; i < PlayerBoostMaxNum; i++) {
		if (!boostEffect[i].isEnd) {// 終わっていないなら抜ける
			return false;
		}
	}
	return true;
}
