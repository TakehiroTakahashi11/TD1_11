#pragma once
#include "BaseBullet.h"
#include "Vector2D.h"

class BulletManager
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
	static int MakeNewBullet(Vector2D position, BulletType bulletType);

	/// @brief �G�t�F�N�g���I��������֐�
	static void SetEnd(int effectNum);

	/// @brief �G�t�F�N�g���I��������
	static bool GetIsEnd(int effectNum);

private:
	BulletManager();

public:

private:
	// �z��̃T�C�Y
	const static int bulletArraySize = 256;

	// �A�b�v�L���X�g�p�z��
	static BaseBullet* bullets[bulletArraySize];

	// �Y��
	static int nextIndex;

	// �Q�[���̃|�C���^
	static Game* pGame;
};