#include "Delta.h"

Delta::Delta(){}
Delta::~Delta(){}

void Delta::Update() {
	// 現在時間を保存
	mNowTime = clock();
	// デルタタイム = 60 * /...
	mDeltaTime = kFPS * static_cast<float>((mNowTime - mOldTime)) / CLOCKS_PER_SEC;

	// 閾値
	if (mDeltaTime > 1.0f) {
		mDeltaTime = 1.0f;
	}

	// 次フレーム用に代入
	mOldTime = mNowTime;

	// ヒットストップ
	if (isHitStop) {
		if (0 < hitStopTime) {
			mDynDeltaTime = 0.1f;
			hitStopTime -= mDeltaTime;
		}
		else {
			hitStopTime = 0.0f;
			mDynDeltaTime = 1.0f;
			isHitStop = false;
		}
	}
}


// 初期化

float Delta::mDynDeltaTime = 1.0f;
float Delta::mDeltaTime = 1.0f;
clock_t Delta::mNowTime = 0;
clock_t Delta::mOldTime = 0;
float Delta::hitStopTime = 0.0f;
bool Delta::isHitStop = false;
