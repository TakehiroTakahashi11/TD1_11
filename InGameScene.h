#pragma once
#include "BaseScene.h"
#include "Easing.h"

class InGameScene : public BaseScene
{
public:
	InGameScene(Game& pGame);

	void Init() override;
	void Update() override;
	void Draw() override;
	void Finalise() override;

private:
	int alpha;

	Easing uiY;
};