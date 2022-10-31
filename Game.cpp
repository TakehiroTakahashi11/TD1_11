#include "Game.h"
#include <Novice.h>
#include "MyFunc.h"
#include "BaseScene.h"
#include "LoadScene.h"
#include "InGameScene.h"
#include "KeyMouseInput.h"
#include "Datas.h"
#include "Delta.h"
#include "EfffectManager.h"
#include "Player.h"
#include "Camera.h"

Game::Game()
{
    // �C�j�V�����C�Y
    Novice::Initialize(Datas::WINDOW_TITLE, static_cast<int>(Datas::SCREEN_WIDTH), static_cast<int>(Datas::SCREEN_HEIGHT));

    // Srand
    My::SetSrand();

    // �V�[���|�C���^
    pScene[kLoadScene] = new LoadScene(*this);
    pScene[kInGameScene] = new InGameScene(*this);

    // �����V�[�����^�C�g����
    mNowScene = kLoadScene;

    // �����t�F�[�Y���C�j�b�g��
    mNowPhase = kInit;

    // �}�E�X���\��
    // Novice::SetMouseCursorVisibility(0);

    // �t���X�N���[��
    // Novice::SetWindowMode(kFullscreen);

    // �G�t�F�N�g������
    EffectManager::Init(*this);

    // ����
    mCameraMain = new Camera(*this);
    mCameraSub = new Camera(*this);
    mCameraUI = new Camera(*this);
    player = new Player(*this);
}

Game::~Game()
{
    // �S��delete
    for (int i = 0; i < kSceneNum; i++) {
        delete pScene[i];
    }
    delete mCameraMain;
    delete mCameraSub;
    delete mCameraUI;
    delete player;

    // �t�@�C�i���C�Y
    EffectManager::Finalise();
    Novice::Finalize();
}

/// @brief �Q�[�����[�v
void Game::Run() {
    while (Novice::ProcessMessage() == 0) {
        // �t���[���J�n
        BeginFrame();

        // �X�V����
        Update();

        // �`�揈��
        Draw();

        // �t���[���I��
        EndFrame();

        // ESC��������I��
        if (Key::IsPressed(DIK_ESCAPE)) {
            break;
        }
    }
}

/// @brief �J�n������
void Game::BeginFrame() {
    // �t���[���J�n
    Novice::BeginFrame();

    // �f���^�^�C���擾
    Delta::Update();

    // ���͎擾
    Key::SetState();
    Mouse::SetState();
}

/// @brief �X�V����
void Game::Update() {
    switch (mNowPhase)
    {
    case Game::kInit:
        // ���݂̃V�[���ɉ����ď���������
        pScene[mNowScene]->Init();
        break;
    case Game::kUpdate:
        // ���݂̃V�[���ɉ����čX�V����
        pScene[mNowScene]->Update();

        // �J�����X�V����
        mCameraMain->Update();
        mCameraSub->Update();
        mCameraUI->Update();
        break;
    case Game::kFinalise:
        // ���݂̃V�[���ɉ����ďI������
        pScene[mNowScene]->Finalise();
        break;
    case Game::kPhaseNum:
    default:
        break;
    }

    // �G�t�F�N�g�X�V
    EffectManager::Update();
}

/// @brief �`�揈��
void Game::Draw() {
    // ���݂̃V�[���ɉ����ĕ`�揈��
    pScene[mNowScene]->Draw();

    // �}�E�X�e�N�X�`���̖��Ń��[�h���ȊO�}�E�X�`��
    // �O�œǂݍ���Ō�ŊO��
    if (mNowScene != kLoadScene)
    {
        Mouse::Draw(Datas::MouseTex);
    }

    // �G�t�F�N�g�`��
    EffectManager::Draw();
}

/// @brief �I��������
void Game::EndFrame() {
    // �t���[���I��
    Novice::EndFrame();
}