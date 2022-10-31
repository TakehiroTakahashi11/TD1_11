#pragma once

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

	/// @brief ���C�����[�v
	void Run();

	/// @brief �V�[���`�F���W�֐�
	/// @param scene �V�[��
	void ChangeScene(Scene scene) { mNowScene = scene; }

	/// @brief �t�F�[�Y�`�F���W�֐�
	/// @param process (kInit, kUpdate, kFinalise)
	void ChangePhase(Process process){ mNowPhase = process; }

private:
	/// @brief �t���[���J�n
	void BeginFrame();

	/// @brief �X�V����
	void Update();

	/// @brief �`��
	void Draw();

	/// @brief �t���[���I��
	void EndFrame();

private:
	// �v���C���[
	class Player* player;

	// �J����
	class Camera* mCameraMain;
	Camera* mCameraSub;
	Camera* mCameraUI;

public:
	Player& getPlayer() { return *player; }
	Camera& getCameraMain() { return *mCameraMain; }
	Camera& getCameraSub() { return *mCameraSub; }
	Camera& getCameraUI() { return *mCameraUI; }
private:

	// ���݂̂ǂ̃V�[����
	Scene mNowScene;
	// �V�[���̃|�C���^�z��
	BaseScene* pScene[kSceneNum];

	// ���݂ǂ̃t�F�[�Y��
	Process mNowPhase;
};