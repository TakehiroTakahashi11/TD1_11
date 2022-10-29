#pragma once
#include "Camera.h"

class BaseScene;

// ゲーム本体
class Game
{
public:
	/// @brief シーン
	enum Scene {
		kLoadScene,
		kInGameScene,

		kSceneNum
	};

	/// @brief フェーズ
	enum Process {
		kInit,
		kUpdate,
		kFinalise,

		kPhaseNum
	};

	/// @brief コンストラクタ
	Game();

	/// @brief デストラクタ
	~Game();

	Camera& getCameraMain();
	Camera& getCameraSub();
	Camera& getCameraUI();

	/// @brief メインループ
	void Run();

	/// @brief シーンチェンジ関数
	/// @param scene シーン
	void ChangeScene(Scene scene);

	/// @brief フェーズチェンジ関数(Init, Update, Finalise)
	void ChangePhase(Process process);

private:
	/// @brief フレーム開始
	void BeginFrame();

	/// @brief 更新処理
	void Update();

	/// @brief 描画
	void Draw();

	/// @brief フレーム終了
	void EndFrame();

public:

private:
	// カメラ
	Camera mCameraMain;
	Camera mCameraSub;
	Camera mCameraUI;

	// 現在のどのシーンか
	Scene mNowScene;
	// シーンのポインタ配列
	BaseScene* pScene[kSceneNum];

	// 現在どのフェーズか
	Process mNowPhase;
};