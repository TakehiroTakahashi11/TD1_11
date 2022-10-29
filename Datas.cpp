#include "Datas.h"
#include <Novice.h>
#include "KeyMouseInput.h"

Texture Datas::MouseTex = Texture(16, 16);
Texture Datas::BackGroundTex = Texture(1920, 1080);

void Datas::LoadTexture()
{
	MouseTex.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	BackGroundTex.SetHandle(Novice::LoadTexture("white1x1.png"));
	Per++;
	IsEnd = true;
}

int Datas::Per = 0;
const int Datas::Max_Per = 2;
bool Datas::IsEnd = false;