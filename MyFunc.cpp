#include "Myfunc.h"
#include <time.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <Novice.h>

namespace My {
    void SetSrand(){
        srand(static_cast<unsigned int>(time(NULL)));
    }

    int Random(int min, int max){
        return min + static_cast<int>(rand() * static_cast<float>(max - min + 1.0f) / static_cast<float>(1.0f + RAND_MAX));
    }

    float RandomF(float min, float max,int num) {
        int Num = static_cast<int>(pow(10, num));
        return static_cast<float>(Random(static_cast<int>(max * Num), static_cast<int>(min * Num)) * (1.0f / static_cast<float>(Num)));
    }

    int Clamp(int val, int max, int min){
        if(val < min){
            return min;
        }
        if(max < val){
            return max;
        }
        return val;
    }

    //�x�N�g���̕�������i �㉺���E�̂S���� �j
    int VectorDirection4(Vector2D vec)  //�߂�l�@0�F��    1�F��    2�F��    3�F�E    -1:�G���[
    {
        if (vec.y == 0 && vec.x == 0) { return -1; }

        //���E��̔���̏ꍇ�A���E���㉺���D��ɂȂ�܂�

        if (vec.y >= abs(vec.x)) { return 0; } //��
        if (vec.y <= -abs(vec.x)) { return 2; } //��

        if (vec.x < -abs(vec.y)) { return 1; } //��
        if (vec.x > abs(vec.y)) { return 3; } //�E

        return -1;    //���Ȃ��͂�
    }

    int VectorDirection8(Vector2D vec)  
    {
        int i;

        if (vec.y == 0 && vec.x == 0) { return -1; }

        double work_vx[4];
        double work_vy[4];
        double rad;
        for (i = 0; i < 4; i++) {
            rad = ((22.5 + i * 45) * M_PI) / 180;

            work_vx[i] = cos(rad);
            work_vy[i] = sin(rad);
        }

        double dot_result[8];
        for (i = 0; i < 4; i++) {
            dot_result[i] = work_vx[i] * vec.x + work_vy[i] * vec.y;
            dot_result[i + 4] = -dot_result[i];
        }

        if (dot_result[0] > 0 && dot_result[3] >= 0) { return 0; }//��
        if (dot_result[1] > 0 && dot_result[4] >= 0) { return 1; }//����
        if (dot_result[2] > 0 && dot_result[5] >= 0) { return 2; }//��
        if (dot_result[3] > 0 && dot_result[6] >= 0) { return 3; }//����
        if (dot_result[4] > 0 && dot_result[7] >= 0) { return 4; }//��
        if (dot_result[5] > 0 && dot_result[0] >= 0) { return 5; }//�E��
        if (dot_result[6] > 0 && dot_result[1] >= 0) { return 6; }//�E
        if (dot_result[7] > 0 && dot_result[2] >= 0) { return 7; }//�E��

        return -1;    //���Ȃ��͂�
    }

    Quad RotateCenter(Vector2D& pos, float theta, float width, float height)
    {
        Quad temp = { {pos.x - width * 0.5f,pos.y - height * 0.5f}, width, height };// �ꎞ
        temp = temp.Translation(-pos).Rotation(static_cast<float>(theta - 90 * M_PI / 180)).Translation({ pos.x - width * 0.5f ,pos.y - height * 0.5f });// ��]
        return temp;
    }

    bool CollisonCircletoPoint(Vector2D pos, float rad_x, float rad_y, Vector2D pos2)
    {
        Vector2D after = { pos2.x - pos.x,pos2.y - pos.y };
        after.y *= rad_x / rad_y;
        if (after.Length() <= rad_x) {
            return true;
        }
        
        return false;
    }
}
