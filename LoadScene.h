#pragma once
#include "BaseScene.h"
#include <thread>

class LoadScene : public BaseScene
{
public:
	LoadScene(Game& pGame);

	void Init() override;
	void Update() override;
	void Draw() override;
	void Finalise() override;

private:
	std::thread mThread;
};