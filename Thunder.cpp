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
	layer = 1;
}

void Thunder::Update()
{
	// “–‚½‚è”»’è
	if (2.5f < elapsedFrame && !isChecked) {
		if (!pGame.getPlayer().GetIsInvincible()) {
			Vector2D p = { 0.0f,Datas::PLAYER_WIDTH * 0.3f };
			if (pGame.getPlayer().GetIsDash()) {
				if (My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(0) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(1) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(2) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(3) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(4) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(5) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(6) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(7) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(8) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(9) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(10) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(11) - p)
					|| My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, Datas::EFFECTS_THUNDER_SIZE_X * 1.5f, pGame.getPlayer().GetJustDodgePosition(12) - p)) {
					pGame.getPlayer().SetIsJustDodge();
				}
			}
			else {
				if (My::CollisonCircletoPoint(position, Datas::EFFECTS_THUNDER_SIZE_X, Datas::EFFECTS_THUNDER_SIZE_X, pGame.getPlayer().GetPosition() - p)) {
					Vector2D temp = pGame.getPlayer().GetPosition() - p - position;
					pGame.getPlayer().SetKnockBack(temp.Normalized() * Datas::PLAYER_KNOCKBACK_POWER);
					pGame.getPlayer().SetDamage(Datas::BOSS_THUNDER1_DAMAGE);
				}
			}
		}
		// ‰¹
		Datas::BOSS_THUNDER_SOUND.PlayOnce();
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
		Novice::SetBlendMode(kBlendModeAdd);
		getCameraMain().DrawQuad({ {position.x - 145.0f,position.y - 85.0f} ,Datas::EFFECTS_THUNDER_SIZE ,Datas::EFFECTS_THUNDER_SIZE }, Datas::EFFECTS_THUNDER_VINNET_TEX,
			static_cast<int>(elapsedFrame) % 7, static_cast<int>(elapsedFrame) / 7);
		Novice::SetBlendMode(kBlendModeNormal);
		getCameraMain().DrawQuad({ {position.x - 145.0f,position.y - 85.0f} ,Datas::EFFECTS_THUNDER_SIZE ,Datas::EFFECTS_THUNDER_SIZE }, Datas::EFFECTS_THUNDER_TEX,
			static_cast<int>(elapsedFrame) % 7, static_cast<int>(elapsedFrame) / 7);
	}
}