#include "PlayerBoost.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Delta.h"

PlayerBoost::PlayerBoost(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

PlayerBoost::~PlayerBoost()
{
}

void PlayerBoost::Init()
{
	for (int i = 0; i < PlayerBoostMaxNum; i++) {
		//�G�t�F�N�g�̈ʒu�A���x�A�T�C�Y������
		boostEffect[i].position = { My::RandomF(position.x - 15.0f, position.x + 15.0f, 1), My::RandomF(position.y - 15.0f, position.y + 15.0f, 1) };
		boostEffect[i].size = { 20, 20 };

		//�����x
		boostEffect[i].currentAlpha = 50;

		//�G�t�F�N�g�\��
		boostEffect[i].isEnd = false;

		//�������t���Ofalse
		boostEffect[i].init = false;
	}
}

void PlayerBoost::Update()
{
	for (int i = 0; i < PlayerBoostMaxNum; i++) {
		if (boostEffect[i].currentAlpha < 0x00 || boostEffect[i].size.x <= 0 || boostEffect[i].size.y <= 0) {

			//�G�t�F�N�g����
			boostEffect[i].isEnd = true;

			boostEffect[i].currentAlpha = 0;

			//�o�߃t���[��������
			boostEffect[i].elapseFrame = 0.0f;
		}

		if (boostEffect[i].isEnd == false) {

			boostEffect[i].size.x -= 0.50f;
			boostEffect[i].size.y -= 0.50f;

			boostEffect[i].currentAlpha -= 6;

			//�o�߃t���[�����Z
			boostEffect[i].elapseFrame += Delta::getTotalDelta();

		}
	}

	// �I������
	if (endCheck()) {
		isEnd = true;
	}
}

void PlayerBoost::Draw()
{
	for (int i = 0; i < PlayerBoostMaxNum; i++) {
		if (!boostEffect[i].isEnd) {
			getCameraMain().DrawQuad({ {boostEffect[i].position.x - boostEffect[i].size.x * 0.5f,boostEffect[i].position.y - boostEffect[i].size.y * 0.5f},boostEffect[i].size.x,boostEffect[i].size.y },
				Datas::PLAYER_BOOST_TEX,0,0,0xFFFFFF00 + boostEffect[i].currentAlpha);
		}
	}
}

bool PlayerBoost::endCheck()
{
	for (int i = 0; i < PlayerBoostMaxNum; i++) {
		if (!boostEffect[i].isEnd) {// �I����Ă��Ȃ��Ȃ甲����
			return false;
		}
	}
	return true;
}
