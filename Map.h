#pragma once
#include "GameObject.h"

class Map : public GameObject
{
public:
	Map(class Game& game);
	~Map();

	void Draw();

	void SetMapNum(int num);

private:
	int map_num;
};