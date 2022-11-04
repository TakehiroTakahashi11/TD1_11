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

    //ベクトルの方向判定（ 上下左右の４方向 ）
    int VectorDirection4(Vector2D vec)  //戻り値　0：上    1：左    2：下    3：右    -1:エラー
    {
        if (vec.y == 0 && vec.x == 0) { return -1; }

        //境界上の判定の場合、左右より上下が優先になります

        if (vec.y >= abs(vec.x)) { return 0; } //上
        if (vec.y <= -abs(vec.x)) { return 2; } //下

        if (vec.x < -abs(vec.y)) { return 1; } //左
        if (vec.x > abs(vec.y)) { return 3; } //右

        return -1;    //こないはず
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

        if (dot_result[0] > 0 && dot_result[3] >= 0) { return 0; }//上
        if (dot_result[1] > 0 && dot_result[4] >= 0) { return 1; }//左上
        if (dot_result[2] > 0 && dot_result[5] >= 0) { return 2; }//左
        if (dot_result[3] > 0 && dot_result[6] >= 0) { return 3; }//左下
        if (dot_result[4] > 0 && dot_result[7] >= 0) { return 4; }//下
        if (dot_result[5] > 0 && dot_result[0] >= 0) { return 5; }//右下
        if (dot_result[6] > 0 && dot_result[1] >= 0) { return 6; }//右
        if (dot_result[7] > 0 && dot_result[2] >= 0) { return 7; }//右上

        return -1;    //こないはず
    }

    Quad RotateCenter(Vector2D& pos, float theta, float width, float height)
    {
        Quad temp = { {pos.x - width * 0.5f,pos.y - height * 0.5f}, width, height };// 一時
        temp = temp.Translation(-pos).Rotation(static_cast<float>(theta - 90 * M_PI / 180)).Translation({ pos.x - width * 0.5f ,pos.y - height * 0.5f });// 回転
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
