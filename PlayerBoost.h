#pragma once
#include "BaseEffect.h"

#define PlayerBoostMaxNum 3

class PlayerBoost : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	PlayerBoost(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~PlayerBoost();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	bool endCheck();

	/******** �G�t�F�N�g **********/
	//position ... x, y���W
	//size ... ��`�̃T�C�Y
	//velocity ... �������x
	//acceleration ... �����x
	//theta ... ��]�p
	//elapseFrame ... ���ݎ���
	//time ... ���S�_�Ɍ���������
	//easeTime ... �C�[�W���O�p����
	//currentAlpha ... �����x
	//init ... ������
	//isEnd ... �G�t�F�N�g���I�����Ă��邩
	struct PlayerBoostStruct {
		Vector2D position;
		Vector2D startPosition;
		Vector2D size;
		Vector2D velocity;
		float acceleration;
		float theta;
		float elapseFrame;
		float time;
		float easeTime;
		unsigned int currentAlpha;

		bool init;
		bool isEnd;
	};

	PlayerBoostStruct boostEffect[PlayerBoostMaxNum];
};