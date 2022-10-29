#include "Easing.h"
#define _USE_MATH_DEFINES
#include <math.h>

/// @brief デフォルトコンストラクタ
Easing::Easing() :Easing(0.0f, 1000.0f) {

}

/// @brief 引数ありコンストラクタ
/// @param start 開始値
/// @param end 終了値
Easing::Easing(float start,float end):
    start(start),
    end(end),
    velocity(0.1f),
    mode(kOutCubic),
    t(0.0f),
    delta(-1.0f),
    p(start)
{
}

/// @brief 引数ありコンストラクタ
/// @param start 開始値
/// @param end 終了値
Easing::Easing(float start, float end, float velocity) :
	start(start),
	end(end),
	velocity(velocity),
	mode(kOutCubic),
	t(0.0f),
	delta(-1.0f),
	p(start)
{
}

/// @brief 引数ありコンストラクタ
/// @param start 開始値
/// @param end 終了値
Easing::Easing(float start, float end, float velocity, Mode mode) :
	start(start),
	end(end),
	velocity(velocity),
	mode(mode),
	t(0.0f),
	delta(-1.0f),
	p(start)
{
}

/// @brief デストラクタ
Easing::~Easing(){}

// =====public======================================================

/// @brief 動作関数
/// @param deltatime 分からない方は入れなくて大丈夫
void Easing::Move(float deltatime=-1.0f){
    // デルタタイム保存
    delta = deltatime;

    // tをイージング
    float easedT = CalcT();

    // 線形補完
    p = LinearInter(start,end,easedT);

    // tを加算
    MoveT();
}

// ====private======================================================

/// @brief 線形補完関数
/// @param start 開始値
/// @param end 終了値
/// @param t 変化量 (0.0f ~ 1.0f)
/// @return 補完した値
float Easing::LinearInter(float start,float end,float t){
    return start * (1.0f - t) + end * t;
}

/// @brief t 加算関数
void Easing::MoveT(){
    if(t < 1.0f){
        if(delta < 0.0f){// デルタタイムが指定されていない時
            t += velocity;
        }
        else{// デルタタイムが指定されている時
            t += velocity * 60 * delta;
        }
    }
    else{
        t = 1.0f;
    }
}

/// @brief t イージング処理関数
/// @return EasedT
float Easing::CalcT(){
	float easedT = 0.0f;

	const float c1 = 1.70158f;
	const float c2 = c1 * 1.525f;
	const float c3 = c1 + 1.0f;
	const float c4 = (2.0f * static_cast<float>(M_PI)) / 3.0f;
	const float c5 = (2.0f * static_cast<float>(M_PI)) / 4.5f;
	const float n1 = 7.5625f;
	const float d1 = 2.75f;

	switch (mode)
	{
	case Easing::kInSine:
		easedT = 1.0f - cosf(static_cast<float>(t * M_PI) / 2.0f);
		break;
	case Easing::kOutSine:
		easedT = sinf(static_cast<float>(t * M_PI) / 2.0f);
		break;
	case Easing::kInOutSine:
		easedT = -(cosf(static_cast<float>(M_PI * t)) - 1.0f) / 2.0f;
		break;
	case Easing::kInQuad:
		easedT = t * t;
		break;
	case Easing::kOutQuad:
		easedT = 1.0f - (1.0f - t) * (1.0f - t);
		break;
	case Easing::kInOutQuad:
		easedT = t < 0.5f
			? 2.0f * t * t
			: 1.0f - powf(-2.0f * t + 2.0f, 2.0f) / 2.0f;
		break;
	case Easing::kInCubic:
		easedT = t * t * t;
		break;
	default:
	case Easing::kOutCubic:
		easedT = 1.0f - powf(1.0f - t, 3.0f);
		break;
	case Easing::kInOutCubic:
		easedT = t < 0.5f
			? 4.0f * t * t * t
			: 1.0f - powf(-2.0f * t + 2.0f, 3.0f) / 2.0f;
		break;
	case Easing::kInQuart:
		easedT = t * t * t * t;
		break;
	case Easing::kOutQuart:
		easedT = 1.0f - powf(1.0f - t, 4.0f);
		break;
	case Easing::kInOutQuart:
		easedT = t < 0.5f
			? 8.0f * t * t * t * t
			: 1.0f - powf(-2.0f * t + 2.0f, 4.0f) / 2.0f;
		break;
	case Easing::kInQuint:
		easedT = t * t * t * t * t;
		break;
	case Easing::kOutQuint:
		easedT = 1.0f - powf(1.0f - t, 5.0f);
		break;
	case Easing::kInOutQuint:
		easedT = t < 0.5f
			? 16.0f * t * t * t * t * t
			: 1.0f - powf(-2.0f * t + 2.0f, 5.0f) / 2.0f;
		break;
	case Easing::kInExpo:
		easedT = t == 0.0f
			? 0.0f : powf(2.0f, 10.0f * t - 10.0f);
		break;
	case Easing::kOutExpo:
		easedT = t == 1.0f
			? 1.0f : 1.0f - powf(2.0f, -10.0f * t);
		break;
	case Easing::kInCirc:
		easedT = 1.0f - sqrtf(1.0f - powf(t, 2.0f));
		break;
	case Easing::kOutCirc:
		easedT = sqrtf(1.0f - powf(t - 1.0f, 2.0f));
		break;
	case Easing::kInOutCirc:
		easedT = t < 0.5f
			? (1.0f - sqrtf(1.0f - powf(2.0f * t, 2.0f))) / 2.0f
			: (sqrtf(1.0f - powf(-2.0f * t + 2.0f, 2.0f)) + 1.0f) / 2.0f;
		break;
	case Easing::kInBack:
		easedT = c3 * t * t * t - c1 * t * t;
		break;
	case Easing::kOutBack:
		easedT = 1.0f + c3 * powf(t - 1.0f, 3.0f) + c1 * powf(t - 1.0f, 2.0f);
		break;
	case Easing::kInOutBack:
		easedT = t < 0.5f
			? (powf(2.0f * t, 2.0f) * ((c2 + 1.0f) * 2.0f * t - c2)) / 2.0f
			: (powf(2.0f * t - 2.0f, 2.0f) * ((c2 + 1.0f) * (t * 2.0f - 2.0f) + c2) + 2.0f) / 2.0f;
		break;
	case Easing::kInElastic:
		easedT = t = 0.0f
			? 0.0f
			: t = 1.0f
			? 1.0f
			: -powf(2.0f, 10.0f * t - 10.0f) * sinf((t * 10.0f - 10.75f) * c4);
		break;
	case Easing::kOutElastic:
		easedT = t == 0.0f
			? 0.0f
			: t = 1.0f
			? 1.0f
			: powf(2.0f, -10.0f * t) * sinf((t * 10.0f - 0.75f) * c4) + 1.0f;
		break;
	case Easing::kInOutElastic:
		easedT = t == 0.0f
			? 0.0f
			: t = 1.0f
			? 1.0f
			: t < 0.5f
			? -(powf(2.0f, 20.0f * t - 10.0f) * sinf((20.0f * t - 11.125f) * c5)) / 2.0f
			: (powf(2.0f, -20.0f * t + 10.0f) * sinf((20.0f * t - 11.125f) * c5)) / 2.0f + 1.0f;
		break;
	case Easing::kInBounce:
		easedT = 1.0f - OutBounce(1.0f - t);
		break;
	case Easing::kOutBounce:
		easedT = 0.0f;
		if (t < 1.0f / d1) {
			easedT = n1 * t * t;
		}
		else if (t < 2.0f / d1) {
			easedT = n1 * (t -= 1.5f / d1) * t + 0.75f;
		}
		else if (t < 2.5f / d1) {
			easedT = n1 * (t -= 2.25f / d1) * t + 0.9375f;
		}
		else {
			easedT = n1 * (t -= 2.625f / d1) * t + 0.984375f;
		}
		break;
	case Easing::kInOutBounce:
		easedT = t < 0.5f
			? (1.0f - OutBounce(1.0f - 2.0f * t)) / 2.0f
			: (1.0f + OutBounce(2.0f * t - 1.0f)) / 2.0f;
		break;
	}

    return easedT;
}

float Easing::OutBounce(float t) {
	const float n1 = 7.5625f;
	const float d1 = 2.75f;

	if (t < 1.0f / d1) {
		return n1 * t * t;
	}
	else if (t < 2.0f / d1) {
		return n1 * (t -= 1.5f / d1) * t + 0.75f;
	}
	else if (t < 2.5f / d1) {
		return n1 * (t -= 2.25f / d1) * t + 0.9375f;
	}
	else {
		return n1 * (t -= 2.625f / d1) * t + 0.984375f;
	}
}