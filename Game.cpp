#include "Game.h"
#include <Novice.h>
#include "MyFunc.h"
#include "BaseScene.h"
#include "LoadScene.h"
#include "InGameScene.h"
#include "KeyMouseInput.h"
#include "Datas.h"
#include "Delta.h"

Game::Game() : mCameraMain(*this), mCameraSub(*this), mCameraUI(*this)
{
    // イニシャライズ
    Novice::Initialize(Datas::WINDOW_TITLE, static_cast<int>(Datas::SCREEN_WIDTH), static_cast<int>(Datas::SCREEN_HEIGHT));

    // Srand
    My::SetSrand();

    // シーンポインタ
    pScene[kLoadScene] = new LoadScene(*this);
    pScene[kInGameScene] = new InGameScene(*this);

    // 初期シーンをタイトルに
    mNowScene = kLoadScene;

    // 初期フェーズをイニットに
    mNowPhase = kInit;

    // マウスを非表示
    // Novice::SetMouseCursorVisibility(0);

    // フルスクリーン
    // Novice::SetWindowMode(kFullscreen);
}

Game::~Game()
{
    // シーンを全てdelete
    for (int i = 0; i < kSceneNum; i++) {
        delete pScene[i];
    }
    // ファイナライズ
    Novice::Finalize();
}

Camera& Game::getCameraMain(){
    return mCameraMain;
}

Camera& Game::getCameraSub(){
    return mCameraSub;
}

Camera& Game::getCameraUI(){
    return mCameraUI;
}

/// @brief ゲームループ
void Game::Run() {
    while (Novice::ProcessMessage() == 0) {
        // フレーム開始
        BeginFrame();

        // 更新処理
        Update();

        // 描画処理
        Draw();

        // フレーム終了
        EndFrame();

        // ESC押したら終了
        if (Key::IsPressed(DIK_ESCAPE)) {
            break;
        }
    }
}

void Game::ChangeScene(Scene scene) {
    mNowScene = scene;
}

void Game::ChangePhase(Process process) {
    mNowPhase = process;
}

/// @brief 開始時処理
void Game::BeginFrame() {
    // フレーム開始
    Novice::BeginFrame();

    // デルタタイム取得
    Delta::Update();

    // 入力取得
    Key::SetState();
    Mouse::SetState();
}

/// @brief 更新処理
void Game::Update() {
    switch (mNowPhase)
    {
    case Game::kInit:
        // 現在のシーンに応じて初期化処理
        pScene[mNowScene]->Init();
        break;
    case Game::kUpdate:
        // 現在のシーンに応じて更新処理
        pScene[mNowScene]->Update();

        // カメラ更新処理
        mCameraMain.Update();
        mCameraSub.Update();
        mCameraUI.Update();
        break;
    case Game::kFinalise:
        // 現在のシーンに応じて終了処理
        pScene[mNowScene]->Finalise();
        break;
    case Game::kPhaseNum:
    default:
        break;
    }
}

/// @brief 描画処理
void Game::Draw() {
    // 現在のシーンに応じて描画処理
    pScene[mNowScene]->Draw();
    if (mNowScene != kLoadScene)
    {
        Mouse::Draw(Datas::MouseTex);
    }
}

/// @brief 終了時処理
void Game::EndFrame() {
    // フレーム終了
    Novice::EndFrame();
}