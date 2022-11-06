#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class Map : public GameObject
{
public:
	Map(class Game& game);
	~Map();

	void Draw();

	void SetMapNum(int num);
	int GetMapNum() { return map_num; }

	bool IsWall(Vector2D pos, Vector2D size);

private:
	int map_num;
};