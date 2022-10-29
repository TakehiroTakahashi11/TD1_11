#include <Novice.h>
#include "Game.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	// ゲームクラスをインスタンス化
	Game game = Game();

	// ゲームループ
	game.Run();

	return 0;
}