#pragma once

class GameObject
{
public:
	GameObject(class Game& pGame);
	virtual ~GameObject();

	Game& getGame() const;
	class Camera& getCameraMain() const;
	Camera& getCameraSub() const;
	Camera& getCameraUI() const;
	bool IsDebug() const;
private:
	// ゲームのポインタ
	Game& pGame;
};