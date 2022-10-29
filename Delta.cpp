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
}


// 初期化

float Delta::mDynDeltaTime = 1.0f;
float Delta::mDeltaTime = 1.0f;
clock_t Delta::mNowTime = 0;
clock_t Delta::mOldTime = 0;