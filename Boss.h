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
		kThunder1,

		None
	};

	// �A�N�V�����Z�b�g
	void SetNextAction(BossAction bossaction);

	// �A�N�V����
	void Action();

	// �ҋ@�A�N�V����
	void Move();
	void MoveMig();

	// �U��1
	void Attack1();
	void Attack1Mig();

	// �U��1
	void Thunder1();
	void Thunder1Mig();

	// �A�j���[�V����
	void Animation();

private:
	// �m�b�N�o�b�N
	bool isKnockBack;
	Vector2D knockBackVel;

	// �o�ߎ���
	float elapsedTime;
	// �Ō�Ƀm�b�N�o�b�N��������
	float lastKnockBackTime;
	// �Ō�ɃA�N�V������������
	float lastActionTime;

	// �A�N�V�������
	BossAction nowAction;
	// �\��A�N�V����
	BossAction nextAction;
	// �ڍs�ł��邩
	bool canMigration;

	// Move
	Vector2D beforePos;
	float moveTheta;

	// Attack1
	float attack1Elapsed;
	float attack1bullet1Time;
	float attack1bullet2Time;
	float attack1bullet3Time;
	float attack1bullet4Time;
	float attack1bullet5Time;
	float attack1bullet6Time;
	float attack1bullet7Time;
	float attack1bullet8Time;
	float attack1bullet9Time;
	float attack1bullet10Time;

	// Thunder1
	float thunder1Elapsed;
	Vector2D thunder1pos;
	Vector2D thunder2pos;
	Vector2D thunder3pos;
	int prethunder1_num;
	int prethunder2_num;
	int prethunder3_num;
	bool thunder1_created;
	bool thunder2_created;
	bool thunder3_created;

	// �����Ă��邩
	bool isFloating;

	// �A�j���[�V����
	float anim;
};