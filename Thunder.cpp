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
	isChecked = false;}

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
	// 当たり判定
	if (2.5f < elapsedFrame && !isChecked) {
		if (!pGame.getPlayer().GetIsInvincible()) {
			if (pGame.getPlayer().GetIsDash()) {
				if (My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(0))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(1))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(2))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(3))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(4))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(5))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(6))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(7))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(8))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(9))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(10))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(11))
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(12))) {
					pGame.getPlayer().SetIsJustDodge();
				}
			}
			else {
				if (My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X, Datas::EFFECTS_THUNDER_SIZE_X, pGame.getPlayer().GetCenterPosition())) {
					pGame.getPlayer().SetDamage(Datas::BOSS_THUNDER1_DAMAGE);
				}
			}
		}
		isChecked = true;
	}

	// 終了処理
	if (40.0f < elapsedFrame) {
		isEnd = true;
	}
}

void Thunder::Draw()
{
	if (!isEnd) {
		Novice::SetBlendMode(kBlendModeAdd);
		getCameraMain().DrawQuad({ {position.x - 145.0f,position.y - 85.0f} ,Datas::EFFECTS_THUNDER_SIZE ,Datas::EFFECTS_THUNDER_SIZE }, Datas::EFFECTS_THUNDER_VINNET_TEX);
		Novice::SetBlendMode(kBlendModeNormal);
		getCameraMain().DrawQuad({ {position.x - 145.0f,position.y - 85.0f} ,Datas::EFFECTS_THUNDER_SIZE ,Datas::EFFECTS_THUNDER_SIZE }, Datas::EFFECTS_THUNDER_TEX,
			static_cast<int>(elapsedFrame) % 7, static_cast<int>(elapsedFrame) / 7);
	}
}