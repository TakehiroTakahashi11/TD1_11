#pragma once
#include "Vector2D.h"
#include "Quad.h"

namespace My {
    void SetSrand();
    int Random(int min, int max);
    float RandomF(float min, float max, int num);
    int Clamp(int val, int max, int min);
    int VectorDirection4(Vector2D vec);
    //ベクトルの方向判定（ 縦横斜めの８方向 ）
    //戻り値  0：上  1：左上  2：左  3:左下  4:下  5:右下  6:右  7:右上　-1：エラー
    int VectorDirection8(Vector2D vec);

    Quad RotateCenter(Vector2D& pos, float theta, float width, float height);
}