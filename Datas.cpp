#include "Datas.h"
#include <Novice.h>
#include "KeyMouseInput.h"

Texture Datas::PLAYER_TEX = Texture(PLAYER_WIDTH, PLAYER_HEIGHT);
Texture Datas::BOSS_TEX = Texture(BOSS_WIDTH, BOSS_HEIGHT);
Texture Datas::MouseTex = Texture(16, 16);
Texture Datas::BackGroundTex = Texture(1920, 1080);

void Datas::LoadTexture()
{
	PLAYER_TEX.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	BOSS_TEX.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	MouseTex.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	BackGroundTex.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	IsEnd = true;
}

int Datas::Per = 0;
const int Datas::Max_Per = 4;
bool Datas::IsEnd = false;