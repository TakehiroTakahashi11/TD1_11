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
	void KnockBack();

	// �A�N�V����enum
	enum BossAction
	{
		kMove,

		None
	};

	// �A�N�V����
	void Action();

	// �ҋ@�A�N�V����
	void Move();

	// �A�j���[�V����
	void Animation();

private:
	// �m�b�N�o�b�N
	bool isKnockBack;
	Vector2D knockBackVel;

	// �A�N�V�������
	BossAction nowAction;
	// �\��A�N�V����
	BossAction nextAction;

	// �A�N�V����1�p��]�p
	Vector2D beforePos;
	float moveTheta;

	// �����Ă��邩
	bool isFloating;

	// �A�j���[�V����
	float anim;
};