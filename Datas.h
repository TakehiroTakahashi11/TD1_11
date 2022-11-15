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
    static constexpr float VIBRATION = 0.3f;// �R���g���[���[�o�C�u���[�V�����{��

    // =========================
    // PLAYER
    // �p�����[�^
    static constexpr float PLAYER_POS_X = 0.0f;// �����|�W�V����x
    static constexpr float PLAYER_POS_Y = -500.0f;// �����|�W�V����y

    static constexpr float PLAYER_MAX_HEALTH = 300.0f;//�ő�̗�

    static constexpr float PLAYER_MAX_STAMINA = 200.0f;//�ő�K�[�h�l
    static constexpr float PLAYER_GUARD_STAMINA = 0.0f;// �K�[�h����X�^�~�i
    static constexpr float PLAYER_GUARD_COOLTIME = 70.0f;// �ēx�K�[�h�ł���K�[�h�l
    static constexpr float PLAYER_STAMINA_REGEN = 0.3f;// �K�[�h�l���R��

    static constexpr float PLAYER_MAX_INV = 80.0f;// ���G����

    static constexpr int PLAYER_SPD = 8;// �ړ��̑��x
    static constexpr int PLAYER_ANIM_SPD = 5;// �ړ��A�j���[�V�����p�x(�t���[��)
    static constexpr float PLAYER_ANIM_MAX = 8.0f;// �ړ��A�j���[�V�����ő�R�}

    static constexpr int PLAYER_DASH_SPD = 35;// �_�b�V���̑��x
    static constexpr float PLAYER_BEFORE_DASH = 4.0f;// �_�b�V�������t���[��
    static constexpr float PLAYER_DASH_LEN = 12.0f;// �_�b�V�����鎞�Ԃ̒���(�t���[��)
    static constexpr float PLAYER_DASH_COOLTIME = 4.0f;// �_�b�V���N�[���_�E��

    static constexpr float PLAYER_KNOCKBACK_POWER = 20.0f;// �{�X�ɓ����������̃m�b�N�o�b�N��
    static constexpr float PLAYER_KNOCKBACK_DIS = 0.7f;// �m�b�N�o�b�N���x�����鑬�x
    static constexpr float PLAYER_KNOCKBACK_RIGID = 5.0f;// �m�b�N�o�b�N��̍d������(�t���[��)

    static constexpr float PLAYER_ATTACK_DAMAGE = 10.0f;// �v���C���[�U����

    static constexpr float PLAYER_ATTACK_CHARGE = 15.0f;// �U���������̃`���[�W��
    static constexpr float PLAYER_JUSTDODGE_CHARGE = 70.0f;// �W���X�g����������̃`���[�W��
    static constexpr float PLAYER_CHARGE_MAX = 500.0f;// �ő�`���[�W��
    static constexpr float PLAYER_CHARGE_DIS = PLAYER_CHARGE_MAX / 5.0f;// �Q�[�W�Ԋu

    static constexpr float PLAYER_CAMARA_OFFSET = 100.0f;// �J����
    static constexpr float PLAYER_CAMARA_SPD = 5.0f;// �J�������߂鑬�x

    // �A�j���[�V����
    static constexpr int PLAYER_WIDTH = 128;// ��
    static constexpr int PLAYER_HEIGHT = 128;// ����
    static constexpr int PLAYER_INV_ANIM_SPD = 10;// ���G�A�j���[�V�������x

    static Texture PLAYER_DASH_TEX;// �e�N�X�`��

    static Texture PLAYER_UP_TEX;
    static Texture PLAYER_DOWN_TEX;
    static Texture PLAYER_LEFT_TEX;
    static Texture PLAYER_RIGHT_TEX;
    static Texture PLAYER_RIGHTUP_TEX;
    static Texture PLAYER_LEFTUP_TEX;
    static Texture PLAYER_RIGHTDOWN_TEX;
    static Texture PLAYER_LEFTDOWN_TEX;

    static Texture PLAYER_DASH_UP_TEX;
    static Texture PLAYER_DASH_DOWN_TEX;
    static Texture PLAYER_DASH_LEFT_TEX;
    static Texture PLAYER_DASH_RIGHT_TEX;
    static Texture PLAYER_DASH_RIGHTUP_TEX;
    static Texture PLAYER_DASH_LEFTUP_TEX;
    static Texture PLAYER_DASH_RIGHTDOWN_TEX;
    static Texture PLAYER_DASH_LEFTDOWN_TEX;

    static Texture PLAYER_BOOST_UP_TEX;
    static Texture PLAYER_BOOST_DOWN_TEX;
    static Texture PLAYER_BOOST_LEFT_TEX;
    static Texture PLAYER_BOOST_RIGHT_TEX;
    static Texture PLAYER_BOOST_RIGHTUP_TEX;
    static Texture PLAYER_BOOST_LEFTUP_TEX;
    static Texture PLAYER_BOOST_RIGHTDOWN_TEX;
    static Texture PLAYER_BOOST_LEFTDOWN_TEX;

    static Texture PLAYER_SHADOW_TEX;

    // =========================
    // GAUNTLETS
    static constexpr int GAUNTLET_WIDTH = 128;// ��
    static constexpr int GAUNTLET_HEIGHT = 128;// ����

    static constexpr float GAUNTLET_MAX_HEALTH = 300.0f;// �ő�ϋv��

    static constexpr float GAUNTLET_KNOCKBACK_POWER = 10.0f;// �{�X�����������̃m�b�N�o�b�N����
    static constexpr float GAUNTLET_KNOCKBACK_DIS = 0.3f;// �m�b�N�o�b�N���x�����鑬�x

    // �A�j���[�V����
    static constexpr int GAUNTLET_PLAYER_MOVE_DISTANCE = 35;// �v���C���[�ƃK���g���b�g�Ƃ̋���(�ʏ�)
    static constexpr int GAUNTLET_PLAYER_GUARD_DISTANCE = 46;// �v���C���[�ƃK���g���b�g�Ƃ̋���(�K�[�h��)
    static constexpr int GAUNTLET_PLAYER_DASH_DISTANCE = 90;// �v���C���[�ƃK���g���b�g�Ƃ̋���(�_�b�V����)
    static constexpr float GAUNTLET_GUARD_DIR_SPD = 15.0f;// �K�[�h���A�K�[�h�������̉�]�̑���
    static constexpr float GAUNTLET_DASH_DIS_SPD = 1.0f;// �_�b�V�����A�_�b�V���������̓����̑���(�c)
    static constexpr float GAUNTLET_DASH_DIR_SPD = 15.0f;// �_�b�V�����A�_�b�V���������̓����̑���(��)
    static Texture GAUNTLET_UP_TEX;
    static Texture GAUNTLET_DOWN_TEX;
    static Texture GAUNTLET_LEFT_TEX;
    static Texture GAUNTLET_RIGHT_TEX;
    static Texture GAUNTLET_RIGHTUP_TEX;
    static Texture GAUNTLET_LEFTUP_TEX;
    static Texture GAUNTLET_RIGHTDOWN_TEX;
    static Texture GAUNTLET_LEFTDOWN_TEX;

    static Texture GAUNTLET_DASH_UP_TEX;
    static Texture GAUNTLET_DASH_DOWN_TEX;
    static Texture GAUNTLET_DASH_LEFT_TEX;
    static Texture GAUNTLET_DASH_RIGHT_TEX;
    static Texture GAUNTLET_DASH_RIGHTUP_TEX;
    static Texture GAUNTLET_DASH_LEFTUP_TEX;
    static Texture GAUNTLET_DASH_RIGHTDOWN_TEX;
    static Texture GAUNTLET_DASH_LEFTDOWN_TEX;

    // =========================
    // BOSS1
    static constexpr float BOSS1_POS_X = 0.0f;// �����|�W�V����x
    static constexpr float BOSS1_POS_Y = 0.0f;// �����|�W�V����y

    static constexpr int BOSS1_WIDTH = 512;// ��
    static constexpr int BOSS1_HEIGHT = 512;// ����

    static constexpr int BOSS1_COL_WIDTH = 180;// ���`�Ԃ̓����蔻�艡
    static constexpr int BOSS1_COL_HEIGHT = 128;// ���`�Ԃ̓����蔻��c

    static constexpr float BOSS1_HEALTH_MAX = 300.0f;// ���`�Ԃ̓����������̃_���[�W
    static constexpr float BOSS1_HIT_DAMAGE = 30.0f;// ���`�Ԃ̓����������̃_���[�W

    static constexpr float BOSS1_ATTACK_HITSTOP = 5.0f;// �{�X�����������̃q�b�g�X�g�b�v�t���[��
    static constexpr float BOSS1_CHARGE_ATTACK_HITSTOP = 10.0f;// �{�X�����������̃q�b�g�X�g�b�v�t���[��

    // �^�C�����C���֌W
    static constexpr float BOSS_TIMELINE_DISTANCE_1 = 500.0f;// �{�X���s����ς��鋗��1
    static constexpr float BOSS_TIMELINE_DISTANCE_2 = 800.0f;// �{�X���s����ς��鋗��2

    static constexpr float BOSS_ATTACK1_OFFSET = 200.0f;// �A�^�b�N1�̌�ɍU�����s���Ȃ�����
    static constexpr float BOSS_ATTACK1_2_OFFSET = 90.0f;
    static constexpr float BOSS_ATTACK2_OFFSET = 350.0f;// 
    static constexpr float BOSS_RUSH1_OFFSET = 300.0f;// 
    static constexpr float BOSS_RUSH1_2_OFFSET = 700.0f;// 
    static constexpr float BOSS_RUSH2_OFFSET = 300.0f;
    static constexpr float BOSS_THUNDER1_OFFSET = 200.0f;
    static constexpr float BOSS_MINE1_OFFSET = 200.0f;

    static constexpr float BOSS1_DASH_COOLTIME = 1000.0f;

    // �A�j���[�V����
    static constexpr float BOSS1_MOVE_SPD = 0.02f;// �ӂ�ӂ푬�x
    static constexpr float BOSS1_MOVE_AMP = 40.0f;// �ӂ�ӂ�U��
    static constexpr int BOSS1_ANIM_SPD = 3;// �A�j���[�V�������x
    static constexpr int BOSS1_ANIM_MAX_X = 23;// �A�j���[�V�������ő�R�}
    static constexpr int BOSS1_ANIM_MAX_Y = 2;// �A�j���[�V�������ő�R�}
    static Texture BOSS1_TEX;// �e�N�X�`��
    static Texture BOSS1_VINNET_TEX;// �e�N�X�`��

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
    static Texture EFFECTS_THUNDER_VINNET_TEX;// �e�N�X�`��

    static constexpr float EFFECTS_PRETHUNDER_SIZE = 400.0f;// �e�N�X�`��
    static Texture EFFECTS_PRETHUNDER_TEX;// �e�N�X�`��

    static constexpr float EFFECTS_PRERUSH_WIDTH = 300.0f;
    static constexpr float EFFECTS_PRERUSH_HEIGHT = 2048.0f;

    static constexpr float BOSS_ATTACK1_DIS = 100.0f;// �����ʒu�̒��S����̋���
    static constexpr float BOSS_ATTACK1_SHOOT_DIS = 5.0f;// ���ˊԊu
    static constexpr float BOSS_ATTACK1_WAVE_DIS = 50.0f;// �E�F�[�u�Ԋu
    static constexpr float BOSS_ATTACK1_SPEED = 10.0f;// ���x
    static constexpr float BOSS_ATTACK1_DAMAGE = 10.0f;// �_���[�W

    static constexpr float BOSS_ATTACK2_SHOOT_DIS = 10.0f;// ���ˊԊu
    static constexpr float BOSS_ATTACK2_SPEED = 30.0f;// ���x

    // �e�N�X�`��
    static constexpr int BOSS_ATTACK1_SIZE = 32;// �傫��
    static Texture BOSS_ATTACK1_TEX;// �e�N�X�`��

    // �e����
    static Texture PRE_BULLET_TEX;// �e�N�X�`��
    static Texture BULLET_DEATH_TEX;// �e�N�X�`��

    // ���@�w
    static Texture BULLET_CIRCLE_TEX1;// �e�N�X�`��
    static Texture BULLET_CIRCLE_TEX2;// �e�N�X�`��
    static Texture BULLET_CIRCLE_TEX3;// �e�N�X�`��
    static Texture BULLET_CIRCLE_VINNET_TEX;// �e�N�X�`��

    // ���U��
    static constexpr float BOSS_THUNDER1_PREPRETIME = 90.0f;// ���@�w�\���\������
    static constexpr float BOSS_THUNDER1_PRETIME = 15.0f;// �\���\������
    static constexpr float BOSS_THUNDER1_TIME_DIS = 50.0f;// ���ˊԊu
    static constexpr float BOSS_THUNDER1_SHAKE_AMP_X = 10.0f;// �J�����V�F�C�N�U��
    static constexpr float BOSS_THUNDER1_SHAKE_AMP_Y = 13.0f;// �J�����V�F�C�N�U��
    static constexpr float BOSS_THUNDER1_SHAKE_DIS_X = -0.15f;// �J�����V�F�C�N����
    static constexpr float BOSS_THUNDER1_SHAKE_DIS_Y = -0.15f;// �J�����V�F�C�N����
    static constexpr float BOSS_THUNDER1_DAMAGE = 30.0f;// �_���[�W

    static Texture MAGIC_CIRCLE_TEX;// �e�N�X�`��
    static Texture MAGIC_CIRCLE_VINNET_TEX;// �e�N�X�`��

    // �u�[�X�g
    static Texture PLAYER_BOOST_TEX;// �e�N�X�`��

    // �ˌ�
    static Texture PRE_RUSH_TEX;// �e�N�X�`��
    static Texture RUSH_INDICATE_TEX;// �e�N�X�`��

    // �n��
    static constexpr float MINE_SIZE = 64.0f;
    static constexpr float MINE_DAMAGE = 20.0f;
    static Texture MINE_TEX;// �e�N�X�`��

    // �G���G
    static constexpr float ENEMY1_SIZE = 64.0f;
    static constexpr float ENEMY1_DAMAGE = 20.0f;
    static Texture ENEMY1_TEX;// �e�N�X�`��

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
    // UI
    static Texture VINETT_TEX;

    // =========================
    // Sound
    static Sound PLAYER_PUNCH_SOUND;

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