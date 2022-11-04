#pragma once
#include "Texture.h"
#include "Sound.h"
#include "Vector2D.h"

class Datas
{
public:
    // =========================
    // �ėp
    static constexpr char WINDOW_TITLE[] = "11��TD1";
    static constexpr float SCREEN_WIDTH = 1920.0f;
    static constexpr float SCREEN_HEIGHT = 1080.0f;
    static constexpr float SCREEN_HALF_WIDTH = SCREEN_WIDTH * 0.5f;
    static constexpr float SCREEN_HALF_HEIGHT = SCREEN_HEIGHT * 0.5f;

    // ���[�h
    static constexpr bool FULL_SCREEN_MODE = false;// �t���X�N�ɂ��邩
    static constexpr bool MOUSE_INV_MODE = true;// �}�E�X��\���ɂ��邩
    static constexpr bool DEBUG_MODE = true;// �f�o�b�O�p���[�h�ɂ��邩
    static constexpr float DEBUG_SPEED = 1.0f;// �f�o�b�O�p�̉�ʑ��x�ύX

    // =========================
    // PLAYER
    // �p�����[�^
    static constexpr float PLAYER_POS_X = Datas::SCREEN_HALF_WIDTH;// �����|�W�V����x
    static constexpr float PLAYER_POS_Y = 0.0f;// �����|�W�V����y
    static constexpr float PLAYER_MAX_HEALTH = 300.0f;//�ő�̗�
    static constexpr float PLAYER_MAX_INV = 5.0f;// ���G����
    static constexpr int PLAYER_SPD = 10;// �ړ��̑��x
    static constexpr int PLAYER_DASH_SPD = 30;// �_�b�V���̑��x
    static constexpr float PLAYER_KNOCKBACK_POWER = 20.0f;// �m�b�N�o�b�N��
    static constexpr float PLAYER_KNOCKBACK_DIS = 0.7f;// �m�b�N�o�b�N���x�����鑬�x
    static constexpr float PLAYER_KNOCKBACK_RIGID = 15.0f;// �m�b�N�o�b�N��̍d������(�t���[��)
    static constexpr float PLAYER_CAMARA_OFFSET = 100.0f;// �J����
    static constexpr float PLAYER_CAMARA_SPD = 5.0f;// �J�������߂鑬�x

    // �A�j���[�V����
    static constexpr int PLAYER_WIDTH = 64;// ��
    static constexpr int PLAYER_HEIGHT = 64;// ����
    static constexpr int PLAYER_ANIM_SPD = 5;// �ړ��A�j���[�V�����p�x(�t���[��)
    static constexpr float PLAYER_ANIM_MAX = 8.0f;// �ړ��A�j���[�V�����ő�R�}
    static constexpr float PLAYER_DASH_LEN = 15.0f;// �_�b�V�����鎞�Ԃ̒���(�t���[��)
    static constexpr float PLAYER_DASH_START_RIGID = 3.0f;// �_�b�V���O�A�j���[�V�������Ԃ̒���(�t���[��)
    static constexpr float PLAYER_DASH_END_RIGID = 3.0f;// �_�b�V����A�j���[�V�������Ԃ̒���(�t���[��)

    static Texture PLAYER_TEX;// �e�N�X�`��

    // =========================
    // GAUNTLETS
    static constexpr int GAUNTLET_WIDTH = 128;// ��
    static constexpr int GAUNTLET_HEIGHT = 128;// ����
    static constexpr float GAUNTLET_MAX_HEALTH = 300.0f;// �ő�ϋv��
    static constexpr float GAUNTLET_KNOCKBACK_POWER = 10.0f;// �m�b�N�o�b�N����

    // �A�j���[�V����
    static constexpr int GAUNTLET_PLAYER_MOVE_DISTANCE = 60;// �v���C���[�ƃK���g���b�g�Ƃ̋���(�ʏ�)
    static constexpr int GAUNTLET_PLAYER_GUARD_DISTANCE = 46;// �v���C���[�ƃK���g���b�g�Ƃ̋���(�K�[�h��)
    static constexpr int GAUNTLET_PLAYER_DASH_DISTANCE = 90;// �v���C���[�ƃK���g���b�g�Ƃ̋���(�_�b�V����)
    static constexpr float GAUNTLET_GUARD_DIR_SPD = 15.0f;// �K�[�h���A�K�[�h�������̉�]�̑���
    static constexpr float GAUNTLET_DASH_DIS_SPD = 1.0f;// �_�b�V�����A�_�b�V���������̓����̑���(�c)
    static constexpr float GAUNTLET_DASH_DIR_SPD = 15.0f;// �_�b�V�����A�_�b�V���������̓����̑���(��)
    static Texture GAUNTLET_TEX;// �e�N�X�`��

    // =========================
    // BOSS
    static constexpr float BOSS1_POS_X = Datas::SCREEN_HALF_WIDTH;// �����|�W�V����x
    static constexpr float BOSS1_POS_Y = 500.0f;// �����|�W�V����y
    static constexpr int BOSS1_WIDTH = 512;// ��
    static constexpr int BOSS1_HEIGHT = 512;// ����
    static constexpr int BOSS1_COL_WIDTH = 180;// ���`�Ԃ̓����蔻��c
    static constexpr int BOSS1_COL_HEIGHT = 128;// ���`�Ԃ̓����蔻�艡
    static constexpr float BOSS1_MOVE_SPD = 0.007f;
    static constexpr float BOSS1_MOVE_AMP = 30.0f;
    static constexpr float BOSS1_HIT_DAMAGE = 30.0f;// ���`�Ԃ̓����������̃_���[�W
    static Texture BOSS1_TEX;// �e�N�X�`��

    // �A�j���[�V����
    static constexpr int BOSS1_ANIM_SPD = 3;// �A�j���[�V�������x
    static constexpr int BOSS1_ANIM_MAX_X = 23;// �A�j���[�V�������ő�R�}
    static constexpr int BOSS1_ANIM_MAX_Y = 2;// �A�j���[�V�������ő�R�}

    // =========================
    // EFFECTS
    static constexpr int EFFECTS_HIT_MAX_NUM = 30;// �q�b�g�G�t�F�N�g�ő吔
    static constexpr int EFFECTS_HIT_SIZE = 64;// �q�b�g�G�t�F�N�g�傫��
    static Texture EFFECTS_HIT_TEX;// �e�N�X�`��

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