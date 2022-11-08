#include "MagicCircleThunder.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Game.h"
#include "Camera.h"
#include "Datas.h"
#include "Boss.h"
#include "EffectManager.h"
#include "Player.h"
#include "Delta.h"

MagicCircleThunder::MagicCircleThunder(Game& game, Vector2D pos) : BaseEffect(game, pos)
{
	BaseInit(pos);
	thunder1pos = {0.0f,0.0f};
	thunder2pos = { 0.0f,0.0f };
	thunder3pos = { 0.0f,0.0f };
	prethunder1_num = -1;
	prethunder2_num = -1;
	prethunder3_num = -1;
	thunder1_created = false;
	thunder2_created = false;
	thunder3_created = false;
}

MagicCircleThunder::~MagicCircleThunder()
{
}

void MagicCircleThunder::Init() {
	effects.resize(3);

	for (int i = 0; i < effects.size(); i++) {
		effects[i].size = 0;
		effects[i].theta = 0;
		effects[i].rotatetheta = 0;
		effects[i].rotation = Vector2D(0, 1).Rotated(i * (360.0f / effects.size() * (float)M_PI / 180.0f));
		effects[i].position = position + effects[i].rotation.Rotated(effects[i].rotatetheta) * MagicCircleRadius;
	}
}

void MagicCircleThunder::Update() {

	for (int i = 0; i < effects.size(); i++) {

		effects[i].theta += 1.0f / 60.0f * static_cast<float>(M_PI) * Delta::getTotalDelta();

		if (effects[i].size < 128) {
			effects[i].size += 0.01f * 128 * Delta::getTotalDelta();
		}
		else {
			effects[i].size = 128.0f;
		}

		if (effects[i].size == 128.0f) {
			effects[i].rotatetheta += 1.0f / 60.0f * static_cast<float>(M_PI) * Delta::getTotalDelta();
			effects[i].position = pGame.getBoss().GetPosition() + effects[i].rotation.Rotated(effects[i].rotatetheta) * MagicCircleRadius;

			if (effects[i].rotatetheta > 1.63f * static_cast<float>(M_PI)) {
				if (prethunder1_num == -1) {
					thunder1pos = pGame.getPlayer().GetCenterPosition();
					prethunder1_num = EffectManager::MakeNewEffect(thunder1pos, kPreThunder);
				}
				if (!thunder1_created && EffectManager::GetIsEnd(prethunder1_num)) {
					thunder1_created = true;
					EffectManager::MakeNewEffect(thunder1pos, kThunder);
					pGame.getCameraMain().CameraShake({ Datas::BOSS_THUNDER1_SHAKE_AMP_X,Datas::BOSS_THUNDER1_SHAKE_AMP_Y }, { Datas::BOSS_THUNDER1_SHAKE_DIS_X,Datas::BOSS_THUNDER1_SHAKE_DIS_Y }, 20.0f);
					effects.pop_back();
				}
			}
			if (effects[i].rotatetheta > 2.3f * static_cast<float>(M_PI)) {
				if (prethunder2_num == -1) {
					thunder2pos = pGame.getPlayer().GetCenterPosition();
					prethunder2_num = EffectManager::MakeNewEffect(thunder2pos, kPreThunder);
				}
				if (!thunder2_created && EffectManager::GetIsEnd(prethunder2_num)) {
					thunder2_created = true;
					EffectManager::MakeNewEffect(thunder2pos, kThunder);
					pGame.getCameraMain().CameraShake({ Datas::BOSS_THUNDER1_SHAKE_AMP_X,Datas::BOSS_THUNDER1_SHAKE_AMP_Y }, { Datas::BOSS_THUNDER1_SHAKE_DIS_X,Datas::BOSS_THUNDER1_SHAKE_DIS_Y }, 20.0f);
					effects.pop_back();
				}
			}
			if (effects[i].rotatetheta > 2.95f * static_cast<float>(M_PI)) {
				if (prethunder3_num == -1) {
					thunder3pos = pGame.getPlayer().GetCenterPosition();
					prethunder3_num = EffectManager::MakeNewEffect(thunder3pos, kPreThunder);
				}
				if (!thunder3_created && EffectManager::GetIsEnd(prethunder3_num)) {
					thunder3_created = true;
					EffectManager::MakeNewEffect(thunder3pos, kThunder);
					pGame.getCameraMain().CameraShake({ Datas::BOSS_THUNDER1_SHAKE_AMP_X,Datas::BOSS_THUNDER1_SHAKE_AMP_Y }, { Datas::BOSS_THUNDER1_SHAKE_DIS_X,Datas::BOSS_THUNDER1_SHAKE_DIS_Y }, 20.0f);
					effects.pop_back();
				}
			}
		}

	}

	if (effects.empty()) {
		isEnd = true;
	}

}

void MagicCircleThunder::Draw() {

	for (int i = 0; i < effects.size(); i++) {
		Quad temp = { { effects[i].position.x - effects[i].size * 0.5f, effects[i].position.y - effects[i].size * 0.5f }, effects[i].size, effects[i].size };
		temp = temp.Translation(-effects[i].position).Rotation(-effects[i].theta).Translation(effects[i].position);

		getCameraMain().DrawQuad(temp, Datas::MAGIC_CIRCLE_TEX);
	}

}
