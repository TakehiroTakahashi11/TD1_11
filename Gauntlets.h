#pragma once
#include "Obj.h"

class Gauntlets : public Obj
{
public:
	Gauntlets(class Game& game);
	~Gauntlets();

	void Init() override;
	void Update() override;
	void Draw() override;

	bool GetIsBreak() { return isBreak; }

private:
	// 座標
	Vector2D gauntlets_pos;

	// 耐久力
	

	// アニメーション
	int x_anim;

	// 壊れているか
	bool isBreak;
};