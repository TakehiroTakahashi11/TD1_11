#pragma once
#include <Novice.h>
#include "Vector2D.h"

#ifndef KeyMouse_h_
#define KeyMouse_h_


#define DIMB_LEFT 0
#define DIMB_RIGHT 1
#define DIMB_MIDDLE 2

constexpr const int MOUSEBUTTONNUM = 3;

class Key
{
private:
	static char keys[256];
	static char preKeys[256];

private:
	Key() {}
	~Key() {}

public:
	/// <summary>
	/// キー入力状態を取得する
	/// </summary>
	static void SetState();

	/// <summary>
	/// 現在使われているか
	/// </summary>
	static bool IsUse();

	/// <summary>
	/// 特定キーが押されていない時
	/// </summary>
	/// <param name="keyCode">入力状態を取得するキーコード( DIK_0 等)</param>
	/// <returns>1: 押されていない 0: 押されている</returns>
	static bool IsEmpty(int keyCode);

	/// <summary>
	/// 特定キーが押された時
	/// </summary>
	/// <param name="keyCode">入力状態を取得するキーコード( DIK_0 等)</param>
	/// <returns>1: 押された 0: 押されていない</returns>
	static bool IsTrigger(int keyCode);

	/// <summary>
	/// 特定キーが押されている時
	/// </summary>
	/// <param name="keyCode">入力状態を取得するキーコード( DIK_0 等)</param>
	/// <returns>1: 押されている 0: 押されていない</returns>
	static bool IsPressed(int keyCode);

	/// <summary>
	/// 特定キーが離された時
	/// </summary>
	/// <param name="keyCode">入力状態を取得するキーコード( DIK_0 等)</param>
	/// <returns>1: 離された 0: 離されていない</returns>
	static bool IsRelease(int keyCode);
};

class Mouse {
private:
	static bool Buttons[MOUSEBUTTONNUM];
	static bool preButtons[MOUSEBUTTONNUM];

	static Vector2D position;

	static int animation;
	static int anim_count;

private:
	Mouse() {}
	~Mouse() {}

public:

	static void SetState();

	/// <summary>
	/// 特定マウスボタンが押されていない時
	/// </summary>
	/// <param name="buttonNumber">マウスボタン番号(0:左,1:右,2:中)</param>
	/// <returns>1: 押されていない 0: 押されている</returns>
	static bool IsEmptyButton(int buttonNumber);

	/// <summary>
	/// 特定マウスボタンが押された時
	/// </summary>
	/// <param name="buttonNumber">マウスボタン番号(0:左,1:右,2:中)</param>
	/// <returns>1: 押された 0: 押されていない</returns>
	static bool IsTriggerButton(int buttonNumber);

	/// <summary>
	/// 特定マウスボタンが押されている時
	/// </summary>
	/// <param name="buttonNumber">マウスボタン番号(0:左,1:右,2:中)</param>
	/// <returns>1: 押されている 0: 押されていない</returns>
	static bool IsPressedButton(int buttonNumber);

	/// <summary>
	/// 特定マウスボタンが離された時
	/// </summary>
	/// <param name="buttonNumber">マウスボタン番号(0:左,1:右,2:中)</param>
	/// <returns>1: 離された 0: 離されていない</returns>
	static bool IsReleaseButton(int buttonNumber);

	/// <summary>
	/// ホイールスクロール量を取得する
	/// </summary>
	/// <returns>ホイールスクロール量。奥側に回したら+。Windowsの設定で逆にしてたら逆</returns>
	static int GetMouseWheel();

	/// <summary>
	/// 描画関数
	/// </summary>
	static void Draw(class Texture& tex);
};

#endif