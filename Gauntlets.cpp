#include "Gauntlets.h"
#include "Game.h"
#include "Camera.h"
#include "Datas.h"
#include "Player.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "MyFunc.h"
#include "Quad.h"
#include "Delta.h"
#include <Novice.h>

Gauntlets::Gauntlets(Game& game) : Obj(game)
{
	Init();
}

Gauntlets::~Gauntlets()
{
}

void Gauntlets::Init()
{
	position = { 0.0f,0.0f };

	dash_dis = 0.0f;
	dash_dis_acc = 1.0f;

	x_anim = 0;

	chargeAttackFrame = 0.0f;
	chargeAttackSpeed = 0.0f;

	chargePos = { 0.0f,0.0f };
}

void Gauntlets::Update()
{
}

void Gauntlets::Draw()
{
	if (!getPlayer().GetIsGuardBreak()) {
		Vector2D dir = getPlayer().GetDirection();
		dir = dir.Rotated(-90 * M_PI / 180);
		Vector2D p_pos = getPlayer().GetPosition();
		Player::PLAYER_DIRECTION_STATE state = getPlayer().GetDirectionState();

		if (getPlayer().GetIsDash() || getPlayer().GetIsChargeAttack()) {
			dash_dis_acc += dash_dis_acc * 1.5f * Delta::getTotalDelta();
			dash_dis += dash_dis_acc * 0.5f * Delta::getTotalDelta();
			if (dash_dis > Datas::GAUNTLET_PLAYER_DASH_DISTANCE) {
				dash_dis = Datas::GAUNTLET_PLAYER_DASH_DISTANCE;
			}
			dir = dir.Rotated(90 * M_PI / 180);
			Vector2D g_pos = p_pos + dir * dash_dis;

			if (getPlayer().GetIsChargeAttack()) {
				g_pos += chargePos;
			}

			Quad temp = { {g_pos.x - Datas::GAUNTLET_WIDTH * 0.5f,g_pos.y - Datas::GAUNTLET_HEIGHT * 0.5f}, Datas::GAUNTLET_WIDTH , Datas::GAUNTLET_HEIGHT };
			Vector2D ld = { -5.0f, 25.0f };
			switch (state)
			{
			case Player::UP:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DASH_UP_TEX);
				break;
			case Player::DOWN:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DASH_DOWN_TEX);
				break;
			case Player::LEFT:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DASH_LEFT_TEX);
				break;
			case Player::RIGHT:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DASH_RIGHT_TEX);
				break;
			case Player::RIGHTUP:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DASH_RIGHTUP_TEX);
				break;
			case Player::LEFTUP:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DASH_LEFTUP_TEX);
				break;
			case Player::RIGHTDOWN:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DASH_RIGHTDOWN_TEX);
				break;
			case Player::LEFTDOWN:
				temp = temp.Translation(ld);
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DASH_LEFTDOWN_TEX);
				break;
			default:
				break;
			}
		}
		else {
			dash_dis_acc -= dash_dis_acc * 1.5f * Delta::getTotalDelta();
			if (dash_dis_acc < 1.0f) {
				dash_dis_acc = 1.0f;
			}

			dash_dis -= dash_dis_acc * Delta::getTotalDelta();
			if (dash_dis < 0.0f) {
				dash_dis = 0.0f;
			}

			if (getPlayer().GetIsGuard()) {// ƒK[ƒhŽž‰ñ“]
				dir = dir.Rotated(90 * M_PI / 180);
				switch (state)
				{
				case Player::UP:
					state = Player::LEFT;
					break;
				case Player::DOWN:
					state = Player::RIGHT;
					break;
				case Player::LEFT:
					state = Player::DOWN;
					break;
				case Player::RIGHT:
					state = Player::UP;
					break;
				case Player::RIGHTUP:
					state = Player::LEFTUP;
					break;
				case Player::LEFTUP:
					state = Player::LEFTDOWN;
					break;
				case Player::RIGHTDOWN:
					state = Player::RIGHTUP;
					break;
				case Player::LEFTDOWN:
					state = Player::RIGHTDOWN;
					break;
				default:
					break;
				}
			}

			Vector2D g_pos = p_pos + dir * Datas::GAUNTLET_PLAYER_MOVE_DISTANCE;
			Quad temp = { {g_pos.x - Datas::GAUNTLET_WIDTH * 0.5f,g_pos.y - Datas::GAUNTLET_HEIGHT * 0.5f}, Datas::GAUNTLET_WIDTH , Datas::GAUNTLET_HEIGHT };

			switch (state)// •`‰æ
			{
			case Player::UP:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_UP_TEX);
				break;
			case Player::DOWN:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_DOWN_TEX);
				break;
			case Player::LEFT:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_LEFT_TEX);
				break;
			case Player::RIGHT:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_RIGHT_TEX);
				break;
			case Player::RIGHTUP:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_RIGHTUP_TEX);
				break;
			case Player::LEFTUP:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_LEFTUP_TEX);
				break;
			case Player::RIGHTDOWN:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_RIGHTDOWN_TEX);
				break;
			case Player::LEFTDOWN:
				getCameraMain().DrawQuad(temp, Datas::GAUNTLET_LEFTDOWN_TEX);
				break;
			default:
				break;
			}
		}
	}
	else {
		// ‰ó‚ê‚½ƒKƒ“ƒgƒŒƒbƒg•`‰æ?
	}
}

bool Gauntlets::ChargeAttack()
{
	if (InitFlag) {
		chargePos = { 0.0f,0.0f };
		InitFlag = false;
		chargeAttackFrame = 0.0f;
		chargeAttackSpeed = 0.0f;
	}

	chargeAttackFrame += Delta::getDeltaTime();
	Vector2D dir = getPlayer().GetDirection();

	if (chargeAttackFrame < 50.0f) {
		Delta::MoveDynDelta(-0.15f);
		chargeAttackSpeed -= 0.3f * Delta::getTotalDelta();
	}
	else if (chargeAttackFrame < 60.0f) {
		Delta::SetDynDelta(1.0f);
		chargeAttackSpeed = 70.0f;
	}

	chargePos += dir * chargeAttackSpeed;

	if (60.0f < chargeAttackFrame) {// I—¹ˆ—
		chargeAttackFrame = 0.0f;
		InitFlag = true;
		return true;
	}
	return false;
}