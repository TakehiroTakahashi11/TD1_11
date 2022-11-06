#include "BossAttack1Anim.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#include "Delta.h"
#include "Game.h"
#include "Player.h"
#include "Datas.h"

BossAttack1Anim::BossAttack1Anim(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

BossAttack1Anim::~BossAttack1Anim()
{
}

void BossAttack1Anim::Init()
{
	elapsedFrame = 0.0f;
}

void BossAttack1Anim::Update()
{
	// èIóπèàóù
	if (48.0f < elapsedFrame) {
		isEnd = true;
	}
}

void BossAttack1Anim::Draw()
{
	if (!isEnd) {
		if (elapsedFrame == 0.0f) {
			getCameraMain().DrawQuad({ {position.x - 200.0f,position.y - 160.0f} ,Datas::EFFECTS_PRETHUNDER_SIZE ,Datas::EFFECTS_PRETHUNDER_SIZE }, Datas::EFFECTS_PRETHUNDER_TEX, static_cast<int>(elapsedFrame));
		}
		else {
			getCameraMain().DrawQuad({ {position.x - 200.0f,position.y - 160.0f} ,Datas::EFFECTS_PRETHUNDER_SIZE ,Datas::EFFECTS_PRETHUNDER_SIZE }, Datas::EFFECTS_PRETHUNDER_TEX,
				(static_cast<int>(elapsedFrame) / 2) % 6, (static_cast<int>(elapsedFrame) / 2) / 6);
		}
	}
}