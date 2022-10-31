#pragma once
#include "Obj.h"
#include "Vector2D.h"

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

private:
	/// @brief ���W
	Vector2D position;

	/// @brief �ړ���
	Vector2D velocity;
};