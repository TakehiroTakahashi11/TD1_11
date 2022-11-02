#pragma once
#include "GameObject.h"

// シ－ン 基底クラス
class BaseScene : public GameObject
{
public:
	BaseScene(class Game* pGame);
	virtual ~BaseScene();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Finalise() = 0;
};