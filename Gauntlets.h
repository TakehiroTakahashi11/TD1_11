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

	bool ChargeAttack();

private:

public://ゲッターセッター

	Vector2D GetPosition() { return position; }

private:
	// ダッシュアニメーション
	float dash_dis;
	float dash_dis_acc;

	// アニメーション
	int x_anim;

	Vector2D chargePos;
	// チャージアタック
	float chargeAttackFrame;
	float chargeAttackSpeed;

	bool InitFlag;
};