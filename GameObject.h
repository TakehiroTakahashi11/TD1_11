#pragma once

class GameObject
{
public:
	GameObject(class Game& pGame);
	virtual ~GameObject();

	class Game& getGame() const;
	class Camera& getCameraMain() const;
	class Camera& getCameraSub() const;
	class Camera& getCameraUI() const;
private:
	/// @brief ゲームのポインタ
	Game& pGame;
};