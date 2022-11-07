#include "MagicCircleThunder.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Game.h"
#include "Camera.h"
#include "Datas.h"
#include "Boss.h"

MagicCircleThunder::MagicCircleThunder(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
}

MagicCircleThunder::~MagicCircleThunder()
{
}

void MagicCircleThunder::Init() {
	effects.resize(3);

	for (int i = 0; i < effects.size(); i++) {
		effects[i].size = 0;
		effects[i].rotation = Vector2D(0, 1).Rotated(i * (360.0f / effects.size() * (float)M_PI / 180.0f));
		effects[i].position = Vector2D(300, 300) + effects[i].rotation.Rotated(effects[i].rotatetheta) * MagicCircleRadius;
		effects[i].rotatetheta = 0;
	}
}

void MagicCircleThunder::Update() {

	for (int i = 0; i < effects.size(); i++) {

		effects[i].theta += 1.0f / 120.0f * static_cast<float>(M_PI);

		if (effects[i].size <= 128) {
			effects[i].size += 0.01f * 128;
		}

		if (effects[i].size > 128) {
			effects[i].rotatetheta += 1.0f / 60.0f * static_cast<float>(M_PI);
			effects[i].position = Vector2D(300, 300) + effects[i].rotation.Rotated(effects[i].rotatetheta) * MagicCircleRadius;
		}

	}

	if (pGame.getBoss().EndThunder() && !effects.empty()) {
		effects.pop_back(); 
	}
	if (effects.empty()) {
		isEnd = true;
	}

}

void MagicCircleThunder::Draw() {

	for (int i = 0; i < effects.size(); i++) {
		Quad temp = { { effects[i].position.x - effects[i].size * 0.5f, effects[i].position.y - effects[i].size * 0.5f }, effects[i].size, effects[i].size };
		temp.Translation(-effects[i].position).Rotation(-effects[i].theta).Translation(effects[i].position);

		getCameraMain().DrawQuad(temp, Datas::MAGIC_CIRCLE_TEX);
	}

}
