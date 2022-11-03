#pragma once
#include "Texture.h"
#include "Sound.h"
#include "Vector2D.h"

class Datas
{
public:
    // =========================
    // 設定

    static constexpr char WINDOW_TITLE[] = "11月TD1";
    static constexpr float SCREEN_WIDTH = 1920.0f;
    static constexpr float SCREEN_HEIGHT = 1080.0f;
    static constexpr float SCREEN_HALF_WIDTH = SCREEN_WIDTH * 0.5f;
    static constexpr float SCREEN_HALF_HEIGHT = SCREEN_HEIGHT * 0.5f;
    static constexpr bool DEBUG_MODE = true;// デバッグ用モードにするか
    static constexpr bool FULL_SCREEN_MODE = true;// フルスクにするか
    static constexpr bool MOUSE_INV_MODE = true;// マウス非表示にするか

    // =========================
    // PLAYER
    static constexpr float PLAYER_POS_X = Datas::SCREEN_HALF_WIDTH;// 初期ポジションx
    static constexpr float PLAYER_POS_Y = 0.0f;// 初期ポジションy
    static constexpr int PLAYER_WIDTH = 32;// 幅
    static constexpr int PLAYER_HEIGHT = 32;// 高さ
    static constexpr int PLAYER_SPD = 10;// 移動の速度
    static constexpr int PLAYER_DASH_SPD = 30;// ダッシュの速度
    static constexpr int PLAYER_ANIM_SPD = 5;// 移動アニメーション頻度(フレーム)
    static constexpr float PLAYER_ANIM_MAX = 8.0f;// 移動アニメーション最大コマ
    static constexpr float PLAYER_DASH_LEN = 10.0f;// ダッシュする時間の長さ(フレーム)
    static constexpr float PLAYER_DASH_START_RIGID = 3.0f;// ダッシュ前アニメーション時間の長さ(フレーム)
    static constexpr float PLAYER_DASH_END_RIGID = 3.0f;// ダッシュ後アニメーション時間の長さ(フレーム)

    static Texture PLAYER_TEX;// テクスチャ

    // =========================
    // GAUNTLETS
    static constexpr int GAUNTLET_WIDTH = 64;// 幅
    static constexpr int GAUNTLET_HEIGHT = 64;// 高さ
    static constexpr int GAUNTLET_PLAYER_MOVE_DISTANCE = 30;// プレイヤーとガントレットとの距離(通常)
    static constexpr int GAUNTLET_PLAYER_GUARD_DISTANCE = 23;// プレイヤーとガントレットとの距離(ガード中)
    static constexpr int GAUNTLET_PLAYER_DASH_DISTANCE = 45;// プレイヤーとガントレットとの距離(ダッシュ中)
    static Texture GAUNTLET_TEX;// テクスチャ

    // =========================
    // BOSS
    static constexpr float BOSS_POS_X = Datas::SCREEN_HALF_WIDTH;// 初期ポジションx
    static constexpr float BOSS_POS_Y = 500.0f;// 初期ポジションy
    static constexpr int BOSS_WIDTH = 250;// 幅
    static constexpr int BOSS_HEIGHT = 250;// 高さ
    static Texture BOSS_TEX;// テクスチャ

    // =========================
    // 仮Texture

    static Texture MouseTex;
    static Texture BackGroundTex;

    // =========================
public:// Load
    static void LoadTexture();
    static int GetPer() { return Per; }
    static bool GetIsEnd() { return IsEnd; }
private:
    Datas() {}
    ~Datas() {}
public:
    static const int Max_Per;
private:
    static int Per;
    static bool IsEnd;
};