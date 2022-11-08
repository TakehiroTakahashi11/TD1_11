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
    static constexpr bool FULL_SCREEN_MODE = true;// �t���X�N�ɂ��邩
    static constexpr bool MOUSE_INV_MODE = true;// �}�E�X��\���ɂ��邩
    static constexpr bool DEBUG_MODE = true;// �f�o�b�O�p���[�h�ɂ��邩
    static constexpr float DEBUG_SPEED = 1.0f;// �f�o�b�O�p�̉�ʑ��x�ύX
    static constexpr float VIBRATION = 0.3f;// �R���g���[���[�o�C�u���[�V�����{��

    // =========================
    // PLAYER
    // �p�����[�^
    static constexpr float PLAYER_POS_X = 0.0f;// �����|�W�V����x
    static constexpr float PLAYER_POS_Y = -500.0f;// �����|�W�V����y

    static constexpr float PLAYER_MAX_HEALTH = 300.0f;//�ő�̗�

    static constexpr float PLAYER_MAX_STAMINA = 300.0f;//�ő�K�[�h�l
    static constexpr float PLAYER_GUARD_STAMINA = 0.1f;// �K�[�h����X�^�~�i
    static constexpr float PLAYER_GUARD_COOLTIME = 70.0f;// �ēx�K�[�h�ł���K�[�h�l
    static constexpr float PLAYER_STAMINA_REGEN = 0.25f;// �K�[�h�l���R��

    static constexpr float PLAYER_MAX_INV = 50.0f;// ���G����

    static constexpr int PLAYER_SPD = 8;// �ړ��̑��x
    static constexpr int PLAYER_ANIM_SPD = 5;// �ړ��A�j���[�V�����p�x(�t���[��)
    static constexpr float PLAYER_ANIM_MAX = 8.0f;// �ړ��A�j���[�V�����ő�R�}

    static constexpr int PLAYER_DASH_SPD = 35;// �_�b�V���̑��x
    static constexpr float PLAYER_DASH_LEN = 7.0f;// �_�b�V�����鎞�Ԃ̒���(�t���[��)
    static constexpr float PLAYER_DASH_START_RIGID = 0.0f;// �_�b�V���O�A�j���[�V�������Ԃ̒���(�t���[��)
    static constexpr float PLAYER_DASH_END_RIGID = 2.0f;// �_�b�V����A�j���[�V�������Ԃ̒���(�t���[��)

    static constexpr float PLAYER_KNOCKBACK_POWER = 20.0f;// �{�X�ɓ����������̃m�b�N�o�b�N��
    static constexpr float PLAYER_KNOCKBACK_DIS = 0.7f;// �m�b�N�o�b�N���x�����鑬�x
    static constexpr float PLAYER_KNOCKBACK_RIGID = 15.0f;// �m�b�N�o�b�N��̍d������(�t���[��)

    static constexpr float PLAYER_CAMARA_OFFSET = 100.0f;// �J����
    static constexpr float PLAYER_CAMARA_SPD = 5.0f;// �J�������߂鑬�x

    // �A�j���[�V����
    static constexpr int PLAYER_WIDTH = 64;// ��
    static constexpr int PLAYER_HEIGHT = 64;// ����
    static constexpr int PLAYER_INV_ANIM_SPD = 10;// ���G�A�j���[�V�������x

    static Texture PLAYER_TEX;// �e�N�X�`��
    static Texture PLAYER_DASH_TEX;// �e�N�X�`��

    // =========================
    // GAUNTLETS
    static constexpr int GAUNTLET_WIDTH = 128;// ��
    static constexpr int GAUNTLET_HEIGHT = 128;// ����

    static constexpr float GAUNTLET_MAX_HEALTH = 300.0f;// �ő�ϋv��

    static constexpr float GAUNTLET_KNOCKBACK_POWER = 10.0f;// �{�X�����������̃m�b�N�o�b�N����
    static constexpr float GAUNTLET_KNOCKBACK_DIS = 0.3f;// �m�b�N�o�b�N���x�����鑬�x

    // �A�j���[�V����
    static constexpr int GAUNTLET_PLAYER_MOVE_DISTANCE = 60;// �v���C���[�ƃK���g���b�g�Ƃ̋���(�ʏ�)
    static constexpr int GAUNTLET_PLAYER_GUARD_DISTANCE = 46;// �v���C���[�ƃK���g���b�g�Ƃ̋���(�K�[�h��)
    static constexpr int GAUNTLET_PLAYER_DASH_DISTANCE = 90;// �v���C���[�ƃK���g���b�g�Ƃ̋���(�_�b�V����)
    static constexpr float GAUNTLET_GUARD_DIR_SPD = 15.0f;// �K�[�h���A�K�[�h�������̉�]�̑���
    static constexpr float GAUNTLET_DASH_DIS_SPD = 1.0f;// �_�b�V�����A�_�b�V���������̓����̑���(�c)
    static constexpr float GAUNTLET_DASH_DIR_SPD = 15.0f;// �_�b�V�����A�_�b�V���������̓����̑���(��)
    static Texture GAUNTLET_TEX;// �e�N�X�`��

    // =========================
    // BOSS1
    static constexpr float BOSS1_POS_X = 0.0f;// �����|�W�V����x
    static constexpr float BOSS1_POS_Y = 0.0f;// �����|�W�V����y

    static constexpr int BOSS1_WIDTH = 512;// ��
    static constexpr int BOSS1_HEIGHT = 512;// ����

    static constexpr int BOSS1_COL_WIDTH = 180;// ���`�Ԃ̓����蔻�艡
    static constexpr int BOSS1_COL_HEIGHT = 128;// ���`�Ԃ̓����蔻��c

    static constexpr float BOSS1_HIT_DAMAGE = 30.0f;// ���`�Ԃ̓����������̃_���[�W

    // �^�C�����C���֌W
    static constexpr float BOSS_TIMELINE_DISTANCE_1 = 450.0f;// �{�X���s����ς��鋗��1
    static constexpr float BOSS_TIMELINE_DISTANCE_2 = 700.0f;// �{�X���s����ς��鋗��2

    static constexpr float BOSS_ATTACK1_OFFSET = 160.0f;// �A�^�b�N1�̌�ɍU�����s���Ȃ�����
    static constexpr float BOSS_THUNDER1_OFFSET = 350.0f;

    // �A�j���[�V����
    static constexpr float BOSS1_MOVE_SPD = 0.02f;// �ӂ�ӂ푬�x
    static constexpr float BOSS1_MOVE_AMP = 40.0f;// �ӂ�ӂ�U��
    static constexpr int BOSS1_ANIM_SPD = 3;// �A�j���[�V�������x
    static constexpr int BOSS1_ANIM_MAX_X = 23;// �A�j���[�V�������ő�R�}
    static constexpr int BOSS1_ANIM_MAX_Y = 2;// �A�j���[�V�������ő�R�}
    static Texture BOSS1_TEX;// �e�N�X�`��

    // =========================
    // EFFECTS
    static constexpr int EFFECTS_HIT_MAX_NUM = 30;// �q�b�g�G�t�F�N�g�ő吔
    static constexpr int EFFECTS_HIT_SIZE = 64;// �q�b�g�G�t�F�N�g�傫��
    static constexpr float EFFECTS_HIT_SPD = 2.0f;// �q�b�g�G�t�F�N�g���x
    static Texture EFFECTS_HIT_TEX;// �e�N�X�`��

    static constexpr int EFFECTS_ATK_MAX_NUM = 20;// �q�b�g�G�t�F�N�g�ő吔
    static constexpr int EFFECTS_ATK_SIZE = 32;// �q�b�g�G�t�F�N�g�傫��
    static constexpr float EFFECTS_ATK_SPD = 1.0f;// �q�b�g�G�t�F�N�g���x
    static Texture EFFECTS_ATK_TEX;// �e�N�X�`��

    static constexpr float EFFECTS_THUNDER_SIZE = 400.0f;// �e�N�X�`��
    static constexpr int EFFECTS_THUNDER_SIZE_Y = 76;// �����蔻��傫��
    static constexpr int EFFECTS_THUNDER_SIZE_X = 113;// �����蔻��傫��
    static Texture EFFECTS_THUNDER_TEX;// �e�N�X�`��

    static constexpr float EFFECTS_PRETHUNDER_SIZE = 400.0f;// �e�N�X�`��
    static Texture EFFECTS_PRETHUNDER_TEX;// �e�N�X�`��

    static constexpr float BOSS_ATTACK1_DIS = 100.0f;// �����ʒu�̒��S����̋���
    static constexpr float BOSS_ATTACK1_SHOOT_DIS = 5.0f;// ���ˊԊu
    static constexpr float BOSS_ATTACK1_WAVE_DIS = 50.0f;// �E�F�[�u�Ԋu
    static constexpr float BOSS_ATTACK1_SPEED = 10.0f;// ���x
    static constexpr float BOSS_ATTACK1_DAMAGE = 5.0f;// �_���[�W

    // �e�N�X�`��
    static constexpr int BOSS_ATTACK1_SIZE = 32;// �傫��
    static Texture BOSS_ATTACK1_TEX;// �e�N�X�`��

    // ���U��
    static constexpr float BOSS_THUNDER1_PREPRETIME = 90.0f;// ���@�w�\���\������
    static constexpr float BOSS_THUNDER1_PRETIME = 15.0f;// �\���\������
    static constexpr float BOSS_THUNDER1_TIME_DIS = 50.0f;// ���ˊԊu
    static constexpr float BOSS_THUNDER1_SHAKE_AMP_X = 7.0f;// �J�����V�F�C�N�U��
    static constexpr float BOSS_THUNDER1_SHAKE_AMP_Y = 5.0f;// �J�����V�F�C�N�U��
    static constexpr float BOSS_THUNDER1_SHAKE_DIS_X = -0.3f;// �J�����V�F�C�N����
    static constexpr float BOSS_THUNDER1_SHAKE_DIS_Y = -0.3f;// �J�����V�F�C�N����
    static constexpr float BOSS_THUNDER1_DAMAGE = 30.0f;// �_���[�W

    static Texture MAGIC_CIRCLE_TEX;// �e�N�X�`��

    // �u�[�X�g
    static Texture PLAYER_BOOST_TEX;// �e�N�X�`��

    // =========================
    // Map
    static constexpr int MAP_SIZE = 64;// �傫��
    static Texture MAP_TEX;// �e�N�X�`��

    // =========================
    // STAGE
    static constexpr float STAGE0_WIDTH = 512.0f;// �`���[�g���A���X�e�[�W�̉���(����
    static constexpr float STAGE0_HEIGHT = 512.0f;
    static constexpr float STAGE0_MAP_X = STAGE0_WIDTH * 2 / MAP_SIZE;// �`���[�g���A���X�e�[�W�̉����̃}�b�v�`�b�v��
    static constexpr float STAGE0_MAP_Y = STAGE0_HEIGHT * 2 / MAP_SIZE;
    static constexpr float STAGE1_WIDTH = 1024.0f;// �X�e�[�W1�̉���(����
    static constexpr float STAGE1_HEIGHT = 1024.0f;
    static constexpr float STAGE1_MAP_X = STAGE1_WIDTH * 2 / MAP_SIZE;// �X�e�[�W1�̉����̃}�b�v�`�b�v��
    static constexpr float STAGE1_MAP_Y = STAGE1_HEIGHT * 2 / MAP_SIZE;

    // =========================
    // ��Texture
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