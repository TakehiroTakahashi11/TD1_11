#include <Novice.h>
#include "Screen.h"
#include "Quad.h"
#include "Vector2D.h"
#include "Datas.h"
#include "Texture.h"

Vector2D Screen::mScreenCenter = { Datas::SCREEN_HALF_WIDTH, Datas::SCREEN_HALF_HEIGHT };

/// @brief クアッド描画関数
/// @param quad クアッド カメラ座標
/// @param texture テクスチャ
/// @param x_anim xアニメーション
/// @param y_anim yアニメーション
void Screen::DrawQuad(const Quad& quad, const Texture& texture, int x_anim, int y_anim, unsigned int color){
	Novice::DrawQuad(
		static_cast<int>(quad.lefttop.x + mScreenCenter.x), static_cast<int>(quad.lefttop.y * -1 + mScreenCenter.y),
		static_cast<int>(quad.righttop.x + mScreenCenter.x), static_cast<int>(quad.righttop.y * -1 + mScreenCenter.y),
		static_cast<int>(quad.leftbottom.x + mScreenCenter.x), static_cast<int>(quad.leftbottom.y * -1 + mScreenCenter.y),
		static_cast<int>(quad.rightbottom.x + mScreenCenter.x), static_cast<int>(quad.rightbottom.y * -1 + mScreenCenter.y),
		texture.width * x_anim, texture.width * y_anim,
		texture.width, texture.height,
		texture.GetHandle(), color);
}