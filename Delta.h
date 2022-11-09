#pragma once
#include <time.h>

/// @brief デルタタイムクラス
class Delta
{
private:
	/// @brief 目標FPS
	static constexpr float kFPS = 60.0f;

	/// @brief 可変デルタタイム
	static float mDynDeltaTime;

	/// @brief デルタタイム
	static float mDeltaTime;

	/// @brief 現在フレームの時間
	static clock_t mNowTime;

	/// @brief 前のフレームの時間
	static clock_t mOldTime;
public:
	/// @brief 更新(デルタタイムをアップデート)
	static void Update();
	/// @brief ゲッター
	static float getDeltaTime() { return mDeltaTime; }
	static float getDynDelta() { return mDynDeltaTime; }
	static float getTotalDelta() { return mDeltaTime * mDynDeltaTime; }

	/// @brief セッター
	static void SetDynDelta(float dyn) { mDynDeltaTime = dyn; }
	static void MoveDynDelta(float dyn) { mDynDeltaTime += dyn; if (mDynDeltaTime < 0.1f) { mDynDeltaTime = 0.1f; } if (1.0f < mDynDeltaTime) { mDynDeltaTime = 1.0f; }	}
private:
	Delta();
	~Delta();
};

