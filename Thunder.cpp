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

Thunder::Thunder(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

Thunder::~Thunder()
{
}

void Thunder::Init()
{
	col_pos = { position.x + 255.0f, position.y + 45.0f };
}

void Thunder::Update()
{
	// �����蔻��
	if (!pGame.getPlayer().GetIsDash() && !pGame.getPlayer().GetIsInvincible()) {
		
	}

	// �I������
	if (30.0f < elapsedFrame) {
		isEnd = true;
	}
}

void Thunder::Draw()
{
	if (!isEnd) {
		getCameraMain().DrawQuad({ {position.x - 255.0f,position.y - 45.0f} ,Datas::EFFECTS_THUNDER_SIZE ,Datas::EFFECTS_THUNDER_SIZE }, Datas::EFFECTS_THUNDER_TEX,
			static_cast<int>(elapsedFrame) % 7, static_cast<int>(elapsedFrame) / 7);
	}
}