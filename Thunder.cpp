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
}

Thunder::~Thunder()
{
}

void Thunder::Init()
{
	elapsedFrame = 0.0f;
	col_pos = { position.x + 145.0f, position.y + 45.0f };
}

void Thunder::Update()
{
	Vector2D temp = { Datas::PLAYER_WIDTH * 1.9f,-Datas::PLAYER_WIDTH * 0.5f };
	// ìñÇΩÇËîªíË
	if (!pGame.getPlayer().GetIsDash() && !pGame.getPlayer().GetIsInvincible()) {
		if (My::CollisonCircletoPoint(col_pos, Datas::EFFECTS_THUNDER_SIZE_X, Datas::EFFECTS_THUNDER_SIZE_Y, pGame.getPlayer().GetPosition() + temp)) {
			pGame.getPlayer().SetDamage(Datas::BOSS_THUNDER1_DAMAGE);
		}
	}

	// èIóπèàóù
	if (40.0f < elapsedFrame) {
		isEnd = true;
	}
}

void Thunder::Draw()
{
	if (!isEnd) {
		getCameraMain().DrawQuad({ {position.x - 145.0f,position.y - 45.0f} ,Datas::EFFECTS_THUNDER_SIZE ,Datas::EFFECTS_THUNDER_SIZE }, Datas::EFFECTS_THUNDER_TEX,
			static_cast<int>(elapsedFrame) % 7, static_cast<int>(elapsedFrame) / 7);
	}
}