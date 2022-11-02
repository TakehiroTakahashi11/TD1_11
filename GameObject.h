#pragma once

class GameObject
{
public:
	GameObject(class Game& pGame);
	virtual ~GameObject();

	Game& getGame() const;
	class Player& getPlayer() const;
	class Gauntlets& getGauntlets() const;
	class Boss& getBoss() const;
	class Camera& getCameraMain() const;
	Camera& getCameraSub() const;
	Camera& getCameraUI() const;
	bool IsCntMode() const;
private:
	// ゲームのポインタ
	Game& pGame;
};