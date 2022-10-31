#pragma once

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

	/// @brief メインループ
	void Run();

	/// @brief シーンチェンジ関数
	/// @param scene シーン
	void ChangeScene(Scene scene) { mNowScene = scene; }

	/// @brief フェーズチェンジ関数
	/// @param process (kInit, kUpdate, kFinalise)
	void ChangePhase(Process process){ mNowPhase = process; }

private:
	/// @brief フレーム開始
	void BeginFrame();

	/// @brief 更新処理
	void Update();

	/// @brief 描画
	void Draw();

	/// @brief フレーム終了
	void EndFrame();

private:
	// プレイヤー
	class Player* player;

	// カメラ
	class Camera* mCameraMain;
	Camera* mCameraSub;
	Camera* mCameraUI;

public:
	Player& getPlayer() { return *player; }
	Camera& getCameraMain() { return *mCameraMain; }
	Camera& getCameraSub() { return *mCameraSub; }
	Camera& getCameraUI() { return *mCameraUI; }
private:

	// 現在のどのシーンか
	Scene mNowScene;
	// シーンのポインタ配列
	BaseScene* pScene[kSceneNum];

	// 現在どのフェーズか
	Process mNowPhase;
};