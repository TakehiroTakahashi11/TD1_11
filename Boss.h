#pragma once
#include "Obj.h"
#include "Easing.h"

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

	// �`���[�W�ɑ΂���m�b�N�o�b�N
	void ChargeKnockBack();

	/// @brief �v���C���[�ƃ{�X�̔���
	void PtoBCollision();

	Vector2D GetPosition() { return position; };
	float GetHealth() { return health; };

	bool GetisnTutorial() { return isnTutorial; }
	bool GetmoveTutorial() { return moveTutorial; }
	bool GetguardTutorial() { return guardTutorial; }
	bool GetdashTutorial() { return dashTutorial; }
	bool GetjustTutorial() { return justTutorial; }
	bool GetchargeTutorial() { return chargeTutorial; }

	void SetmoveTutorial() { moveTutorial = true; dashTutorial = false; }
	void SetdashTutorial() { dashTutorial = true; guardTutorial = false; }
	void SetguardTutorial() { guardTutorial = true; justTutorial = false; }
	void SetjustTutorial() { justTutorial = true; chargeTutorial = false; }
	void SetchargeTutorial() { chargeTutorial = true; }

private:
	struct Spear {
		Vector2D position = Vector2D();
		Vector2D direction = Vector2D();
		float theta = 0;
		int frame = 0;
		bool isPre = false;
		bool isInject = false;
		Easing speed = Easing(5, 50, 0.01f, Easing::kOutBack);
	};

	Spear leftSpear;
	Spear rightSpear;

	bool isPreSpear;
	int preSpearFrame;

	enum BossState {
		Wait,
		PreMageAttack,
		MageAttack,
		AfterMageAttack,
		PreFightAttack,
		FightAttack,
		AfterFightAttack
	};

	BossState bossstate = Wait;
	BossState nextstate = Wait;

	float frame = 0.0f;

	float motionspeed = 0.02f;

	float theta = 0;

	Vector2D boss_centerPos = Vector2D(500, 500);
	Vector2D boss_bodyPos = Vector2D(boss_centerPos.x, boss_centerPos.y);
	Vector2D boss_leftupArmPos = Vector2D(boss_centerPos.x - 150, boss_centerPos.y + 50);
	Vector2D boss_rightupArmPos = Vector2D(boss_centerPos.x + 150, boss_centerPos.y + 50);
	Vector2D boss_leftdownArmPos = Vector2D(boss_centerPos.x - 150, boss_centerPos.y - 100);
	Vector2D boss_rightdownArmPos = Vector2D(boss_centerPos.x + 150, boss_centerPos.y - 100);
	Vector2D boss_ringPos = Vector2D(boss_centerPos.x, boss_centerPos.y + 150);
	Vector2D boss_leg1Pos = Vector2D(boss_centerPos.x, boss_centerPos.y - 150);
	Vector2D boss_leg2Pos = Vector2D(boss_centerPos.x, boss_centerPos.y - 225);

	Easing leftupArm_move_x = Easing(boss_leftupArmPos.x, boss_centerPos.x - 75, 0.01, Easing::kInCubic);
	Easing leftupArm_move_y = Easing(boss_leftupArmPos.y, boss_centerPos.y + 50, 0.01, Easing::kInCubic);
	Easing rightupArm_move_x = Easing(boss_rightupArmPos.x, boss_centerPos.x + 75, 0.01, Easing::kInCubic);
	Easing rightupArm_move_y = Easing(boss_rightupArmPos.y, boss_centerPos.y + 50, 0.01, Easing::kInCubic);

	Easing leftdownArm_move_x = Easing(boss_leftdownArmPos.x, boss_centerPos.x - 75, 0.01, Easing::kInCubic);
	Easing leftdownArm_move_y = Easing(boss_leftdownArmPos.y, boss_centerPos.y - 50, 0.01, Easing::kInCubic);
	Easing rightdownArm_move_x = Easing(boss_rightdownArmPos.x, boss_centerPos.x + 75, 0.01, Easing::kInCubic);
	Easing rightdownArm_move_y = Easing(boss_rightdownArmPos.y, boss_centerPos.y - 50, 0.01, Easing::kInCubic);

	Easing upArm_theta = Easing(0, 700 * 3.14 / 180, 0.01, Easing::kInCubic);

	Easing downArm_theta = Easing(0, 700 * 3.14 / 180, 0.01, Easing::kInCubic);

	float bodyBack_theta = 0;
	float bodyBack_accel = 1.0f;

	float uparmFrame = 0.0f;
	float downarmFrame = 0.0f;

	bool isAttack1 = false;
	bool isAttack2 = false;
	bool isAttack1End = false;
	bool isAttack2End = false;
	

	// �m�b�N�o�b�N
	void KnockBack();

	// �^�C�����C��
	void TimeLine();

	// �`���[�g���A���p�^�C�����C��
	void Tutorial();

	// �ڍs���Z
	void Migration();

	// �A�N�V����enum
	enum BossAction
	{
		kMove1,
		kAttack1,
		kAttack1_1,
		kAttack1_2,
		kAttack2,
		kRush1,
		kRush1_2,
		kRush2,
		kThunder1,
		kThunder1_1,
		kMine1,

		None
	};

	// �A�N�V�����Z�b�g
	void SetNextAction(BossAction bossaction);

	// �A�N�V����
	void Action();

	// �ҋ@�A�N�V����
	void Move1();

	// �U��1
	void Attack1();
	// �U��1_1
	void Attack1_1();
	// �U��1_2
	void Attack1_2();

	// �U��1
	void Attack2();

	// �ˌ�1
	void Rush1();

	// �ˌ�1_2
	void Rush1_2();

	// �ˌ�2
	void Rush2();

	// �U��1
	void Thunder1();
	// �U��1_1
	void Thunder1_1();

	// �n��
	void Mine1();

	// �A�j���[�V����
	void Animation();

private:
	// �z�[���|�W�V����
	Vector2D homePos;

	// �ړ��ڕW�|�W�V����
	Vector2D movePos;
	Vector2D movePosEaseResult;
	Easing movePosEaseX;
	Easing movePosEaseY;

	// 
	Vector2D trembPos;

	// �̗�
	float health;

	// �m�b�N�o�b�N
	bool isKnockBack;
	Vector2D knockBackVel;

	// �o�ߎ���
	float elapsedTime;
	// �Ō�ɃA�N�V������������
	float lastActionTime;

	// �ڍs�ł��邩
	bool canMigration;
	// �ڍs�ł���܂ł̎���
	float migrationTime;
	// �O��̍s��
	BossAction beforeAction;

	// �`���[�g���A������Ȃ�
	bool isnTutorial;
	//
	bool moveTutorial;
	//
	bool guardTutorial;
	//
	bool dashTutorial;
	//
	bool justTutorial;
	//
	bool chargeTutorial;

	// Move1
	float dashCoolTime;
	Vector2D dashVelDis;
	Vector2D dashVel;
	float moveTheta;

	// Attack1
	bool attack1Flag;
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

	// Attack1_1
	bool attack1_1Flag;

	// Attack1_2
	bool attack1_2Flag;

	// Attack2
	bool attack2Flag;
	float attack2Elapsed;
	float attack2bullet1Time;
	float attack2bullet2Time;
	float attack2bullet3Time;
	float attack2bullet4Time;
	float attack2bullet5Time;
	float attack2bullet6Time;
	float attack2bullet7Time;
	float attack2bullet8Time;
	float attack2bullet9Time;
	float attack2bullet10Time;

	// Rush1
	bool rush1Flag;
	float rush1Elapsed;
	Easing boss_rush;
	int rush_ef_num;

	// Rush1_2
	bool rush1_2Flag;

	// Rush2
	bool rush2Flag;
	float rush2Elapsed;
	Easing boss_rush2_X;
	Easing boss_rush2_Y;
	int rush2_ef_num;


	// Thunder1
	bool thunder1Flag;
	int thunder1num;

	// Thunder1_1
	bool thunder1_1Flag;

	// Mine1
	bool mine1Flag;
	float mine1Elapsed;
	int mine1;
	int mine2;
	int mine3;

	// �A�j���[�V����
	float anim;

	// �k��
	float tremblingFrame;

	int Move2cnt;
	float Move2frame;
	bool Move2Reset;
};