#pragma once
#include "BaseBullet.h"
#include "Vector2D.h"

class BulletManager
{
public:
	/// @brief 初期化処理
	static void Init(class Game& Game);

	/// @brief 更新処理
	static void Update();

	/// @brief 描画処理
	static void Draw();

	/// @brief 終了処理
	static void Finalise();

	/// @brief 新規エフェクトを生成
	/// @param position 生成座標
	/// @param effectType 生成するEffectType::
	/// @return 管理用のint変数
	static int MakeNewBullet(Vector2D position, BulletType bulletType);

	/// @brief エフェクトを終了させる関数
	static void SetEnd(int effectNum);

	/// @brief エフェクトが終了したか
	static bool GetIsEnd(int effectNum);

private:
	BulletManager();

public:

private:
	// 配列のサイズ
	const static int bulletArraySize = 256;

	// アップキャスト用配列
	static BaseBullet* bullets[bulletArraySize];

	// 添字
	static int nextIndex;

	// ゲームのポインタ
	static Game* pGame;
};