#pragma once
#include "Vector2D.h"

enum FieldType {
	// �t�B�[���h����
	NoneField,
	DestroyCircle,
};

class BaseField
{
public:
	/// @brief �f�t�H���g�R���X�g���N�^
	BaseField();
	/// @brief �R���X�g���N�^
	BaseField(class Game& game);
	/// @brief ��������R���X�g���N�^
	BaseField(Game& game, Vector2D pos, Vector2D wid);
	/// @brief �f�X�g���N�^
	~BaseField();

	// �p���p

	/// @brief ����������
	virtual void Init();

	// �}�l�[�W���[����p

	/// @brief ����������
	void BaseInit();
	/// @brief ����������
	void BaseInit(Vector2D pos, Vector2D wid);

	// �Q�b�^�[�Z�b�^�[

	/// @brief ���W���Z�b�g����֐�
	void SetPositon(Vector2D pos) { position = pos; }
	/// @brief ���W
	Vector2D GetPositon() { return position; }
	/// @brief �����Z�b�g����֐�
	void SetWidth(Vector2D wid) { width = wid; }
	/// @brief ��
	Vector2D GetWidth() { return width; }
	/// @brief �t�B�[���h���폜����֐�
	void SetEnd() { isEnd = true; }
	/// @brief �t�B�[���h���폜����Ă��邩
	bool GetIsEnd() { return isEnd; }

protected:
	// ���W
	Vector2D position;
	// ��
	Vector2D width;

	// �I��������
	bool isEnd;

	// �Q�[���̃|�C���^
	Game& pGame;
};