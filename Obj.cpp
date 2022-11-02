#include "Obj.h"

/// @brief コンストラクタ
/// @param pGame ゲームのポインタ
Obj::Obj(Game& pGame):GameObject(pGame)
{
	height = 0.0f;
	width = 0.0f;
}

/// @brief デストラクタ
Obj::~Obj(){}