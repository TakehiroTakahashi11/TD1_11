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

    // エフェクト初期化
    EffectManager::Init(*this);

    // 生成
    mCameraMain = new Camera(*this);
    mCameraSub = new Camera(*this);
    mCameraUI = new Camera(*this);
    player = new Player(*this);
}

Game::~Game()
{
    // 全てdelete
    for (int i = 0; i < kSceneNum; i++) {
        delete pScene[i];
    }
    delete mCameraMain;
    delete mCameraSub;
    delete mCameraUI;
    delete player;

    // ファイナライズ
    EffectManager::Finalise();
    Novice::Finalize();
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
        mCameraMain->Update();
        mCameraSub->Update();
        mCameraUI->Update();
        break;
    case Game::kFinalise:
        // 現在のシーンに応じて終了処理
        pScene[mNowScene]->Finalise();
        break;
    case Game::kPhaseNum:
    default:
        break;
    }

    // エフェクト更新
    EffectManager::Update();
}

/// @brief 描画処理
void Game::Draw() {
    // 現在のシーンに応じて描画処理
    pScene[mNowScene]->Draw();

    // マウステクスチャの問題でロード中以外マウス描画
    // 外で読み込んで後で外す
    if (mNowScene != kLoadScene)
    {
        Mouse::Draw(Datas::MouseTex);
    }

    // エフェクト描画
    EffectManager::Draw();
}

/// @brief 終了時処理
void Game::EndFrame() {
    // フレーム終了
    Novice::EndFrame();
}