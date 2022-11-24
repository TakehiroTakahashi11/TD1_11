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
#define _USE_MATH_DEFINES
#include <math.h>
#include "Boss.h"
#include <Novice.h>

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

	circlePos = position;
	circle1Size = 0.0f;
	circle2Size = 0.0f;
	circle3Size = 0.0f;
	circle1Theta = 0.0f;
	circle2Theta = 0.0f;
	circle3Theta = 0.0f;
	circle1ThetaSpd = 0.0f;
	circle2ThetaSpd = 0.0f;
	circle3ThetaSpd = 0.0f;

	Datas::BOSS_CIRCLE_SOUND.PlayOnce();
}

void BossAttack1Anim::Update()
{
	circlePos = pGame.getBoss().GetPosition();


	if (150.0f < elapsedFrame) {
		if (circle3Size > 0.0f) {// èkè¨
			circle1Size -= 5.0f * Delta::getTotalDelta();
			circle2Size -= 5.0f * Delta::getTotalDelta();
			circle3Size -= 5.0f * Delta::getTotalDelta();
		}
	}

	if (150.0f > elapsedFrame) {
		circle1Size += 5.0f * Delta::getTotalDelta();
		circle2Size += 5.0f * Delta::getTotalDelta();
		circle3Size += 5.0f * Delta::getTotalDelta();
	}
	circle1ThetaSpd += 0.001f * 1.1 * Delta::getTotalDelta();
	circle2ThetaSpd -= 0.001f * Delta::getTotalDelta();
	circle3ThetaSpd += 0.001f * Delta::getTotalDelta();
	circle1Theta += circle1ThetaSpd * Delta::getTotalDelta();
	circle2Theta += circle2ThetaSpd * Delta::getTotalDelta();
	circle3Theta += circle3ThetaSpd * Delta::getTotalDelta();

	// Ëáíl
	if (circle1Size > 512.0f) {
		circle1Size = 512.0f;
	}
	if (circle2Size > 512.0f) {
		circle2Size = 512.0f;
	}
	if (circle3Size > 512.0f) {
		circle3Size = 512.0f;
	}

	if (circle1ThetaSpd > 0.05f) {
		circle1ThetaSpd = 0.05f;
	}
	if (circle2ThetaSpd > 0.05f) {
		circle2ThetaSpd = 0.05f;
	}
	if (circle3ThetaSpd > 0.05f) {
		circle3ThetaSpd = 0.05f;
	}

	if (circle1Theta > M_PI * 2) {
		circle1Theta -= M_PI * 2;
	}
	if (circle2Theta > M_PI * 2) {
		circle2Theta -= M_PI * 2;
	}
	if (circle3Theta > M_PI * 2) {
		circle3Theta -= M_PI * 2;
	}



	// èIóπèàóù
	if (150.0f < elapsedFrame && circle3Size <= 0.0f) {
		isEnd = true;
	}
}

void BossAttack1Anim::Draw()
{
	if (!isEnd) {
		Quad vinnet = { {circlePos.x - circle1Size ,circlePos.y - circle1Size} ,circle1Size * 2.0f ,circle1Size * 2.0f };
		Quad circle1 = { {circlePos.x - circle1Size * 0.5f,circlePos.y - circle1Size * 0.5f} ,circle1Size ,circle1Size };
		Quad circle2 = { {circlePos.x - circle2Size * 0.5f,circlePos.y - circle2Size * 0.5f} ,circle2Size ,circle2Size };
		Quad circle3 = { {circlePos.x - circle3Size * 0.5f,circlePos.y - circle3Size * 0.5f} ,circle3Size ,circle3Size };
		circle1 = circle1.Translation(-circlePos).Rotation(circle1Theta).Translation(circlePos);
		circle2 = circle2.Translation(-circlePos).Rotation(circle2Theta).Translation(circlePos);
		circle3 = circle3.Translation(-circlePos).Rotation(circle3Theta).Translation(circlePos);

		Novice::SetBlendMode(kBlendModeAdd);
		getCameraMain().DrawQuad(vinnet, Datas::BULLET_CIRCLE_VINNET_TEX);
		Novice::SetBlendMode(kBlendModeNormal);

		getCameraMain().DrawQuad(circle1, Datas::BULLET_CIRCLE_TEX1);
		getCameraMain().DrawQuad(circle2, Datas::BULLET_CIRCLE_TEX2);
		getCameraMain().DrawQuad(circle3, Datas::BULLET_CIRCLE_TEX3);
	}
}