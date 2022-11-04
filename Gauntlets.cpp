#include "Gauntlets.h"
#include "Game.h"
#include "Camera.h"
#include "Datas.h"
#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "MyFunc.h"
#include "Quad.h"
#include "Delta.h"
#include <Novice.h>

Gauntlets::Gauntlets(Game& game) : Obj(game)
{
	Init();
}

Gauntlets::~Gauntlets()
{
}

void Gauntlets::Init()
{
	position = { 0.0f,0.0f };
	health = 300.0f;
	guard_dir = 0.0f;
	dash_dis = 0.0f;
	dash_dir = 0.0f;
	x_anim = 0;
	isBreak = false;
}

void Gauntlets::Update()
{
	Animation();
}

void Gauntlets::Draw()
{
	Quad temp = { {0.0f,0.0f},0.0f,0.0f };

	if (getPlayer().GetIsGuard()) {// ガード中なら
		temp = My::RotateCenter(position, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x) + static_cast<float>(guard_dir * M_PI / 180), Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
	else if (getPlayer().GetIsDash()) {// ダッシュ中なら
		temp = My::RotateCenter(position, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x), Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
	else {// ムーブ中なら
		temp = My::RotateCenter(position, atan2f(getPlayer().GetDirection().y, getPlayer().GetDirection().x) + static_cast<float>(guard_dir * M_PI / 180), Datas::GAUNTLET_WIDTH, Datas::GAUNTLET_HEIGHT);
		getCameraMain().DrawQuad(temp, Datas::GAUNTLET_TEX);
	}
}

void Gauntlets::Animation()
{
	Vector2D pos = getPlayer().GetPosition();// プレイヤー座標取得
	Vector2D dir = getPlayer().GetDirection();

	if (getPlayer().GetIsGuard()) {// ガード中なら
		// ガードアニメーション用
		if (guard_dir < 90.0f) {// 角度が90より小さいならば
			guard_dir += Datas::GAUNTLET_GUARD_DIR_SPD * Delta::getTotalDelta();// 回転
		}
		else {// 以上なら
			guard_dir = 90.0f;// 固定
		}

		// 計算
		dir = dir.Rotated(static_cast<float>((guard_dir + 270) * M_PI / 180));
		pos += dir * Datas::GAUNTLET_PLAYER_GUARD_DISTANCE;
	}
	else if (getPlayer().GetIsDash()) {// ダッシュ中なら
		// ダッシュアニメーション用
		if (dash_dis < 1.0f) {// アニメーションしきっていないなら
			dash_dis += Datas::GAUNTLET_DASH_DIS_SPD * Delta::getTotalDelta();// 回転
		}
		else {// 以上なら
			dash_dis = 1.0f;// 固定
		}
		if (dash_dir < 75.0f) {
			dash_dir = 75.0f;
		}
		if (dash_dir < 90.0f) {// 角度が90より小さいならば
			dash_dir += Datas::GAUNTLET_DASH_DIR_SPD * Delta::getTotalDelta();// 回転
		}
		else {// 以上なら
			dash_dir = 90.0f;// 固定
		}

		// 計算
		dir = dir.Rotated(static_cast<float>((dash_dir + 270) * M_PI / 180));
		pos += dir * (Datas::GAUNTLET_PLAYER_DASH_DISTANCE * dash_dis);
	}
	else {// ムーブ中なら
		// ガードアニメーション用
		if (0.0f < guard_dir) {// 角度が0度より大きいなら
			guard_dir -= Datas::GAUNTLET_GUARD_DIR_SPD * Delta::getTotalDelta();// 回転
		}
		else {// 以下なら
			guard_dir = 0.0f;// 固定
		}

		// ダッシュアニメーション用
		if (0.0f < dash_dis) {// アニメーションしきっていないなら
			dash_dis -= Datas::GAUNTLET_DASH_DIS_SPD * Delta::getTotalDelta();// 回転
		}
		else {// 以下なら
			dash_dis = 0.0f;// 固定
		}

		if (75.0f < dash_dir) {
			dash_dir = 75.0f;
		}
		if (0.0f < dash_dir) {// 角度が0より大きいならば
			dash_dir -= Datas::GAUNTLET_DASH_DIR_SPD * Delta::getTotalDelta();// 回転
		}
		else {// 以下なら
			dash_dir = 0.0f;// 固定
		}

		// 計算
		dir = dir.Rotated(static_cast<float>((dash_dir + guard_dir + 270) * M_PI / 180));
		pos += dir * Datas::GAUNTLET_PLAYER_MOVE_DISTANCE;
	}

	Vector2D center = { Datas::PLAYER_WIDTH * 0.5f, Datas::PLAYER_HEIGHT * 0.5f };
	position = pos + center;// 反映
}
