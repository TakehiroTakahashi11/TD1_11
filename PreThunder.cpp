#include "PreThunder.h"
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

PreThunder::PreThunder(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

PreThunder::~PreThunder()
{
}

void PreThunder::Init()
{
	elapsedFrame = 0.0f;
	elapsedSub = 0.0f;
}

void PreThunder::Update()
{
	if (Datas::BOSS_THUNDER1_PRETIME < elapsedFrame) {
		elapsedSub += Delta::getTotalDelta();
	}

	// I—¹ˆ—
	if (48.0f < elapsedSub) {
		isEnd = true;
	}
}

void PreThunder::Draw()
{
	if (!isEnd) {
		if (elapsedSub == 0.0f) {
			getCameraMain().DrawQuad({ {position.x - 200.0f,position.y - 200.0f} ,Datas::EFFECTS_PRETHUNDER_SIZE ,Datas::EFFECTS_PRETHUNDER_SIZE }, Datas::EFFECTS_PRETHUNDER_TEX, static_cast<int>(elapsedSub));
		}
		else {
			getCameraMain().DrawQuad({ {position.x - 200.0f,position.y - 200.0f} ,Datas::EFFECTS_PRETHUNDER_SIZE ,Datas::EFFECTS_PRETHUNDER_SIZE }, Datas::EFFECTS_PRETHUNDER_TEX,
				(static_cast<int>(elapsedSub) / 2) % 6, (static_cast<int>(elapsedSub) / 2) / 6);
		}
	}
}