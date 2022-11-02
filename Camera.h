#pragma once
#include "GameObject.h"
#include "Vector2D.h"
#include "Quad.h"
#include "Texture.h"

class Camera : public GameObject
{
public:
	/// @brief コンストラクタ
	/// @param pGame ゲームのポインタ
	Camera(class Game* pGame);
	
	/// @brief デストラクタ
	~Camera();

	/// @brief カメラ位置をセットする
	/// @param position カメラ位置(ワールド座標)
	void setPosition(const Vector2D& position);

	/// @brief カメラ位置を移動させる
	/// @param velocity 移動ベクトル
	void MovePosition(const Vector2D& velocity);

	/// @brief スケールをセットする
	/// @param scale スケール
	void setScale(float scale);

	/// @brief スケールを移動させる
	/// @param scale スケール
	void MoveScale(float scale);

	/// @brief 回転角をセットする
	/// @param theta Radian
	void setTheta(float theta);

	/// @brief 回転角を移動させる
	/// @param theta Radian
	void MoveTheta(float theta);

	const Vector2D& getPosition() const { return mPosition; }
	float getScale() const { return mScale; }
	float getTheta() const { return mTheta; }

	void DrawQuad(const Quad& quad, const Texture& texture, int x_anim = 0, int y_anim = 0, unsigned int color = 0xFFFFFFFF) const;

	// カメラシェイク
	void CameraShake(Vector2D range, Vector2D velocity, float finish_time);

	// 更新処理
	void Update();

private:
	// カメラ中心座標()
	void setCenterPos();

public:

private:
	Vector2D mPosition;// カメラ座標(ワールド座標)
	Vector2D mCenterPos;// カメラ座標(ワールド座標)

	Vector2D mShakePos;// シェイク座標(ワールド座標)

	float mScale;// 拡縮
	float mTheta;// 回転角
	unsigned int mColor;// 全体の色

	Vector2D mRange;// range
	Vector2D mVelocity;// 変化量
	bool IsShake;// カメラシェイクするかフラグ

	float mFinish;// 終了時間
};