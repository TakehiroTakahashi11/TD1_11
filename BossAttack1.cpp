#include "BossAttack1.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Delta.h"

BossAttack1::BossAttack1(Game& game, Vector2D pos) : BaseBullet(game, pos)
{
	BaseInit(pos);
}

BossAttack1::~BossAttack1()
{
}

void BossAttack1::Init()
{
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		//�e������������
		bossAttack1[i].theta = static_cast<float>(i * (360 / BossAttack1MaxNum) * (M_PI / 180.0f));

		//�e�̈ʒu�A���x�A�T�C�Y������
		bossAttack1[i].velocity = { cosf(bossAttack1[i].theta), sinf(bossAttack1[i].theta) };
		bossAttack1[i].position = position + bossAttack1[i].velocity * Datas::BOSS_ATTACK1_DIS;
		bossAttack1[i].size = { Datas::BOSS_ATTACK1_SIZE, Datas::BOSS_ATTACK1_SIZE };


		//�e�\��
		bossAttack1[i].isEnd = false;
	}
}

void BossAttack1::Update()
{
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		if (bossAttack1[i].isEnd == false) {
			if (bossAttack1[i].position.x + bossAttack1[i].size.x < -Datas::STAGE1_WIDTH
				|| Datas::STAGE1_WIDTH < bossAttack1[i].position.x + bossAttack1[i].size.x
				|| bossAttack1[i].position.y + bossAttack1[i].size.y < -Datas::STAGE1_HEIGHT
				|| Datas::STAGE1_HEIGHT < bossAttack1[i].position.y + bossAttack1[i].size.y) {// �����ǂ��O�Ȃ�
				//�G�t�F�N�g�I��
				bossAttack1[i].isEnd = true;
			}

			// �ړ�����
			bossAttack1[i].position += bossAttack1[i].velocity * Datas::BOSS_ATTACK1_SPEED * Delta::getTotalDelta();
		}

	}

	// �I������
	if (endCheck()) {
		isEnd = true;
	}
}

void BossAttack1::Draw()
{
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		if (!bossAttack1[i].isEnd) {
			getCameraMain().DrawQuad({ {bossAttack1[i].position.x - bossAttack1[i].size.x * 0.5f,bossAttack1[i].position.y - bossAttack1[i].size.y * 0.5f},
				bossAttack1[i].size.x,bossAttack1[i].size.y }, Datas::EFFECTS_HIT_TEX);
		}
	}
}

bool BossAttack1::endCheck()
{
	for (int i = 0; i < BossAttack1MaxNum; i++) {
		if (!bossAttack1[i].isEnd) {// �I����Ă��Ȃ��Ȃ甲����
			return false;
		}
	}
	return true;
}
