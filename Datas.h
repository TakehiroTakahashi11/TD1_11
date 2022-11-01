#pragma once
#include "Texture.h"
#include "Sound.h"
#include "Vector2D.h"

class Datas
{
public:
    // =========================
    // WINDOW

    static constexpr char WINDOW_TITLE[] = "11ŒŽTD1";

    // =========================
    // SCREEN

    static constexpr float SCREEN_WIDTH = 1920.0f;
    static constexpr float SCREEN_HEIGHT = 1080.0f;
    static constexpr float SCREEN_HALF_WIDTH = SCREEN_WIDTH * 0.5f;
    static constexpr float SCREEN_HALF_HEIGHT = SCREEN_HEIGHT * 0.5f;

    // =========================
    // PLAYER
    static constexpr float PLAYER_POS_X = Datas::SCREEN_HALF_WIDTH;
    static constexpr float PLAYER_POS_Y = 0.0f;
    static constexpr int PLAYER_WIDTH = 25;
    static constexpr int PLAYER_HEIGHT = 25;
    static constexpr int PLAYER_SPEED = 20;
    static constexpr int PLAYER_DASH_SPEED = 40;
    static Texture PLAYER_TEX;

    // =========================
    // BOSS
    static constexpr float BOSS_POS_X = Datas::SCREEN_HALF_WIDTH;
    static constexpr float BOSS_POS_Y = 500.0f;
    static constexpr int BOSS_WIDTH = 250;
    static constexpr int BOSS_HEIGHT = 250;
    static Texture BOSS_TEX;

    // =========================
    // Texture

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