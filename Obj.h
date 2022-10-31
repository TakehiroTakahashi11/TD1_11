#pragma once
#include "GameObject.h"

class Obj : public GameObject
{
public:
	/// @brief コンストラクタ
	/// @param pGame ゲームのポインタ
	Obj(class Game& pGame);

	/// @brief デストラクタ
	virtual ~Obj();

	/// @brief 初期化処理
	virtual void Init() = 0;

	/// @brief 更新処理
	virtual void Update() = 0;

	/// @brief 描画処理
	virtual void Draw() = 0;
private:

};