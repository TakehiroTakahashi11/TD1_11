#pragma once
#pragma once
#include "BaseField.h"

class FieldManager
{
public:
	/// @brief 初期化処理
	static void Init(class Game& Game);

	/// @brief 終了処理
	static void Finalise();

	/// @brief フィールドを生成
	/// @param position 生成座標
	/// @param effectType 生成するEffectType::
	/// @return 管理用のint変数
	static int MakeNewField(Vector2D position, Vector2D width, FieldType fieldType);

	/// @brief そこがフィールドか
	/// @param position 判定する座標
	/// @param effectType 判定するEffectType::
	/// @return フィールドならtrue | でないならfalse
	static bool IsField(Vector2D position, FieldType fieldType);

	/// @brief 座標を変更する関数
	static void SetPosition(int fieldNum, Vector2D position);
	/// @brief 座標を変更する関数
	static void SetWidth(int fieldNum, Vector2D width);

	/// @brief エフェクトを終了させる関数
	static void SetEnd(int fieldNum);

	/// @brief エフェクトが終了したか
	static bool GetIsEnd(int fieldNum);

private:
	FieldManager();
	static bool isHit(Vector2D t, Vector2D pos, Vector2D wid, FieldType fieldType);
	static bool CollisionBox(Vector2D t, Vector2D pos, Vector2D wid);
	static bool CollisionCircle(Vector2D t, Vector2D pos, Vector2D wid);

public:

private:
	// 配列のサイズ
	const static int fieldArraySize = 64;

	// アップキャスト用配列
	static BaseField* fields[fieldArraySize];
	// 管理用配列
	static FieldType fieldsNums[fieldArraySize];

	// 添字
	static int nextIndex;

	// ゲームのポインタ
	static Game* pGame;
};