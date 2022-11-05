#include "Map.h"
#include "Game.h"
#include "Camera.h"
#include "Datas.h"

Map::Map(Game& game) : GameObject(game)
{
	map_num = 1;
}

Map::~Map()
{
}

void Map::Draw()
{
	switch (map_num)
	{
	case 0:
		for (int x = 0; x < Datas::STAGE0_MAP_X; x++) {
			for (int y = 0; y < Datas::STAGE0_MAP_Y; y++) {
				getCameraMain().DrawQuad({ {Datas::MAP_SIZE * x - Datas::STAGE0_WIDTH, Datas::MAP_SIZE * y - Datas::STAGE0_HEIGHT},Datas::MAP_SIZE ,Datas::MAP_SIZE }, Datas::MAP_TEX, 0);
			}
		}
		break;
	case 1:
		for (int x = 0; x < Datas::STAGE1_MAP_X; x++) {
			for (int y = 0; y < Datas::STAGE1_MAP_Y; y++) {
				getCameraMain().DrawQuad({ {Datas::MAP_SIZE * x - Datas::STAGE1_WIDTH, Datas::MAP_SIZE * y - Datas::STAGE1_HEIGHT},Datas::MAP_SIZE ,Datas::MAP_SIZE }, Datas::MAP_TEX, 0);
			}
		}
		break;
	default:
		break;
	}
}

void Map::SetMapNum(int num)
{
	switch (num)
	{
	case 1:
		// 壁壊れるパーティクル
		break;
	default:
		break;
	}
	map_num = num;
}
