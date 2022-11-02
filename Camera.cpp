#include "Camera.h"
#include "Datas.h"
#include "Screen.h"
#include "Texture.h"
#include "Quad.h"
#include "MyFunc.h"
#include <Novice.h>
#include "Delta.h"
#include "Game.h"

/// @brief コンストラクタ
/// @param pGame ゲームのポインタ
Camera::Camera(Game& pGame)
: GameObject(pGame),
mPosition({0,0}),
mCenterPos({Datas::SCREEN_HALF_WIDTH,Datas::SCREEN_HALF_HEIGHT}),
mScale(1.0f),
mTheta(0.0f),
mColor(0xFFFFFFFF),
IsShake(false),
mFinish(0.0f)
{
}

/// @brief デストラクタ
Camera::~Camera(){}

/// @brief カメラ位置をセットする
/// @param position カメラ位置(ワールド座標)
void Camera::setPosition(const Vector2D& position) {
	mPosition = position;
	mPosition.x -= Datas::SCREEN_HALF_WIDTH;
	mPosition.y -= Datas::SCREEN_HALF_HEIGHT;
	setCenterPos();
}

/// @brief カメラ位置を移動させる
/// @param velocity 移動ベクトル
void Camera::MovePosition(const Vector2D& velocity) {
	mPosition += velocity;
	mPosition.x -= Datas::SCREEN_HALF_WIDTH;
	mPosition.y -= Datas::SCREEN_HALF_HEIGHT;
	setCenterPos();
}

/// @brief スケールをセットする
/// @param scale スケール
void Camera::setScale(float scale) {
	mScale = scale;
}

/// @brief スケールを移動させる
/// @param scale スケール
void Camera::MoveScale(float scale) {
	mScale += scale;
}

/// @brief 回転角をセットする
/// @param theta Radian
void Camera::setTheta(float theta) {
	mTheta = theta;
}

/// @brief 回転角を移動させる
/// @param theta Radian
void Camera::MoveTheta(float theta) {
	mTheta += theta;
}

/// @brief 内部用:カメラセンター位置を計算して保存
void Camera::setCenterPos() {
	mCenterPos = { mPosition.x + Datas::SCREEN_HALF_WIDTH ,mPosition.y + Datas::SCREEN_HALF_HEIGHT };
}

/// @brief クアッド描画関数
/// @param quad クアッド ワールド座標
/// @param texture テクスチャ
/// @param x_anim xアニメーション
/// @param y_anim yアニメーション
void Camera::DrawQuad(const Quad& quad, const Texture& texture, int x_anim, int y_anim ,unsigned int color) const{
	// カメラ座標に変換
	Quad Temp = quad.Translation(-(mCenterPos + mShakePos)).Scaling(mScale).Rotation(mTheta);
	Screen::DrawQuad(Temp,texture,x_anim,y_anim,color);
}

/// @brief カメラシェイク関数
/// @param range 揺れ幅
/// @param velocity 変化量
/// @param finish_time 終了時間
void Camera::CameraShake(Vector2D range, Vector2D velocity, float finish_time){
	mRange = range;
	mVelocity = velocity;
	mFinish = finish_time;
	IsShake = true;
}

// 更新処理
void Camera::Update(){
	if(IsShake){// シェイクフラグがtrueの時
		float delta = Delta::getDeltaTime();// デルタタイム

		mShakePos.x += My::RandomF(-mRange.x, mRange.x,5);// カメラシェイク
		mShakePos.y += My::RandomF(-mRange.y, mRange.y,5);

		if(mRange.x > 0){// レンジを変化させていく
			mRange.x += mVelocity.x * delta;
		}
		else {
			mRange.x = 0.0f;
		}

		if(mRange.y > 0){
			mRange.y += mVelocity.y * delta;
		}
		else {
			mRange.y = 0.0f;
		}

		mFinish -= delta;// 終了時間を引いていく

		if(mFinish < 0.0f){// もし終了時間に達したら
			mShakePos = { 0.0f,0.0f };
			IsShake = false;// フラグをfalseに
		}
	}
}