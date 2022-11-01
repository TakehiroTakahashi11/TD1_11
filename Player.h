#pragma once
#include "Obj.h"
#include "Vector2D.h"
#include "ControllerInput.h"

class Player : public Obj
{
public:
	/// @brief コンストラクタ
	/// @param pGame ゲームのポインタ
	Player(class Game& pGame);

	/// @brief 初期化処理
	void Init() override;

	/// @brief 更新処理
	void Update() override;

	/// @brief 描画処理
	void Draw() override;

	enum DashLevel {
		Dash1,
		Dash2,
		Dash3
	};

private:
	/// @brief 移動処理
	void Move();

private:
	// 座標
	Vector2D position;

	// 幅
	float width;
	// 高さ
	float height;

};