#pragma once

/*
// =======================Sample======================

// インクルード==Easing.hとEasing.cppをファイルに入れ、使いたい所でインクルード=================================================
#include "Easing.h"

// 宣言==今回のEasingは基本的にはintや構造体、Vectorと同じもの(データ型)=======================================================
Easing piyo(0.0f, 100.0f);// 一番簡単な書き方、開始値と終了値のみ
// Easing piyo(0.0f, 100.0f, 0.05f);// 速度を設定したい場合
// Easing piyo(0.0f, 100.0f, 0.05f, Mode::kInQuad);// モードも設定したい場合、モードは https://easings.net/ja 

// 更新処理==Moveを使うと宣言した数値を使いイージングを計算して、結果を中に保存してくれる=========================================
piyo.Move();

// ※途中で内部の数値を変えたい場合、代入では無くSet系関数を使う
piyo.SetStart(10.0f);
//...

// イージングが終わっているかを判断する関数
if(piyo.IsEnd()){// <-------変数.IsEnd()
	//...
}

// 描画処理==イージング結果を取り出す際は変数名.p (Vectorのv.xやv.yと同じ)=====================================================
// Novice::Draw(piyo.p, y, //...);

// ====================================================
*/

class Easing
{
// ==変数===========================================================
public:
    // 列挙体 : イージングモード
	// 参照URL : https://easings.net/ja
	enum Mode {
		kNone,// 補完しない
		kInSine,
		kOutSine,
		kInOutSine,
		kInQuad,
		kOutQuad,
		kInOutQuad,
		kInCubic,
		kOutCubic,
		kInOutCubic,
		kInQuart,
		kOutQuart,
		kInOutQuart,
		kInQuint,
		kOutQuint,
		kInOutQuint,
		kInExpo,
		kOutExpo,
		kInCirc,
		kOutCirc,
		kInOutCirc,
		kInBack,
		kOutBack,
		kInOutBack,
		kInElastic,
		kOutElastic,
		kInOutElastic,
		kInBounce,
		kOutBounce,
		kInOutBounce
	};

	float p;// イージングされた値

private:
	float start;// 開始値
	float end;// 終了値
	float velocity;// tの増加量
	Mode mode;// イージングモード
	float t;// 0.0f ~ 1.0f
	float delta;// デルタタイム

// ==関数============================================================
public:
	/// @brief デフォルトコンストラクタ
    Easing();

	/// @brief 引数ありコンストラクタ
	/// @param start 開始値
	/// @param end 終了値
	Easing(float start,float end);

	/// @brief 引数ありコンストラクタ
	/// @param start 開始値
	/// @param end 終了値
	/// @param velocity 速度
	Easing(float start, float end, float velocity);

	/// @brief 引数ありコンストラクタ
	/// @param start 開始値
	/// @param end 終了値
	/// @param velocity 速度
	/// @param mode イージングモード
	Easing(float start, float end, float velocity, Mode mode);

	/// @brief デストラクタ
    ~Easing();

	// ==============================================================

	/// @brief 動作関数
	/// @param deltatime 分からない方は入れなくて大丈夫
	void Move(float deltatime);
	
	// ==ゲッター======================================================

	/// @brief イージングが終わっているか
	/// @return 終わっていたら : true , 終わっていなかったら : fakse
	bool IsEnd() const { return t >= 1.0f ? true : false; };
	
	/// @brief Startをゲットする
	/// @return 開始値
	float GetStart() const { return start; }

	/// @brief Endをゲットする
	/// @return 終了値
	float GetEnd() const { return end; }
	
	/// @brief tをゲットする
	/// @return 変化量
	float GetT() const { return t; }

	// ==セッター======================================================

	/// @brief Startをセットする ついでにtも0に戻る
	/// @param S 開始値
	void SetStart(float S){ t = 0.0f; start = S; }

	/// @brief Endをセットする ついでにtも良い感じになる
	/// @param E 終了値
	void SetEnd(float E){ end = E; t = (start - p)/(start - end); }

	/// @brief velocityをセットする
	/// @param Vel 速度
	void SetVel(float Vel){ velocity = Vel; }

	/// @brief モードをセットする
	/// @param Mode イージングモード
	void SetMode(Mode Mode){ mode = Mode; }

	/// @brief tをセットする
	/// @param T 変化量
	void SetT(float T){ t = T; }

private:
	/// @brief 線形補完関数
	/// @param start 開始値
	/// @param end 終了値
	/// @param t 変化量 (0.0f ~ 1.0f)
	/// @return 補完した値
	float LinearInter(float start,float end,float t);

	/// @brief t 加算関数
	void MoveT();

	/// @brief t イージング処理関数
	/// @return EasedT
	float CalcT();

	/// @brief デルタタイム計算用関数
	/// @param deltatime デルタタイム
	void CalcDelta(float deltatime);

	float OutBounce(float t);
};