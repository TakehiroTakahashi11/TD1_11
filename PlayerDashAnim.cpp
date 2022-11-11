#include "PlayerDashAnim.h"
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

PlayerDashAnim::PlayerDashAnim(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

PlayerDashAnim::~PlayerDashAnim()
{
}

void PlayerDashAnim::Init()
{
	elapsedFrame = 0.0f;
	theta = pGame.getPlayer().GetIsDir();
	layer = 1;
}

void PlayerDashAnim::Update()
{
	// èIóπèàóù
	pos = pGame.getPlayer().GetPosition();
	if (16.0f < elapsedFrame) {
		isEnd = true;
	}
}

void PlayerDashAnim::Draw()
{
	Novice::SetBlendMode(kBlendModeAdd);
	Quad temp = { {pos.x - Datas::PLAYER_WIDTH * 0.5f,pos.y - Datas::PLAYER_HEIGHT * 0.5f}, Datas::PLAYER_WIDTH, Datas::PLAYER_HEIGHT };
	getCameraMain().DrawQuad(temp,Datas::Datas::PLAYER_DASH_TEX, (static_cast<int>(elapsedFrame) / 2));
	Novice::SetBlendMode(kBlendModeNormal);
}