#pragma once
#include "Vector2D.h"

enum FieldType {
	// フィールド無し
	NoneField,
	DestroyCircle,
};

class BaseField
{
public:
	/// @brief デフォルトコンストラクタ
	BaseField();
	/// @brief コンストラクタ
	BaseField(class Game& game);
	/// @brief 引数ありコンストラクタ
	BaseField(Game& game, Vector2D pos, Vector2D wid);
	/// @brief デストラクタ
	~BaseField();

	// 継承用

	/// @brief 初期化処理
	virtual void Init();

	// マネージャー操作用

	/// @brief 初期化処理
	void BaseInit();
	/// @brief 初期化処理
	void BaseInit(Vector2D pos, Vector2D wid);

	// ゲッターセッター

	/// @brief 座標をセットする関数
	void SetPositon(Vector2D pos) { position = pos; }
	/// @brief 座標
	Vector2D GetPositon() { return position; }
	/// @brief 幅をセットする関数
	void SetWidth(Vector2D wid) { width = wid; }
	/// @brief 幅
	Vector2D GetWidth() { return width; }
	/// @brief フィールドを削除する関数
	void SetEnd() { isEnd = true; }
	/// @brief フィールドを削除されているか
	bool GetIsEnd() { return isEnd; }

protected:
	// 座標
	Vector2D position;
	// 幅
	Vector2D width;

	// 終了したか
	bool isEnd;

	// ゲームのポインタ
	Game& pGame;
};