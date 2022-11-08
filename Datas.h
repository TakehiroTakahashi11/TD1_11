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
    static constexpr bool FULL_SCREEN_MODE = true;// フルスクにするか
    static constexpr bool MOUSE_INV_MODE = true;// マウス非表示にするか
    static constexpr bool DEBUG_MODE = true;// デバッグ用モードにするか
    static constexpr float DEBUG_SPEED = 1.0f;// デバッグ用の画面速度変更
    static constexpr float VIBRATION = 0.3f;// コントローラーバイブレーション倍率

    // =========================
    // PLAYER
    // パラメータ
    static constexpr float PLAYER_POS_X = 0.0f;// 初期ポジションx
    static constexpr float PLAYER_POS_Y = -500.0f;// 初期ポジションy

    static constexpr float PLAYER_MAX_HEALTH = 300.0f;//最大体力

    static constexpr float PLAYER_MAX_STAMINA = 300.0f;//最大ガード値
    static constexpr float PLAYER_GUARD_STAMINA = 0.1f;// ガード消費スタミナ
    static constexpr float PLAYER_GUARD_COOLTIME = 70.0f;// 再度ガードできるガード値
    static constexpr float PLAYER_STAMINA_REGEN = 0.25f;// ガード値自然回復

    static constexpr float PLAYER_MAX_INV = 50.0f;// 無敵時間

    static constexpr int PLAYER_SPD = 8;// 移動の速度
    static constexpr int PLAYER_ANIM_SPD = 5;// 移動アニメーション頻度(フレーム)
    static constexpr float PLAYER_ANIM_MAX = 8.0f;// 移動アニメーション最大コマ

    static constexpr int PLAYER_DASH_SPD = 35;// ダッシュの速度
    static constexpr float PLAYER_DASH_LEN = 7.0f;// ダッシュする時間の長さ(フレーム)
    static constexpr float PLAYER_DASH_START_RIGID = 0.0f;// ダッシュ前アニメーション時間の長さ(フレーム)
    static constexpr float PLAYER_DASH_END_RIGID = 2.0f;// ダッシュ後アニメーション時間の長さ(フレーム)

    static constexpr float PLAYER_KNOCKBACK_POWER = 20.0f;// ボスに当たった時のノックバック力
    static constexpr float PLAYER_KNOCKBACK_DIS = 0.7f;// ノックバック速度が減る速度
    static constexpr float PLAYER_KNOCKBACK_RIGID = 15.0f;// ノックバック後の硬直時間(フレーム)

    static constexpr float PLAYER_CAMARA_OFFSET = 100.0f;// カメラ
    static constexpr float PLAYER_CAMARA_SPD = 5.0f;// カメラが戻る速度

    // アニメーション
    static constexpr int PLAYER_WIDTH = 64;// 幅
    static constexpr int PLAYER_HEIGHT = 64;// 高さ
    static constexpr int PLAYER_INV_ANIM_SPD = 10;// 無敵アニメーション速度

    static Texture PLAYER_TEX;// テクスチャ
    static Texture PLAYER_DASH_TEX;// テクスチャ

    // =========================
    // GAUNTLETS
    static constexpr int GAUNTLET_WIDTH = 128;// 幅
    static constexpr int GAUNTLET_HEIGHT = 128;// 高さ

    static constexpr float GAUNTLET_MAX_HEALTH = 300.0f;// 最大耐久力

    static constexpr float GAUNTLET_KNOCKBACK_POWER = 10.0f;// ボスを殴った時のノックバック距離
    static constexpr float GAUNTLET_KNOCKBACK_DIS = 0.3f;// ノックバック速度が減る速度

    // アニメーション
    static constexpr int GAUNTLET_PLAYER_MOVE_DISTANCE = 60;// プレイヤーとガントレットとの距離(通常)
    static constexpr int GAUNTLET_PLAYER_GUARD_DISTANCE = 46;// プレイヤーとガントレットとの距離(ガード中)
    static constexpr int GAUNTLET_PLAYER_DASH_DISTANCE = 90;// プレイヤーとガントレットとの距離(ダッシュ中)
    static constexpr float GAUNTLET_GUARD_DIR_SPD = 15.0f;// ガード時、ガード解除時の回転の速さ
    static constexpr float GAUNTLET_DASH_DIS_SPD = 1.0f;// ダッシュ時、ダッシュ解除時の動きの速さ(縦)
    static constexpr float GAUNTLET_DASH_DIR_SPD = 15.0f;// ダッシュ時、ダッシュ解除時の動きの速さ(横)
    static Texture GAUNTLET_TEX;// テクスチャ

    // =========================
    // BOSS1
    static constexpr float BOSS1_POS_X = 0.0f;// 初期ポジションx
    static constexpr float BOSS1_POS_Y = 0.0f;// 初期ポジションy

    static constexpr int BOSS1_WIDTH = 512;// 幅
    static constexpr int BOSS1_HEIGHT = 512;// 高さ

    static constexpr int BOSS1_COL_WIDTH = 180;// 第一形態の当たり判定横
    static constexpr int BOSS1_COL_HEIGHT = 128;// 第一形態の当たり判定縦

    static constexpr float BOSS1_HIT_DAMAGE = 30.0f;// 第一形態の当たった時のダメージ

    // タイムライン関係
    static constexpr float BOSS_TIMELINE_DISTANCE_1 = 450.0f;// ボスが行動を変える距離1
    static constexpr float BOSS_TIMELINE_DISTANCE_2 = 700.0f;// ボスが行動を変える距離2

    static constexpr float BOSS_ATTACK1_OFFSET = 160.0f;// アタック1の後に攻撃が行われない時間
    static constexpr float BOSS_THUNDER1_OFFSET = 350.0f;

    // アニメーション
    static constexpr float BOSS1_MOVE_SPD = 0.02f;// ふわふわ速度
    static constexpr float BOSS1_MOVE_AMP = 40.0f;// ふわふわ振幅
    static constexpr int BOSS1_ANIM_SPD = 3;// アニメーション速度
    static constexpr int BOSS1_ANIM_MAX_X = 23;// アニメーション横最大コマ
    static constexpr int BOSS1_ANIM_MAX_Y = 2;// アニメーション横最大コマ
    static Texture BOSS1_TEX;// テクスチャ

    // =========================
    // EFFECTS
    static constexpr int EFFECTS_HIT_MAX_NUM = 30;// ヒットエフェクト最大数
    static constexpr int EFFECTS_HIT_SIZE = 64;// ヒットエフェクト大きさ
    static constexpr float EFFECTS_HIT_SPD = 2.0f;// ヒットエフェクト速度
    static Texture EFFECTS_HIT_TEX;// テクスチャ

    static constexpr int EFFECTS_ATK_MAX_NUM = 20;// ヒットエフェクト最大数
    static constexpr int EFFECTS_ATK_SIZE = 32;// ヒットエフェクト大きさ
    static constexpr float EFFECTS_ATK_SPD = 1.0f;// ヒットエフェクト速度
    static Texture EFFECTS_ATK_TEX;// テクスチャ

    static constexpr float EFFECTS_THUNDER_SIZE = 400.0f;// テクスチャ
    static constexpr int EFFECTS_THUNDER_SIZE_Y = 76;// 当たり判定大きさ
    static constexpr int EFFECTS_THUNDER_SIZE_X = 113;// 当たり判定大きさ
    static Texture EFFECTS_THUNDER_TEX;// テクスチャ

    static constexpr float EFFECTS_PRETHUNDER_SIZE = 400.0f;// テクスチャ
    static Texture EFFECTS_PRETHUNDER_TEX;// テクスチャ

    static constexpr float BOSS_ATTACK1_DIS = 100.0f;// 初期位置の中心からの距離
    static constexpr float BOSS_ATTACK1_SHOOT_DIS = 5.0f;// 発射間隔
    static constexpr float BOSS_ATTACK1_WAVE_DIS = 50.0f;// ウェーブ間隔
    static constexpr float BOSS_ATTACK1_SPEED = 10.0f;// 速度
    static constexpr float BOSS_ATTACK1_DAMAGE = 5.0f;// ダメージ

    // テクスチャ
    static constexpr int BOSS_ATTACK1_SIZE = 32;// 大きさ
    static Texture BOSS_ATTACK1_TEX;// テクスチャ

    // 雷攻撃
    static constexpr float BOSS_THUNDER1_PREPRETIME = 90.0f;// 魔法陣予兆表示時間
    static constexpr float BOSS_THUNDER1_PRETIME = 15.0f;// 予兆表示時間
    static constexpr float BOSS_THUNDER1_TIME_DIS = 50.0f;// 発射間隔
    static constexpr float BOSS_THUNDER1_SHAKE_AMP_X = 7.0f;// カメラシェイク振幅
    static constexpr float BOSS_THUNDER1_SHAKE_AMP_Y = 5.0f;// カメラシェイク振幅
    static constexpr float BOSS_THUNDER1_SHAKE_DIS_X = -0.3f;// カメラシェイク減衰
    static constexpr float BOSS_THUNDER1_SHAKE_DIS_Y = -0.3f;// カメラシェイク減衰
    static constexpr float BOSS_THUNDER1_DAMAGE = 30.0f;// ダメージ

    static Texture MAGIC_CIRCLE_TEX;// テクスチャ

    // ブースト
    static Texture PLAYER_BOOST_TEX;// テクスチャ

    // =========================
    // Map
    static constexpr int MAP_SIZE = 64;// 大きさ
    static Texture MAP_TEX;// テクスチャ

    // =========================
    // STAGE
    static constexpr float STAGE0_WIDTH = 512.0f;// チュートリアルステージの横幅(半分
    static constexpr float STAGE0_HEIGHT = 512.0f;
    static constexpr float STAGE0_MAP_X = STAGE0_WIDTH * 2 / MAP_SIZE;// チュートリアルステージの横幅のマップチップ数
    static constexpr float STAGE0_MAP_Y = STAGE0_HEIGHT * 2 / MAP_SIZE;
    static constexpr float STAGE1_WIDTH = 1024.0f;// ステージ1の横幅(半分
    static constexpr float STAGE1_HEIGHT = 1024.0f;
    static constexpr float STAGE1_MAP_X = STAGE1_WIDTH * 2 / MAP_SIZE;// ステージ1の横幅のマップチップ数
    static constexpr float STAGE1_MAP_Y = STAGE1_HEIGHT * 2 / MAP_SIZE;

    // =========================
    // 仮Texture
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