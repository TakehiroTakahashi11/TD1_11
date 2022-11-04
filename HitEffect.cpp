#include "HitEffect.h"
#include "Game.h"
#include "Quad.h"
#include "Camera.h"
#include "Datas.h"
#include "MyFunc.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Delta.h"

HitEffect::HitEffect(Game& game, Vector2D pos) : BaseEffect(game,pos)
{
	BaseInit(pos);
}

HitEffect::~HitEffect()
{
}

void HitEffect::Init()
{
	for (int i = 0; i < HitEffectMaxNum; i++) {
		//�G�t�F�N�g�̈ʒu�A���x�A�T�C�Y������
		hitEffect[i].position = position;
		hitEffect[i].velocity = { My::RandomF(5.0f, 7.0f, 1), My::RandomF(5.0f, 7.0f, 1) };
		hitEffect[i].size = { 16, 16 };

		//�G�t�F�N�g�������������������_���ɂ���
		hitEffect[i].theta = My::Random(0, 360);
		hitEffect[i].theta = hitEffect[i].theta * (M_PI / 180.0f);

		//�G�t�F�N�g�\��
		hitEffect[i].isEnd = false;
		hitEffect[i].acceleration = 0.15f;
	}
}

void HitEffect::Update()
{
	for (int i = 0; i < HitEffectMaxNum; i++) {
		if (hitEffect[i].isEnd == false) {
			//�G�t�F�N�g�̃T�C�Yx,y�̂ǂ��炩��0�ɂȂ�����
			if (hitEffect[i].size.x <= 0 || hitEffect[i].size.y <= 0) {
				//�G�t�F�N�g�I��
				hitEffect[i].isEnd = true;
			}

			hitEffect[i].position.x += (cosf(hitEffect[i].theta) * hitEffect[i].velocity.x) * Delta::getTotalDelta();
			hitEffect[i].position.y += -(sinf(hitEffect[i].theta) * hitEffect[i].velocity.y) * Delta::getTotalDelta();

			hitEffect[i].velocity.x += hitEffect[i].acceleration * Delta::getTotalDelta();
			hitEffect[i].velocity.y += hitEffect[i].acceleration * Delta::getTotalDelta();

			hitEffect[i].size -= {1.0f, 1.0f };
		}

		if (elapsedFrame >= 100.0f) {
			isEnd = true;
		}
	}
}

void HitEffect::Draw()
{
	for (int i = 0; i < HitEffectMaxNum; i++) {
		if (!hitEffect[i].isEnd) {
			getCameraMain().DrawQuad({ {hitEffect[i].position},hitEffect[i].size.x,hitEffect[i].size.y }, Datas::EFFECTS_HIT_TEX);
		}
	}
}