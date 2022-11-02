#pragma once
#include "Texture.h"
#include "Sound.h"
#include "Vector2D.h"

class Datas
{
public:
    // =========================
    // �ݒ�

    static constexpr char WINDOW_TITLE[] = "11��TD1";
    static constexpr float SCREEN_WIDTH = 1920.0f;
    static constexpr float SCREEN_HEIGHT = 1080.0f;
    static constexpr float SCREEN_HALF_WIDTH = SCREEN_WIDTH * 0.5f;
    static constexpr float SCREEN_HALF_HEIGHT = SCREEN_HEIGHT * 0.5f;
    static constexpr bool DEBUG_MODE = true;// �f�o�b�O�p���[�h�ɂ��邩
    static constexpr bool FULL_SCREEN_MODE = true;// �t���X�N�ɂ��邩
    static constexpr bool MOUSE_INV_MODE = true;// �}�E�X��\���ɂ��邩

    // =========================
    // PLAYER
    static constexpr float PLAYER_POS_X = Datas::SCREEN_HALF_WIDTH;// �����|�W�V����x
    static constexpr float PLAYER_POS_Y = 0.0f;// �����|�W�V����y
    static constexpr int PLAYER_WIDTH = 64;// ��
    static constexpr int PLAYER_HEIGHT = 64;// ����
    static constexpr int PLAYER_SPD = 10;// �ړ��̑��x
    static constexpr int PLAYER_DASH_SPD = 30;// �_�b�V���̑��x
    static constexpr int PLAYER_ANIM_SPD = 5;// �ړ��A�j���[�V�����p�x(�t���[��)
    static constexpr float PLAYER_DASH_LEN = 10.0f;// �_�b�V�����鎞�Ԃ̒���(�t���[��)
    static constexpr float PLAYER_DASH_START_RIGID = 3.0f;// �_�b�V���O�A�j���[�V�������Ԃ̒���(�t���[��)
    static constexpr float PLAYER_DASH_END_RIGID = 3.0f;// �_�b�V����A�j���[�V�������Ԃ̒���(�t���[��)

    static Texture PLAYER_UP_TEX;// �e�N�X�`��
    static Texture PLAYER_DOWN_TEX;
    static Texture PLAYER_LEFT_TEX;
    static Texture PLAYER_RIGHT_TEX;
    static Texture PLAYER_UP_LEFT_TEX;
    static Texture PLAYER_UP_RIGHT_TEX;
    static Texture PLAYER_DOWN_LEFT_TEX;
    static Texture PLAYER_DOWN_RIGHT_TEX;

    // =========================
    // GAUNTLETS
    static constexpr int GAUNTLET_WIDTH = 40;// ��
    static constexpr int GAUNTLET_HEIGHT = 40;// ����
    static constexpr int GAUNTLET_PLAYER_DISTANCE = 60;// �v���C���[�ƃK���g���b�g�Ƃ̋���(���S���W)
    static Texture GAUNTLET_TEX;// �e�N�X�`��

    // =========================
    // BOSS
    static constexpr float BOSS_POS_X = Datas::SCREEN_HALF_WIDTH;// �����|�W�V����x
    static constexpr float BOSS_POS_Y = 500.0f;// �����|�W�V����y
    static constexpr int BOSS_WIDTH = 250;// ��
    static constexpr int BOSS_HEIGHT = 250;// ����
    static Texture BOSS_TEX;// �e�N�X�`��

    // =========================
    // ��Texture

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