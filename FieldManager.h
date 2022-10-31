#pragma once
#pragma once
#include "BaseField.h"

class FieldManager
{
public:
	/// @brief ����������
	static void Init(class Game& Game);

	/// @brief �I������
	static void Finalise();

	/// @brief �t�B�[���h�𐶐�
	/// @param position �������W
	/// @param effectType ��������EffectType::
	/// @return �Ǘ��p��int�ϐ�
	static int MakeNewField(Vector2D position, Vector2D width, FieldType fieldType);

	/// @brief �������t�B�[���h��
	/// @param position ���肷����W
	/// @param effectType ���肷��EffectType::
	/// @return �t�B�[���h�Ȃ�true | �łȂ��Ȃ�false
	static bool IsField(Vector2D position, FieldType fieldType);

	/// @brief ���W��ύX����֐�
	static void SetPosition(int fieldNum, Vector2D position);
	/// @brief ���W��ύX����֐�
	static void SetWidth(int fieldNum, Vector2D width);

	/// @brief �G�t�F�N�g���I��������֐�
	static void SetEnd(int fieldNum);

	/// @brief �G�t�F�N�g���I��������
	static bool GetIsEnd(int fieldNum);

private:
	FieldManager();
	static bool isHit(Vector2D t, Vector2D pos, Vector2D wid, FieldType fieldType);
	static bool CollisionBox(Vector2D t, Vector2D pos, Vector2D wid);
	static bool CollisionCircle(Vector2D t, Vector2D pos, Vector2D wid);

public:

private:
	// �z��̃T�C�Y
	const static int fieldArraySize = 64;

	// �A�b�v�L���X�g�p�z��
	static BaseField* fields[fieldArraySize];
	// �Ǘ��p�z��
	static FieldType fieldsNums[fieldArraySize];

	// �Y��
	static int nextIndex;

	// �Q�[���̃|�C���^
	static Game* pGame;
};