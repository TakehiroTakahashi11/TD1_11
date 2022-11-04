#pragma once
#include "GameObject.h"

class Map : public GameObject
{
public:
	Map(class Game& game);
	~Map();

	void Update();
	void Draw();

private:

};