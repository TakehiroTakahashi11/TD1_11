#pragma once
#include "Texture.h"
#include "Sound.h"

class Datas
{
public:
    // WINDOW

    static constexpr char WINDOW_TITLE[] = "11ŒŽTD1";

    // =========================
    // SCREEN

    static constexpr float SCREEN_WIDTH = 1920.0f;
    static constexpr float SCREEN_HEIGHT = 1080.0f;
    static constexpr float SCREEN_HALF_WIDTH = SCREEN_WIDTH * 0.5f;
    static constexpr float SCREEN_HALF_HEIGHT = SCREEN_HEIGHT * 0.5f;

    // =========================
    // Texture

    static Texture MouseTex;
    static Texture BackGroundTex;

public:
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