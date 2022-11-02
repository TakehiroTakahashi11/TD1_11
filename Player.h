#pragma once
#include "Obj.h"
#include "ControllerInput.h"

class Player : public Obj
{
public:
	/// @brief �R���X�g���N�^
	/// @param pGame �Q�[���̃|�C���^
	Player(class Game& pGame);

	/// @brief ����������
	void Init() override;

	/// @brief �X�V����
	void Update() override;

	/// @brief �`�揈��
	void Draw() override;

	enum DashLevel {
		Dash1,
		Dash2,
		Dash3
	};

private:
	/// @brief �ړ�����
	void Move();

	/// @brief �U������
	void Dash();

	/// @brief �h�䏈��
	void Guard();

private:
	// ����
	Controller::StickMagnitude l_stick_mag;

	// �ړ���
	Vector2D velocity;
	// ����
	Vector2D direciton;
	// ���x
	float speed;

	// �_�b�V���̒���
	float dash_length;
	// �_�b�V�����x
	float dash_speed;
	// �_�b�V������
	bool isDash;

	// �K�[�h����
	bool isGuard;
};