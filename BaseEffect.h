#pragma once
#include "Vector2D.h"

enum EffectType {
	// �G�t�F�N�g����
	NoneEffect,
	kHit,
	kAtttack,
	kThunder,
	kPreThunder,
	kPlayerDash,
	kPlayerBoost,
};

class BaseEffect
{
public:
	/// @brief �f�t�H���g�R���X�g���N�^
	BaseEffect();
	/// @brief �R���X�g���N�^
	BaseEffect(class Game& game);
	/// @brief ��������R���X�g���N�^
	BaseEffect(Game& game, Vector2D pos);
	/// @brief �f�X�g���N�^
	~BaseEffect();

	// �p���p

	/// @brief ����������
	virtual void Init();
	/// @brief �X�V����
	virtual void Update();
	/// @brief �`�揈��
	virtual void Draw();

	// �}�l�[�W���[����p

	/// @brief ����������
	void BaseInit();
	/// @brief ����������
	void BaseInit(Vector2D pos);
	/// @brief �X�V����
	void BaseUpdate();
	/// @brief �`�揈��
	void BaseDraw();

	// �Q�b�^�[�Z�b�^�[

	/// @brief �G�t�F�N�g���I��������֐�
	void SetEnd() { isEnd = true; }
	/// @brief �G�t�F�N�g���I����Ă��邩
	bool GetIsEnd() { return isEnd; }

	/// @brief ���C���J�������擾����֐�
	class Camera& getCameraMain();
	/// @brief �T�u�J�������擾����֐�
	Camera& getCameraSub();
	/// @brief UI�J�������擾����֐�
	Camera& getCameraUI();

protected:
	// ���W
	Vector2D position;
	// �o�߃t���[��
	float elapsedFrame;

	// �I��������
	bool isEnd;

	// �Q�[���̃|�C���^
	Game& pGame;
};