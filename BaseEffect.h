#pragma once
#include "Vector2D.h"

enum EffectType {
	// エフェクト無し
	NoneEffect,
	kHit,
	kAtttack,
	kThunder,
	kPreThunder,
	kPlayerDash,
	kPlayerBoost,
};

class BaseEffect
{
public:
	/// @brief デフォルトコンストラクタ
	BaseEffect();
	/// @brief コンストラクタ
	BaseEffect(class Game& game);
	/// @brief 引数ありコンストラクタ
	BaseEffect(Game& game, Vector2D pos);
	/// @brief デストラクタ
	~BaseEffect();

	// 継承用

	/// @brief 初期化処理
	virtual void Init();
	/// @brief 更新処理
	virtual void Update();
	/// @brief 描画処理
	virtual void Draw();

	// マネージャー操作用

	/// @brief 初期化処理
	void BaseInit();
	/// @brief 初期化処理
	void BaseInit(Vector2D pos);
	/// @brief 更新処理
	void BaseUpdate();
	/// @brief 描画処理
	void BaseDraw();

	// ゲッターセッター

	/// @brief エフェクトを終了させる関数
	void SetEnd() { isEnd = true; }
	/// @brief エフェクトが終わっているか
	bool GetIsEnd() { return isEnd; }

	/// @brief メインカメラを取得する関数
	class Camera& getCameraMain();
	/// @brief サブカメラを取得する関数
	Camera& getCameraSub();
	/// @brief UIカメラを取得する関数
	Camera& getCameraUI();

protected:
	// 座標
	Vector2D position;
	// 経過フレーム
	float elapsedFrame;

	// 終了したか
	bool isEnd;

	// ゲームのポインタ
	Game& pGame;
};