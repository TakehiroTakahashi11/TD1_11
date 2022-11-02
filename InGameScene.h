#pragma once
#include "BaseScene.h"

class InGameScene : public BaseScene
{
public:
	InGameScene(Game& pGame);

	void Init() override;
	void Update() override;
	void Draw() override;
	void Finalise() override;

private:

};