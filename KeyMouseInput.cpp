#include "KeyMouseInput.h"
#include "Texture.h"

char Key::keys[256] = { 0 };
char Key::preKeys[256] = { 0 };

bool Mouse::Buttons[MOUSEBUTTONNUM] = { 0 };
bool Mouse::preButtons[MOUSEBUTTONNUM] = { 0 };

Vector2D Mouse::position = { 0.0f,0.0f };
int Mouse::animation = NULL;
int Mouse::anim_count = NULL;

void Key::SetState() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

bool Key::IsUse(){
	for(int i = 0; i < 256; i++){
		if(keys[i] != 0){
			return true;
		}
	}
	return false;
}


bool Key::IsEmpty(int keyCode) {
	if (preKeys[keyCode] == 0 && keys[keyCode] == 0) {
		return true;
	}
	return false;
}

bool Key::IsTrigger(int keyCode) {
	if (preKeys[keyCode] == 0 && keys[keyCode] != 0) {
		return true;
	}
	return false;
}

bool Key::IsPressed(int keyCode) {
	if (keys[keyCode] != 0) {
		return true;
	}
	return false;
}

bool Key::IsRelease(int keyCode) {
	if (preKeys[keyCode] != 0 && keys[keyCode] == 0) {
		return true;
	}
	return false;
}



void Mouse::SetState() {
	for (int num = 0; num < MOUSEBUTTONNUM; num++) {
		preButtons[num] = Buttons[num];
		Buttons[num] = Novice::IsPressMouse(num);
		if (Buttons[num]) {
			anim_count = 15;
		}
	}
	int x = 0;
	int y = 0;
	Novice::GetMousePosition(&x, &y);
	position = { static_cast<float>(x),static_cast<float>(y) };
	anim_count > 0 ? anim_count-- : anim_count = 0;
	anim_count == 0 ? animation = 0 : animation = 1;
}

bool Mouse::IsEmptyButton(int buttonNumber) {
	if (preButtons[buttonNumber] == 0 && Buttons[buttonNumber] == 0) {
		return true;
	}
	return false;
}

bool Mouse::IsTriggerButton(int buttonNumber) {
	if (preButtons[buttonNumber] == 0 && Buttons[buttonNumber] != 0) {
		return true;
	}
	return false;
}

bool Mouse::IsPressedButton(int buttonNumber) {
	if (preButtons[buttonNumber] != 0) {
		return true;
	}
	return false;
}

bool Mouse::IsReleaseButton(int buttonNumber) {
	if (preButtons[buttonNumber] != 0 && Buttons[buttonNumber] == 0) {
		return true;
	}
	return false;
}

int Mouse::GetMouseWheel() {
	return Novice::GetWheel();
}

void Mouse::Draw(Texture& tex) {
	Novice::DrawQuad(static_cast<int>(position.x), static_cast<int>(position.y),
		static_cast<int>(position.x + tex.width), static_cast<int>(position.y),
		static_cast<int>(position.x), static_cast<int>(position.y + tex.height),
		static_cast<int>(position.x + tex.width), static_cast<int>(position.y + tex.height),
		tex.width * animation, 0, tex.width, tex.height, tex.GetHandle(), 0xFFFFFFFF);
}