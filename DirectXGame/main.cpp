#include <Windows.h>
#include "KamataEngine.h"
#include "GameScene.h"
#include "Skydome.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	using namespace KamataEngine;

	// エンジンの初期化
	KamataEngine::Initialize(L"LE2D_02_アオヤギ_ガクト_AL3");

	// ゲームシーンのインスタンス作成
	GameScene* gameScene = new GameScene();

	// DirectXのインスタンスを取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// ゲームシーンの初期化
	gameScene->Initialize();

	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		// ゲームシーンの更新
		gameScene->Update();

		// 描画開始
		dxCommon->PreDraw();

		// ゲームシーンの描画
		gameScene->Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの解放
	delete gameScene;

	// nullptrの代入
	gameScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}
