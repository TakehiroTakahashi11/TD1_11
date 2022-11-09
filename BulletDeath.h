#pragma once
#include "BaseEffect.h"

#define BulletDeathMaxNum 5

class BulletDeath : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	BulletDeath(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~BulletDeath();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	bool endCheck();

	/******** �G�t�F�N�g **********/
	//position ... x, y���W
	//startPosition ... �������W
	//endPosition ... �I�[���W
	//size ... ��`�̃T�C�Y
	//startSize ... ��`�̏����T�C�Y
	//velocity ... �������x
	//acceleration ... �����x
	//theta ... ��]�p
	//elapseFrame ... ���ݎ���
	//time ... ���S�_�Ɍ���������
	//easeTime ... �C�[�W���O�p����
	//currentAlpha ... �����x
	//init ... ������
	//isEnd ... �G�t�F�N�g���I�����Ă��邩
	struct BulletDeathStruct {
		Vector2D position;
		Vector2D startPosition;
		Vector2D endPosition;
		Vector2D size;
		Vector2D startSize;
		Vector2D velocity;
		float acceleration;
		float theta;
		float elapseFrame;
		float time;
		float easeTime;
		// unsigned int currentAlpha;

		bool isEnd;
	};

	BulletDeathStruct bulletDeath[BulletDeathMaxNum];
};