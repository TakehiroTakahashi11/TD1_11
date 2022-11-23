#include "Datas.h"
#include <Novice.h>
#include "KeyMouseInput.h"

Texture Datas::PLAYER_DASH_TEX = Texture(64, 64);

Texture Datas::PLAYER_UP_TEX = Texture(128, 128);
Texture Datas::PLAYER_DOWN_TEX = Texture(128, 128);
Texture Datas::PLAYER_LEFT_TEX = Texture(128, 128);
Texture Datas::PLAYER_RIGHT_TEX = Texture(128, 128);
Texture Datas::PLAYER_RIGHTUP_TEX = Texture(128, 128);
Texture Datas::PLAYER_LEFTUP_TEX = Texture(128, 128);
Texture Datas::PLAYER_RIGHTDOWN_TEX = Texture(128, 128);
Texture Datas::PLAYER_LEFTDOWN_TEX = Texture(128, 128);

Texture Datas::PLAYER_DASH_UP_TEX = Texture(128, 128);
Texture Datas::PLAYER_DASH_DOWN_TEX = Texture(128, 128);
Texture Datas::PLAYER_DASH_LEFT_TEX = Texture(128, 128);
Texture Datas::PLAYER_DASH_RIGHT_TEX = Texture(128, 128);
Texture Datas::PLAYER_DASH_RIGHTUP_TEX = Texture(128, 128);
Texture Datas::PLAYER_DASH_LEFTUP_TEX = Texture(128, 128);
Texture Datas::PLAYER_DASH_RIGHTDOWN_TEX = Texture(128, 128);
Texture Datas::PLAYER_DASH_LEFTDOWN_TEX = Texture(128, 128);

Texture Datas::PLAYER_BOOST_UP_TEX = Texture(128, 128);
Texture Datas::PLAYER_BOOST_DOWN_TEX = Texture(128, 128);
Texture Datas::PLAYER_BOOST_LEFT_TEX = Texture(128, 128);
Texture Datas::PLAYER_BOOST_RIGHT_TEX = Texture(128, 128);
Texture Datas::PLAYER_BOOST_RIGHTUP_TEX = Texture(128, 128);
Texture Datas::PLAYER_BOOST_LEFTUP_TEX = Texture(128, 128);
Texture Datas::PLAYER_BOOST_RIGHTDOWN_TEX = Texture(128, 128);
Texture Datas::PLAYER_BOOST_LEFTDOWN_TEX = Texture(128, 128);

Texture Datas::PLAYER_SHADOW_TEX = Texture(128, 128);

Texture Datas::GAUNTLET_UP_TEX = Texture(128, 128);
Texture Datas::GAUNTLET_DOWN_TEX = Texture(128, 128);
Texture Datas::GAUNTLET_LEFT_TEX = Texture(128, 128);
Texture Datas::GAUNTLET_RIGHT_TEX = Texture(128, 128);
Texture Datas::GAUNTLET_RIGHTUP_TEX = Texture(128, 128);
Texture Datas::GAUNTLET_LEFTUP_TEX = Texture(128, 128);
Texture Datas::GAUNTLET_RIGHTDOWN_TEX = Texture(128, 128);
Texture Datas::GAUNTLET_LEFTDOWN_TEX = Texture(128, 128);

Texture Datas::GAUNTLET_DASH_UP_TEX = Texture(512, 512);
Texture Datas::GAUNTLET_DASH_DOWN_TEX = Texture(512, 512);
Texture Datas::GAUNTLET_DASH_LEFT_TEX = Texture(512, 512);
Texture Datas::GAUNTLET_DASH_RIGHT_TEX = Texture(512, 512);
Texture Datas::GAUNTLET_DASH_RIGHTUP_TEX = Texture(512, 512);
Texture Datas::GAUNTLET_DASH_LEFTUP_TEX = Texture(512, 512);
Texture Datas::GAUNTLET_DASH_RIGHTDOWN_TEX = Texture(512, 512);
Texture Datas::GAUNTLET_DASH_LEFTDOWN_TEX = Texture(512, 512);

Texture Datas::BOSS1_leftSpear = Texture(512, 560);
Texture Datas::BOSS1_rightSpear = Texture(512, 560);

Texture Datas::BOSS1_body = Texture(512, 256);
Texture Datas::BOSS1_leftupArm = Texture(160, 112);
Texture Datas::BOSS1_rightupArm = Texture(160, 112);
Texture Datas::BOSS1_leftdownArm = Texture(192, 128);
Texture Datas::BOSS1_rightdownArm = Texture(192, 128);

Texture Datas::BOSS1_ring = Texture(128, 64);
Texture Datas::BOSS1_leg1 = Texture(224, 112);
Texture Datas::BOSS1_leg2 = Texture(272, 224);
Texture Datas::BOSS1_bodyBack = Texture(256, 256);
Texture Datas::BOSS1_VINNET_TEX = Texture(512, 560);

Texture Datas::EFFECTS_HIT_TEX = Texture(EFFECTS_HIT_SIZE, EFFECTS_HIT_SIZE);
Texture Datas::EFFECTS_ATK_TEX = Texture(EFFECTS_ATK_SIZE, EFFECTS_ATK_SIZE);
Texture Datas::EFFECTS_THUNDER_TEX = Texture(400, 400);
Texture Datas::EFFECTS_THUNDER_VINNET_TEX = Texture(400, 400);
Texture Datas::EFFECTS_PRETHUNDER_TEX = Texture(400, 400);

Texture Datas::BOSS_ATTACK1_TEX = Texture(32, 32);
Texture Datas::PRE_BULLET_TEX = Texture(200, 200);
Texture Datas::BULLET_DEATH_TEX = Texture(32, 32);
Texture Datas::BULLET_CIRCLE_TEX1 = Texture(256, 256);
Texture Datas::BULLET_CIRCLE_TEX2 = Texture(256, 256);
Texture Datas::BULLET_CIRCLE_TEX3 = Texture(256, 256);
Texture Datas::BULLET_CIRCLE_VINNET_TEX = Texture(256, 256);

Texture Datas::MAGIC_CIRCLE_TEX = Texture(256, 256);
Texture Datas::MAGIC_CIRCLE_VINNET_TEX = Texture(512, 512);

Texture Datas::PLAYER_BOOST_TEX = Texture(32, 32);

Texture Datas::PRE_RUSH_TEX = Texture(128, 512);
Texture Datas::RUSH_INDICATE_TEX = Texture(48, 48);

Texture Datas::MINE_TEX = Texture(64, 64);
Texture Datas::MINE_EXPLODE_TEX = Texture(64, 64);

Texture Datas::ENEMY1_TEX = Texture(64, 64);

Texture Datas::LAZER_TEX = Texture(400, 400);

Texture Datas::MAP_TEX = Texture(64, 64);

Texture Datas::VINETT_TEX = Texture(1920, 1080);
Texture Datas::UI_TEX = Texture(400, 160);
Texture Datas::UI_HEALTH_TEX = Texture(400, 160);
Texture Datas::CLEAR_TEX = Texture(700, 500);
Texture Datas::GAMEOVER_TEX = Texture(700, 500);

Texture Datas::BackGroundTex = Texture(1920, 1080);

Sound Datas::BOOST_SOUND = Sound(false, 0.05f);
Sound Datas::DASH_SOUND = Sound(false, 0.05f);
Sound Datas::EXPLOSION_SOUND = Sound(false, 0.05f);
Sound Datas::GUARD_SOUND = Sound(false, 0.05f);
Sound Datas::HIT_SOUND = Sound(false, 0.05f);
Sound Datas::PUNCH_SOUND = Sound(false, 0.05f);
Sound Datas::SPECIAL_SOUND = Sound(false, 0.05f);

Sound Datas::BOSS_BULLET_SOUND = Sound(false, 0.05f);
Sound Datas::BOSS_EXPLOSION_SOUND = Sound(false, 0.1f);
Sound Datas::BOSS_JUMP_SOUND = Sound(false, 0.2f);
Sound Datas::BOSS_LASER_SOUND = Sound(false, 0.2f);
Sound Datas::BOSS_RUSH_SOUND = Sound(false, 0.2f);
Sound Datas::BOSS_THUNDER_SOUND = Sound(false, 0.2f);

void Datas::LoadTexture()
{
	PLAYER_DASH_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Dash.png"));
	Per++;

	PLAYER_UP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Up.png"));
	Per++;
	PLAYER_DOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Down.png"));
	Per++;
	PLAYER_LEFT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Left.png"));
	Per++;
	PLAYER_RIGHT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Right.png"));
	Per++;
	PLAYER_RIGHTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_RightUp.png"));
	Per++;
	PLAYER_LEFTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_LeftUp.png"));
	Per++;
	PLAYER_RIGHTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_RightDown.png"));
	Per++;
	PLAYER_LEFTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_LeftDown.png"));
	Per++;

	PLAYER_DASH_UP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Up_Dash.png"));
	Per++;
	PLAYER_DASH_DOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Down_Dash.png"));
	Per++;
	PLAYER_DASH_LEFT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Left_Dash.png"));
	Per++;
	PLAYER_DASH_RIGHT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Right_Dash.png"));
	Per++;
	PLAYER_DASH_RIGHTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_RightUp_Dash.png"));
	Per++;
	PLAYER_DASH_LEFTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_LeftUp_Dash.png"));
	Per++;
	PLAYER_DASH_RIGHTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_RightDown_Dash.png"));
	Per++;
	PLAYER_DASH_LEFTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_LeftDown_Dash.png"));
	Per++;

	PLAYER_BOOST_UP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Up_Boost.png"));
	Per++;
	PLAYER_BOOST_DOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Down_Boost.png"));
	Per++;
	PLAYER_BOOST_LEFT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Left_Boost.png"));
	Per++;
	PLAYER_BOOST_RIGHT_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Right_Boost.png"));
	Per++;
	PLAYER_BOOST_RIGHTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_RightUp_Boost.png"));
	Per++;
	PLAYER_BOOST_LEFTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_LeftUp_Boost.png"));
	Per++;
	PLAYER_BOOST_RIGHTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_RightDown_Boost.png"));
	Per++;
	PLAYER_BOOST_LEFTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_LeftDown_Boost.png"));
	Per++;

	PLAYER_SHADOW_TEX.SetHandle(Novice::LoadTexture("./Resources/Player/Player_Shadow.png"));
	Per++;

	GAUNTLET_UP_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_Up.png"));
	Per++;
	GAUNTLET_DOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_Down.png"));
	Per++;
	GAUNTLET_LEFT_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_Left.png"));
	Per++;
	GAUNTLET_RIGHT_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_Right.png"));
	Per++;
	GAUNTLET_RIGHTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_RightUp.png"));
	Per++;
	GAUNTLET_LEFTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_LeftUp.png"));
	Per++;
	GAUNTLET_RIGHTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_RightDown.png"));
	Per++;
	GAUNTLET_LEFTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_LeftDown.png"));
	Per++;

	GAUNTLET_DASH_UP_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_Up_Dash.png"));
	Per++;
	GAUNTLET_DASH_DOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_Down_Dash.png"));
	Per++;
	GAUNTLET_DASH_LEFT_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_Left_Dash.png"));
	Per++;
	GAUNTLET_DASH_RIGHT_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_Right_Dash.png"));
	Per++;
	GAUNTLET_DASH_RIGHTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_RightUp_Dash.png"));
	Per++;
	GAUNTLET_DASH_LEFTUP_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_LeftUp_Dash.png"));
	Per++;
	GAUNTLET_DASH_RIGHTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_RightDown_Dash.png"));
	Per++;
	GAUNTLET_DASH_LEFTDOWN_TEX.SetHandle(Novice::LoadTexture("./Resources/Gauntlet/Gauntlet_LeftDown_Dash.png"));
	Per++;

	BOSS1_leftSpear.SetHandle(Novice::LoadTexture("./Resources/Boss/spear_left.png"));
	Per++;
	BOSS1_rightSpear.SetHandle(Novice::LoadTexture("./Resources/Boss/spear_right.png"));
	Per++;

	BOSS1_body.SetHandle(Novice::LoadTexture("./Resources/Boss/body.png"));
	Per++;
	BOSS1_leftupArm.SetHandle(Novice::LoadTexture("./Resources/Boss/leftup_arm.png"));
	Per++;
	BOSS1_rightupArm.SetHandle(Novice::LoadTexture("./Resources/Boss/rightup_arm.png"));
	Per++;
	BOSS1_leftdownArm.SetHandle(Novice::LoadTexture("./Resources/Boss/leftdown_arm.png"));
	Per++;
	BOSS1_rightdownArm.SetHandle(Novice::LoadTexture("./Resources/Boss/rightdown_arm.png"));
	Per++;

	BOSS1_ring.SetHandle(Novice::LoadTexture("./Resources/Boss/ring.png"));
	Per++;
	BOSS1_leg1.SetHandle(Novice::LoadTexture("./Resources/Boss/leg1.png"));
	Per++;
	BOSS1_leg2.SetHandle(Novice::LoadTexture("./Resources/Boss/leg2.png"));
	Per++;
	BOSS1_bodyBack.SetHandle(Novice::LoadTexture("./Resources/Boss/back_body.png"));
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
	PRE_BULLET_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Bullet/PreBullet.png"));
	Per++;
	BULLET_DEATH_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Bullet/BulletDeath.png"));
	Per++;
	BULLET_CIRCLE_TEX1.SetHandle(Novice::LoadTexture("./Resources/Effect/Bullet/MagicCircle1_Bullet.png"));
	Per++;
	BULLET_CIRCLE_TEX2.SetHandle(Novice::LoadTexture("./Resources/Effect/Bullet/MagicCircle2_Bullet.png"));
	Per++;
	BULLET_CIRCLE_TEX3.SetHandle(Novice::LoadTexture("./Resources/Effect/Bullet/MagicCircle3_Bullet.png"));
	Per++;
	BULLET_CIRCLE_VINNET_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Bullet/MagicCircle_Bullet_Vinnet.png"));
	Per++;

	PLAYER_BOOST_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Boost/Boost.png"));
	Per++;

	PRE_RUSH_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Rush/PreRush.png"));
	Per++;
	RUSH_INDICATE_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Rush/RushIndicate.png"));
	Per++;

	MINE_TEX.SetHandle(Novice::LoadTexture("./Resources/Enemy/LandMine_Enemy.png"));
	MINE_EXPLODE_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Rush/PreRush.png"));

	ENEMY1_TEX.SetHandle(Novice::LoadTexture("./Resources/Enemy/Attack_Enemy.png"));

	LAZER_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Laser/Laser.png"));

	MAGIC_CIRCLE_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Thunder/MagicCircle.png"));
	Per++;
	MAGIC_CIRCLE_VINNET_TEX.SetHandle(Novice::LoadTexture("./Resources/Effect/Thunder/MagicCircleVinnet.png"));
	Per++;
	MAP_TEX.SetHandle(Novice::LoadTexture("./Resources/Map/ChipTile.png"));
	Per++;

	VINETT_TEX.SetHandle(Novice::LoadTexture("./Resources/UI/Vinetting.png"));
	Per++;
	UI_TEX.SetHandle(Novice::LoadTexture("./Resources/UI/Player_UI.png"));
	Per++;
	UI_HEALTH_TEX.SetHandle(Novice::LoadTexture("./Resources/UI/Player_Health.png"));
	Per++;
	CLEAR_TEX.SetHandle(Novice::LoadTexture("./Resources/UI/gameclear.png"));
	Per++;
	GAMEOVER_TEX.SetHandle(Novice::LoadTexture("./Resources/UI/gameover.png"));
	Per++;

	BackGroundTex.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;

	BOOST_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Player/boost.wav"));
	Per++;
	DASH_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Player/dash.wav"));
	Per++;
	EXPLOSION_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Player/explosion.wav"));
	Per++;
	GUARD_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Player/guard.wav"));
	Per++;
	HIT_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Player/hit.wav"));
	Per++;
	PUNCH_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Player/punch.wav"));
	Per++;
	SPECIAL_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Player/special.wav"));
	Per++;

	BOSS_BULLET_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Boss/bullet.wav"));
	Per++;
	BOSS_EXPLOSION_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Boss/explosion.wav"));
	Per++;
	BOSS_JUMP_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Boss/jump.wav"));
	Per++;
	BOSS_LASER_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Boss/laser.wav"));
	Per++;
	BOSS_RUSH_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Boss/rush.wav"));
	Per++;
	BOSS_THUNDER_SOUND.SetHandle(Novice::LoadAudio("./Resources/Sound/Boss/thunder.wav"));
	Per++;

	IsEnd = true;
}

int Datas::Per = 0;
const int Datas::Max_Per = 90;
bool Datas::IsEnd = false;