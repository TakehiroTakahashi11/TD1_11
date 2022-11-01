#pragma once
#include "Obj.h"
#include "Vector2D.h"
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

private:
	// ���W
	Vector2D position;

	// ��
	float width;
	// ����
	float height;

};