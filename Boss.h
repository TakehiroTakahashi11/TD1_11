#pragma once
#include "Obj.h"

class Boss : public Obj
{
public:
	/// @brief �R���X�g���N�^
	/// @param pGame �Q�[���̃|�C���^
	Boss(class Game& pGame);

	/// @brief ����������
	void Init() override;

	/// @brief �X�V����
	void Update() override;

	/// @brief �`�揈��
	void Draw() override;

	/// @brief �Փ˔���
	void Collision();

	/// @brief �v���C���[�ƃ{�X�̔���
	void PtoBCollision();

private:
	// �m�b�N�o�b�N
	void SetKnockBack();
	void KnockBack();

private:
	// �m�b�N�o�b�N
	bool isKnockBack;
	Vector2D knockBackVel;

	// �����Ă��邩
	bool isFloating;
};