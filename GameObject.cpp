#include "GameObject.h"
#include "Game.h"
#include "Camera.h"

GameObject::GameObject(Game& pGame) :pGame(pGame){}
GameObject::~GameObject(){}

Game& GameObject::getGame() const { return pGame; }
Camera& GameObject::getCameraMain() const { return pGame.getCameraMain(); }
Camera& GameObject::getCameraSub() const { return pGame.getCameraSub(); }
Camera& GameObject::getCameraUI() const { return pGame.getCameraUI(); }
bool GameObject::IsDebug() const { return pGame.IsDebug(); }
bool GameObject::IsCntMode() const { return pGame.IsCntMode(); }