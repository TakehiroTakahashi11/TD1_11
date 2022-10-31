#pragma once
#include "Obj.h"
#include "Vector2D.h"

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

private:
	/// @brief 座標
	Vector2D position;

	/// @brief 移動量
	Vector2D velocity;
};