#pragma once
#include "Camera.h"

class BaseScene;

// �Q�[���{��
class Game
{
public:
	/// @brief �V�[��
	enum Scene {
		kLoadScene,
		kInGameScene,

		kSceneNum
	};

	/// @brief �t�F�[�Y
	enum Process {
		kInit,
		kUpdate,
		kFinalise,

		kPhaseNum
	};

	/// @brief �R���X�g���N�^
	Game();

	/// @brief �f�X�g���N�^
	~Game();

	Camera& getCameraMain();
	Camera& getCameraSub();
	Camera& getCameraUI();

	/// @brief ���C�����[�v
	void Run();

	/// @brief �V�[���`�F���W�֐�
	/// @param scene �V�[��
	void ChangeScene(Scene scene);

	/// @brief �t�F�[�Y�`�F���W�֐�(Init, Update, Finalise)
	void ChangePhase(Process process);

private:
	/// @brief �t���[���J�n
	void BeginFrame();

	/// @brief �X�V����
	void Update();

	/// @brief �`��
	void Draw();

	/// @brief �t���[���I��
	void EndFrame();

public:

private:
	// �J����
	Camera mCameraMain;
	Camera mCameraSub;
	Camera mCameraUI;

	// ���݂̂ǂ̃V�[����
	Scene mNowScene;
	// �V�[���̃|�C���^�z��
	BaseScene* pScene[kSceneNum];

	// ���݂ǂ̃t�F�[�Y��
	Process mNowPhase;
};