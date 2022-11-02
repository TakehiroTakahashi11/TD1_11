#include "Datas.h"
#include <Novice.h>
#include "KeyMouseInput.h"


Texture Datas::PLAYER_UP_TEX = Texture(32, 32);
Texture Datas::PLAYER_DOWN_TEX = Texture(32, 32);
Texture Datas::PLAYER_LEFT_TEX = Texture(32, 32);
Texture Datas::PLAYER_RIGHT_TEX = Texture(32, 32);
Texture Datas::PLAYER_UP_LEFT_TEX = Texture(32, 32);
Texture Datas::PLAYER_UP_RIGHT_TEX = Texture(32, 32);
Texture Datas::PLAYER_DOWN_LEFT_TEX = Texture(32, 32);
Texture Datas::PLAYER_DOWN_RIGHT_TEX = Texture(32, 32);
Texture Datas::GAUNTLET_TEX = Texture(GAUNTLET_WIDTH, GAUNTLET_HEIGHT);
Texture Datas::BOSS_TEX = Texture(BOSS_WIDTH, BOSS_HEIGHT);
Texture Datas::MouseTex = Texture(16, 16);
Texture Datas::BackGroundTex = Texture(1920, 1080);

void Datas::LoadTexture()
{
	PLAYER_UP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Up.png"));
	Per++;
	PLAYER_DOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Down.png"));
	Per++;
	PLAYER_LEFT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Left.png"));
	Per++;
	PLAYER_RIGHT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Right.png"));
	Per++;
	PLAYER_UP_LEFT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_UpLeft.png"));
	Per++;
	PLAYER_UP_RIGHT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_UpRight.png"));
	Per++;
	PLAYER_DOWN_LEFT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_DownLeft.png"));
	Per++;
	PLAYER_DOWN_RIGHT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_DownRight.png"));
	Per++;
	GAUNTLET_TEX.SetHandle(Novice::LoadTexture("white1x1.png"));
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
const int Datas::Max_Per = 12;
bool Datas::IsEnd = false;