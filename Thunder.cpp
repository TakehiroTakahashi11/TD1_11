#include "Thunder.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#include "Delta.h"
#include "Game.h"
#include "Player.h"
#include "Datas.h"
#include <Novice.h>

Thunder::Thunder(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
	isChecked = false;
}

Thunder::~Thunder()
{
}

void Thunder::Init()
{
	elapsedFrame = 0.0f;
	isChecked = false;
	layer = 2;
}

void Thunder::Update()
{
	// “–‚½‚è”»’è
	if (2.5f < elapsedFrame && !isChecked) {
		if (My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X, Datas::EFFECTS_THUNDER_SIZE_X, pGame.getPlayer().GetCenterPosition())
			&& !pGame.getPlayer().GetIsDash() && !pGame.getPlayer().GetIsInvincible()) {
			pGame.getPlayer().SetDamage(Datas::BOSS_THUNDER1_DAMAGE);
		}
		isChecked = true;
	}

	// I—¹ˆ—
	if (40.0f < elapsedFrame) {
		isEnd = true;
	}
}

void Thunder::Draw()
{
	if (!isEnd) {
		getCameraMain().DrawQuad({ {position.x - 145.0f,position.y - 85.0f} ,Datas::EFFECTS_THUNDER_SIZE ,Datas::EFFECTS_THUNDER_SIZE }, Datas::EFFECTS_THUNDER_TEX,
			static_cast<int>(elapsedFrame) % 7, static_cast<int>(elapsedFrame) / 7);
	}
}