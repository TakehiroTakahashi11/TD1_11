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

	/// @brief アニメーション関数
	void Animation();

public://ゲッターセッター

	Vector2D GetPosition() { return position; }
	bool GetIsBreak() { return isBreak; }

private:// 耐久力
	float health;

	// ガードアニメーション角度
	float guard_dir;
	// ダッシュアニメーション
	float dash_dis;
	float dash_dir;

	// アニメーション
	int x_anim;

	// 壊れているか
	bool isBreak;
};