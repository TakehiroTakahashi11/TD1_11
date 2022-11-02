#pragma once
#include "Vector2D.h"
#include "Quad.h"

namespace My {
    void SetSrand();
    int Random(int min, int max);
    float RandomF(float min, float max, int num);
    int Clamp(int val, int max, int min);
    int VectorDirection4(Vector2D vec);
    //�x�N�g���̕�������i �c���΂߂̂W���� �j
    //�߂�l  0�F��  1�F����  2�F��  3:����  4:��  5:�E��  6:�E  7:�E��@-1�F�G���[
    int VectorDirection8(Vector2D vec);

    Quad RotateCenter(Vector2D& pos, float theta, float width, float height);
}