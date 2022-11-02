#pragma once
#include "GameObject.h"
#include "Vector2D.h"

class Obj : public GameObject
{
public:
	/// @brief �f�t�H���g�R���X�g���N�^
	Obj();

	/// @brief �R���X�g���N�^
	/// @param pGame �Q�[���̃|�C���^
	Obj(class Game* pGame);

	/// @brief �f�X�g���N�^
	virtual ~Obj();

	/// @brief ����������
	virtual void Init() = 0;

	/// @brief �X�V����
	virtual void Update() = 0;

	/// @brief �`�揈��
	virtual void Draw() = 0;
protected:
	// ���W
	Vector2D position;

	// ��
	float width;
	// ����
	float height;
};