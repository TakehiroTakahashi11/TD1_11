#pragma once
#include "BaseEffect.h"

class EffectManager
{
public:
	/// @brief ����������
	static void Init(class Game& Game);

	/// @brief �X�V����
	static void Update();

	/// @brief �`�揈��
	static void Draw();

	/// @brief �I������
	static void Finalise();

	/// @brief �V�K�G�t�F�N�g�𐶐�
	/// @param position �������W
	/// @param effectType ��������EffectType::
	/// @return �Ǘ��p��int�ϐ�
	static int MakeNewEffect(Vector2D position, EffectType effectType);

	/// @brief �G�t�F�N�g���I��������֐�
	static void SetEnd(int effectNum);

	/// @brief �G�t�F�N�g���I��������
	static bool GetIsEnd(int effectNum);

private:
	EffectManager();

public:

private:
	// �z��̃T�C�Y
	const static int effectArraySize = 1024;

	// �A�b�v�L���X�g�p�z��
	static BaseEffect* effects[effectArraySize];

	// �Y��
	static int nextIndex;

	// �Q�[���̃|�C���^
	static Game* pGame;
};