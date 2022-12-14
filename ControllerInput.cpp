#include "ControllerInput.h"
#include "Datas.h"
#include <Novice.h>
#include "Delta.h"
// 静的メンバ変数の再宣言

XINPUT_STATE Controller::state[MAX_CONTROLLER_NUM] = { 0 };
XINPUT_STATE Controller::previousState[MAX_CONTROLLER_NUM] = { 0 };

BYTE Controller::triggerDeadZone[MAX_CONTROLLER_NUM] = { XINPUT_GAMEPAD_TRIGGER_THRESHOLD };

SHORT Controller::leftStickDeadZone[MAX_CONTROLLER_NUM] = { XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE };
SHORT Controller::rightStickDeadZone[MAX_CONTROLLER_NUM] = { XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE };

int Controller::number = 0;
XINPUT_VIBRATION Controller::vibration = { 0,0 };
int Controller::vibration_vel = 0.0f;

// メンバ関数の定義

void Controller::SetState(){
	number = 0;
	for (int num = 0; num < MAX_CONTROLLER_NUM; num++) {
		previousState[num] = state[num];
 		number = (XInputGetState(num, &state[num]) == ERROR_SUCCESS ? number + 1 : number);
		if (0 < vibration.wRightMotorSpeed) {
			vibration.wRightMotorSpeed -= vibration_vel * Delta::getDeltaTime();
		}
		if (0 < vibration.wLeftMotorSpeed) {
			vibration.wLeftMotorSpeed -= vibration_vel * Delta::getDeltaTime();
		}
		if (vibration.wLeftMotorSpeed < 8000) {
			vibration.wLeftMotorSpeed = 0;
		}
		if (vibration.wRightMotorSpeed < 8000) {
			vibration.wRightMotorSpeed = 0;
		}
		XInputSetState(num, &vibration);
	}
}

bool Controller::IsUse() {
	int x = 0, y = 0;
	GetRightStick(0, x, y);
	if (x != 0 || y != 0) {
		return true;
	}
	GetLeftStick(0, x, y);
	if (x != 0 || y != 0) {
		return true;
	}
	if (number != 0) {
		for (int num = 0; num < number; num++) {
			if (
				state[number].Gamepad.wButtons != 0 ||
				state[number].Gamepad.bRightTrigger != 0 ||
				state[number].Gamepad.bLeftTrigger != 0 ||
				(state[number].Gamepad.sThumbRX <  rightStickDeadZone[number] && state[number].Gamepad.sThumbRX > -rightStickDeadZone[number]) ||
				(state[number].Gamepad.sThumbRY <  rightStickDeadZone[number] && state[number].Gamepad.sThumbRY > -rightStickDeadZone[number]) ||
				(state[number].Gamepad.sThumbLX <  rightStickDeadZone[number] && state[number].Gamepad.sThumbLX > -rightStickDeadZone[number]) ||
				(state[number].Gamepad.sThumbLY <  rightStickDeadZone[number] && state[number].Gamepad.sThumbLY > -rightStickDeadZone[number])){
				return true;
				}
		}
	}
	return false;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Controller::SetTriggerDeadZone(int number, int deadzone) {
	if (number < MAX_CONTROLLER_NUM) {
		triggerDeadZone[number] = deadzone;
		return true;
	}
	return false;
}

bool Controller::SetRightStickDeadZone(int number, int deadzone) {
	if (number < MAX_CONTROLLER_NUM) {
		rightStickDeadZone[number] = deadzone;
		return true;
	}
	return false;
}

bool Controller::SetLeftStickDeadZone(int number, int deadzone) {
	if (number < MAX_CONTROLLER_NUM) {
		leftStickDeadZone[number] = deadzone;
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Controller::IsTriggerButton(int number, Button button){
	if (number < MAX_CONTROLLER_NUM) {
		if (button != rTrigger && button != lTrigger) {
			return (state[number].Gamepad.wButtons & button) &&
				!(previousState[number].Gamepad.wButtons & button);
		}
		if (button == rTrigger) {
			return (state[number].Gamepad.bRightTrigger > triggerDeadZone[number]) &&
				!(previousState[number].Gamepad.bRightTrigger > triggerDeadZone[number]);
		}
		if (button == lTrigger) {
			return (state[number].Gamepad.bLeftTrigger > triggerDeadZone[number]) &&
				!(previousState[number].Gamepad.bLeftTrigger > triggerDeadZone[number]);
		}
	}
	return false;
}

bool Controller::IsPressedButton(int number, Button button){
	if (number < MAX_CONTROLLER_NUM) {
		if (button != rTrigger && button != lTrigger) {
			return (state[number].Gamepad.wButtons & button);
		}
		if (button == rTrigger) {
			return (state[number].Gamepad.bRightTrigger > triggerDeadZone[number]);
		}
		if (button == lTrigger) {
			return (state[number].Gamepad.bLeftTrigger > triggerDeadZone[number]);
		}
	}
	return false;
}

bool Controller::IsReleaseButton(int number, Button button){
	if (number < MAX_CONTROLLER_NUM) {
		if (button != rTrigger && button != lTrigger) {
			return !(state[number].Gamepad.wButtons & button) &&
				(previousState[number].Gamepad.wButtons & button);
		}
		if (button == rTrigger) {
			return !(state[number].Gamepad.bRightTrigger > triggerDeadZone[number]) &&
				(previousState[number].Gamepad.bRightTrigger > triggerDeadZone[number]);
		}
		if (button == lTrigger) {
			return !(state[number].Gamepad.bLeftTrigger > triggerDeadZone[number]) &&
				(previousState[number].Gamepad.bLeftTrigger > triggerDeadZone[number]);
		}
	}
	return false;
}

bool Controller::IsStickDirection(int number, StickDirection direction) {
	if (number < MAX_CONTROLLER_NUM) {
		switch (direction)
		{
		case Controller::lsdUP:
			return state[number].Gamepad.sThumbLY >= leftStickDeadZone[number] ? true : false;
			break;
		case Controller::lsdDOWN:
			return state[number].Gamepad.sThumbLY <= -leftStickDeadZone[number] ? true : false;
			break;
		case Controller::lsdRIGHT:
			return state[number].Gamepad.sThumbLX >= leftStickDeadZone[number] ? true : false;
			break;
		case Controller::lsdLEFT:
			return state[number].Gamepad.sThumbLX <= -leftStickDeadZone[number] ? true : false;
			break;
		case Controller::rsdUP:
			return state[number].Gamepad.sThumbRY >= rightStickDeadZone[number] ? true : false;
			break;
		case Controller::rsdDOWN:
			return state[number].Gamepad.sThumbRY >= -rightStickDeadZone[number] ? true : false;
			break;
		case Controller::rsdRIGHT:
			return state[number].Gamepad.sThumbRX >= leftStickDeadZone[number] ? true : false;
			break;
		case Controller::rsdLEFT:
			return state[number].Gamepad.sThumbRX <= -leftStickDeadZone[number] ? true : false;
			break;
		default:
			break;
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Controller::GetRightTrigger(int number, int& out) {
	if (number < MAX_CONTROLLER_NUM) {
		if (state[number].Gamepad.bRightTrigger > triggerDeadZone[number]) {
			out = state[number].Gamepad.bRightTrigger;
		}
		else {
			out = 0;
		}
		return true;
	}
	return false;
}

bool Controller::GetLeftTrigger(int number, int& out){
	if (number < MAX_CONTROLLER_NUM) {
		if (state[number].Gamepad.bLeftTrigger > triggerDeadZone[number]) {
			out = state[number].Gamepad.bLeftTrigger;
		}
		else {
			out = 0;
		}
		return true;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Controller::GetRightStick(int number, int& outx, int& outy){
	if (number < MAX_CONTROLLER_NUM) {
		if ((state[number].Gamepad.sThumbRX <  rightStickDeadZone[number] &&
			state[number].Gamepad.sThumbRX > -rightStickDeadZone[number]) &&
			(state[number].Gamepad.sThumbRY <  rightStickDeadZone[number] &&
				state[number].Gamepad.sThumbRY > -rightStickDeadZone[number])) {
			outx = 0;
			outy = 0;
		}
		else {
			outx = state[number].Gamepad.sThumbRX;
			outy = state[number].Gamepad.sThumbRY;
		}
		return true;
	}
	return false;
}

bool Controller::GetRightStick(int number, StickMagnitude& out) {
	return GetRightStick(number, out.x, out.y);
}

bool Controller::GetLeftStick(int number, int& outx, int& outy){
	if (number < MAX_CONTROLLER_NUM) {
		if ((state[number].Gamepad.sThumbLX <  rightStickDeadZone[number] &&
			state[number].Gamepad.sThumbLX > -rightStickDeadZone[number]) &&
			(state[number].Gamepad.sThumbLY <  rightStickDeadZone[number] &&
				state[number].Gamepad.sThumbLY > -rightStickDeadZone[number])) {
			outx = 0;
			outy = 0;
		}
		else {
			outx = state[number].Gamepad.sThumbLX;
			outy = state[number].Gamepad.sThumbLY;
		}
		return true;
	}
	return false;
}

bool Controller::GetLeftStick(int number, StickMagnitude& out) {
	return GetLeftStick(number, out.x, out.y);
}

void Controller::isVibration(int vel) {
	vibration_vel = vel;
	vibration.wLeftMotorSpeed = static_cast<int>(USHRT_MAX * Datas::VIBRATION);
	vibration.wRightMotorSpeed = static_cast<int>(USHRT_MAX * Datas::VIBRATION);
	XInputSetState(0, &vibration);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////