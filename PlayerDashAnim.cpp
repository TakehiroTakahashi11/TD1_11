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
	pos = position;
}

void PlayerDashAnim::Update()
{
	// èIóπèàóù
	if (16.0f < elapsedFrame) {
		isEnd = true;
	}
}

void PlayerDashAnim::Draw()
{
	Quad temp = { {pos.x - Datas::PLAYER_WIDTH * 0.5f,pos.y - Datas::PLAYER_HEIGHT * 0.5f}, Datas::PLAYER_WIDTH, Datas::PLAYER_HEIGHT };
	getCameraMain().DrawQuad(temp.Translation(-pos).Rotation(static_cast<float>(theta)).Translation({ pos.x - Datas::PLAYER_WIDTH * 0.5f ,pos.y - Datas::PLAYER_HEIGHT * 0.5f }),
		Datas::Datas::PLAYER_DASH_TEX, (static_cast<int>(elapsedFrame) / 2));
}