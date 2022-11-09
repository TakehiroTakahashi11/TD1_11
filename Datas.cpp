#include "Datas.h"
#include <Novice.h>
#include "KeyMouseInput.h"


Texture Datas::PLAYER_TEX = Texture(64, 64);
Texture Datas::PLAYER_DASH_TEX = Texture(64, 64);
Texture Datas::GAUNTLET_TEX = Texture(128, 128);
Texture Datas::BOSS1_TEX = Texture(512, 560);
Texture Datas::BOSS1_VINNET_TEX = Texture(512, 560);
Texture Datas::EFFECTS_HIT_TEX = Texture(EFFECTS_HIT_SIZE, EFFECTS_HIT_SIZE);
Texture Datas::EFFECTS_ATK_TEX = Texture(EFFECTS_ATK_SIZE, EFFECTS_ATK_SIZE);
Texture Datas::EFFECTS_THUNDER_TEX = Texture(400, 400);
Texture Datas::EFFECTS_THUNDER_VINNET_TEX = Texture(400, 400);
Texture Datas::EFFECTS_PRETHUNDER_TEX = Texture(400, 400);
Texture Datas::BOSS_ATTACK1_TEX = Texture(32, 32);
Texture Datas::BULLET_DEATH_TEX = Texture(32, 32);
Texture Datas::MAGIC_CIRCLE_TEX = Texture(256, 256);
Texture Datas::MAGIC_CIRCLE_VINNET_TEX = Texture(512, 512);
Texture Datas::PLAYER_BOOST_TEX = Texture(32, 32);
Texture Datas::MAP_TEX = Texture(64, 64);
Texture Datas::VINETT_TEX = Texture(1920, 1080);
Texture Datas::BackGroundTex = Texture(1920, 1080);

void Datas::LoadTexture()
{
	PLAYER_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player.png"));
	Per++;
	PLAYER_DASH_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Dash.png"));
	Per++;
	GAUNTLET_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet.png"));
	Per++;
	BOSS1_TEX.SetHandle(Novice::LoadTexture("./Resources/Boss/Boss1.png"));
	Per++;
	BOSS1_VINNET_TEX.SetHandle(Novice::LoadTexture("./Resources/Boss/BossVinnet.png"));
	Per++;
	EFFECTS_HIT_TEX.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	EFFECTS_ATK_TEX.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	EFFECTS_THUNDER_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Thunder/Thunder.png"));
	Per++;
	EFFECTS_THUNDER_VINNET_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Thunder/ThunderVinnet.png"));
	Per++;
	EFFECTS_PRETHUNDER_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Thunder/PreThunder.png"));
	Per++;
	BOSS_ATTACK1_TEX.SetHandle(Novice::LoadTexture("./Resources/Bullet/Bullet.png"));
	Per++;
	BULLET_DEATH_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Bullet/BulletDeath.png"));
	Per++;
	PLAYER_BOOST_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Boost/Boost.png"));
	Per++;
	MAGIC_CIRCLE_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Thunder/MagicCircle.png"));
	Per++;
	MAGIC_CIRCLE_VINNET_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Thunder/MagicCircleVinnet.png"));
	Per++;
	MAP_TEX.SetHandle(Novice::LoadTexture("./Resources/Map/ChipTile.png"));
	Per++;
	VINETT_TEX.SetHandle(Novice::LoadTexture("./Resources/UI/Vinetting.png"));
	Per++;
	BackGroundTex.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	IsEnd = true;
}

int Datas::Per = 0;
const int Datas::Max_Per = 18;
bool Datas::IsEnd = false;