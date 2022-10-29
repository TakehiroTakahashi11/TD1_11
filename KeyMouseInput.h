#pragma once
#include <Novice.h>
#include "Vector2D.h"

#ifndef KeyMouse_h_
#define KeyMouse_h_


#define DIMB_LEFT 0
#define DIMB_RIGHT 1
#define DIMB_MIDDLE 2

constexpr const int MOUSEBUTTONNUM = 3;

class Key
{
private:
	static char keys[256];
	static char preKeys[256];

private:
	Key() {}
	~Key() {}

public:
	/// <summary>
	/// �L�[���͏�Ԃ��擾����
	/// </summary>
	static void SetState();

	/// <summary>
	/// ���ݎg���Ă��邩
	/// </summary>
	static bool IsUse();

	/// <summary>
	/// ����L�[��������Ă��Ȃ���
	/// </summary>
	/// <param name="keyCode">���͏�Ԃ��擾����L�[�R�[�h( DIK_0 ��)</param>
	/// <returns>1: ������Ă��Ȃ� 0: ������Ă���</returns>
	static bool IsEmpty(int keyCode);

	/// <summary>
	/// ����L�[�������ꂽ��
	/// </summary>
	/// <param name="keyCode">���͏�Ԃ��擾����L�[�R�[�h( DIK_0 ��)</param>
	/// <returns>1: �����ꂽ 0: ������Ă��Ȃ�</returns>
	static bool IsTrigger(int keyCode);

	/// <summary>
	/// ����L�[��������Ă��鎞
	/// </summary>
	/// <param name="keyCode">���͏�Ԃ��擾����L�[�R�[�h( DIK_0 ��)</param>
	/// <returns>1: ������Ă��� 0: ������Ă��Ȃ�</returns>
	static bool IsPressed(int keyCode);

	/// <summary>
	/// ����L�[�������ꂽ��
	/// </summary>
	/// <param name="keyCode">���͏�Ԃ��擾����L�[�R�[�h( DIK_0 ��)</param>
	/// <returns>1: �����ꂽ 0: ������Ă��Ȃ�</returns>
	static bool IsRelease(int keyCode);
};

class Mouse {
private:
	static bool Buttons[MOUSEBUTTONNUM];
	static bool preButtons[MOUSEBUTTONNUM];

	static Vector2D position;

	static int animation;
	static int anim_count;

private:
	Mouse() {}
	~Mouse() {}

public:

	static void SetState();

	/// <summary>
	/// ����}�E�X�{�^����������Ă��Ȃ���
	/// </summary>
	/// <param name="buttonNumber">�}�E�X�{�^���ԍ�(0:��,1:�E,2:��)</param>
	/// <returns>1: ������Ă��Ȃ� 0: ������Ă���</returns>
	static bool IsEmptyButton(int buttonNumber);

	/// <summary>
	/// ����}�E�X�{�^���������ꂽ��
	/// </summary>
	/// <param name="buttonNumber">�}�E�X�{�^���ԍ�(0:��,1:�E,2:��)</param>
	/// <returns>1: �����ꂽ 0: ������Ă��Ȃ�</returns>
	static bool IsTriggerButton(int buttonNumber);

	/// <summary>
	/// ����}�E�X�{�^����������Ă��鎞
	/// </summary>
	/// <param name="buttonNumber">�}�E�X�{�^���ԍ�(0:��,1:�E,2:��)</param>
	/// <returns>1: ������Ă��� 0: ������Ă��Ȃ�</returns>
	static bool IsPressedButton(int buttonNumber);

	/// <summary>
	/// ����}�E�X�{�^���������ꂽ��
	/// </summary>
	/// <param name="buttonNumber">�}�E�X�{�^���ԍ�(0:��,1:�E,2:��)</param>
	/// <returns>1: �����ꂽ 0: ������Ă��Ȃ�</returns>
	static bool IsReleaseButton(int buttonNumber);

	/// <summary>
	/// �z�C�[���X�N���[���ʂ��擾����
	/// </summary>
	/// <returns>�z�C�[���X�N���[���ʁB�����ɉ񂵂���+�BWindows�̐ݒ�ŋt�ɂ��Ă���t</returns>
	static int GetMouseWheel();

	/// <summary>
	/// �`��֐�
	/// </summary>
	static void Draw(class Texture& tex);
};

#endif