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
		kAttack1,

		None
	};

	// �A�N�V�����Z�b�g
	void SetNextAction(BossAction bossaction);

	// �A�N�V����
	void Action();

	// �ҋ@�A�N�V����
	void Move();

	// �U��1
	void Attack1();

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

	// Move
	Vector2D beforePos;
	float moveTheta;

	// Attack1
	int bullet_handle;

	// �����Ă��邩
	bool isFloating;

	// �A�j���[�V����
	float anim;
};