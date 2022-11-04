#pragma once
#include "Texture.h"
#include "Sound.h"
#include "Vector2D.h"

class Datas
{
public:
    // =========================
    // 汎用
    static constexpr char WINDOW_TITLE[] = "11月TD1";
    static constexpr float SCREEN_WIDTH = 1920.0f;
    static constexpr float SCREEN_HEIGHT = 1080.0f;
    static constexpr float SCREEN_HALF_WIDTH = SCREEN_WIDTH * 0.5f;
    static constexpr float SCREEN_HALF_HEIGHT = SCREEN_HEIGHT * 0.5f;

    // モード
    static constexpr bool FULL_SCREEN_MODE = false;// フルスクにするか
    static constexpr bool MOUSE_INV_MODE = true;// マウス非表示にするか
    static constexpr bool DEBUG_MODE = true;// デバッグ用モードにするか
    static constexpr float DEBUG_SPEED = 1.0f;// デバッグ用の画面速度変更

    // =========================
    // PLAYER
    // パラメータ
    static constexpr float PLAYER_POS_X = Datas::SCREEN_HALF_WIDTH;// 初期ポジションx
    static constexpr float PLAYER_POS_Y = 0.0f;// 初期ポジションy
    static constexpr float PLAYER_MAX_HEALTH = 300.0f;//最大体力
    static constexpr float PLAYER_MAX_INV = 5.0f;// 無敵時間
    static constexpr int PLAYER_SPD = 10;// 移動の速度
    static constexpr int PLAYER_DASH_SPD = 30;// ダッシュの速度
    static constexpr float PLAYER_KNOCKBACK_POWER = 20.0f;// ノックバック力
    static constexpr float PLAYER_KNOCKBACK_DIS = 0.7f;// ノックバック速度が減る速度
    static constexpr float PLAYER_KNOCKBACK_RIGID = 15.0f;// ノックバック後の硬直時間(フレーム)
    static constexpr float PLAYER_CAMARA_OFFSET = 100.0f;// カメラ
    static constexpr float PLAYER_CAMARA_SPD = 5.0f;// カメラが戻る速度

    // アニメーション
    static constexpr int PLAYER_WIDTH = 64;// 幅
    static constexpr int PLAYER_HEIGHT = 64;// 高さ
    static constexpr int PLAYER_ANIM_SPD = 5;// 移動アニメーション頻度(フレーム)
    static constexpr float PLAYER_ANIM_MAX = 8.0f;// 移動アニメーション最大コマ
    static constexpr float PLAYER_DASH_LEN = 15.0f;// ダッシュする時間の長さ(フレーム)
    static constexpr float PLAYER_DASH_START_RIGID = 3.0f;// ダッシュ前アニメーション時間の長さ(フレーム)
    static constexpr float PLAYER_DASH_END_RIGID = 3.0f;// ダッシュ後アニメーション時間の長さ(フレーム)

    static Texture PLAYER_TEX;// テクスチャ

    // =========================
    // GAUNTLETS
    static constexpr int GAUNTLET_WIDTH = 128;// 幅
    static constexpr int GAUNTLET_HEIGHT = 128;// 高さ
    static constexpr float GAUNTLET_MAX_HEALTH = 300.0f;// 最大耐久力
    static constexpr float GAUNTLET_KNOCKBACK_POWER = 10.0f;// ノックバック距離

    // アニメーション
    static constexpr int GAUNTLET_PLAYER_MOVE_DISTANCE = 60;// プレイヤーとガントレットとの距離(通常)
    static constexpr int GAUNTLET_PLAYER_GUARD_DISTANCE = 46;// プレイヤーとガントレットとの距離(ガード中)
    static constexpr int GAUNTLET_PLAYER_DASH_DISTANCE = 90;// プレイヤーとガントレットとの距離(ダッシュ中)
    static constexpr float GAUNTLET_GUARD_DIR_SPD = 15.0f;// ガード時、ガード解除時の回転の速さ
    static constexpr float GAUNTLET_DASH_DIS_SPD = 1.0f;// ダッシュ時、ダッシュ解除時の動きの速さ(縦)
    static constexpr float GAUNTLET_DASH_DIR_SPD = 15.0f;// ダッシュ時、ダッシュ解除時の動きの速さ(横)
    static Texture GAUNTLET_TEX;// テクスチャ

    // =========================
    // BOSS
    static constexpr float BOSS1_POS_X = Datas::SCREEN_HALF_WIDTH;// 初期ポジションx
    static constexpr float BOSS1_POS_Y = 500.0f;// 初期ポジションy
    static constexpr int BOSS1_WIDTH = 512;// 幅
    static constexpr int BOSS1_HEIGHT = 512;// 高さ
    static constexpr int BOSS1_COL_WIDTH = 180;// 第一形態の当たり判定縦
    static constexpr int BOSS1_COL_HEIGHT = 128;// 第一形態の当たり判定横
    static constexpr float BOSS1_HIT_DAMAGE = 30.0f;// 第一形態の当たった時のダメージ
    static Texture BOSS1_TEX;// テクスチャ

    // アニメーション
    static constexpr int BOSS1_ANIM_SPD = 3;// アニメーション速度
    static constexpr int BOSS1_ANIM_MAX_X = 23;// アニメーション横最大コマ
    static constexpr int BOSS1_ANIM_MAX_Y = 2;// アニメーション横最大コマ

    // =========================
    // EFFECTS
    static constexpr int EFFECTS_HIT_MAX_NUM = 30;// ヒットエフェクト最大数
    static constexpr int EFFECTS_HIT_SIZE = 64;// ヒットエフェクト大きさ
    static Texture EFFECTS_HIT_TEX;// テクスチャ

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