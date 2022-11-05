#include "Datas.h"
#include <Novice.h>
#include "KeyMouseInput.h"


Texture Datas::PLAYER_TEX = Texture(32, 32);
Texture Datas::GAUNTLET_TEX = Texture(64, 64);
Texture Datas::BOSS1_TEX = Texture(512, 560);
Texture Datas::EFFECTS_HIT_TEX = Texture(EFFECTS_HIT_SIZE, EFFECTS_HIT_SIZE);
Texture Datas::EFFECTS_THUNDER_TEX = Texture(400, 400);
Texture Datas::BOSS_ATTACK1_TEX = Texture(32, 32);
Texture Datas::MAP_TEX = Texture(64, 64);
Texture Datas::BackGroundTex = Texture(1920, 1080);

void Datas::LoadTexture()
{
	PLAYER_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player.png"));
	Per++;
	GAUNTLET_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet.png"));
	Per++;
	BOSS1_TEX.SetHandle(Novice::LoadTexture("./Resources/Boss/Boss1.png"));
	Per++;
	EFFECTS_HIT_TEX.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	EFFECTS_THUNDER_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Thunder/Thunder.png"));
	Per++;
	BOSS_ATTACK1_TEX.SetHandle(Novice::LoadTexture("./Resources/Bullet/Bullet.png"));
	Per++;
	MAP_TEX.SetHandle(Novice::LoadTexture("./Resources/Map/ChipTile.png"));
	Per++;
	BackGroundTex.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	IsEnd = true;
}

int Datas::Per = 0;
const int Datas::Max_Per = 7;
bool Datas::IsEnd = false;