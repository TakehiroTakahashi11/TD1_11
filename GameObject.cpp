#include "GameObject.h"
#include "Game.h"
#include "Camera.h"

GameObject::GameObject(Game& pGame) :pGame(pGame){}
GameObject::~GameObject(){}

Game& GameObject::getGame() const { return pGame; }
Player& GameObject::getPlayer() const{ return pGame.getPlayer(); }
Gauntlets& GameObject::getGauntlets() const{ return pGame.getGauntlets(); }
Boss& GameObject::getBoss() const{ return pGame.getBoss(); }
Camera& GameObject::getCameraMain() const { return pGame.getCameraMain(); }
Camera& GameObject::getCameraSub() const { return pGame.getCameraSub(); }
Camera& GameObject::getCameraUI() const { return pGame.getCameraUI(); }
bool GameObject::IsCntMode() const { return pGame.IsCntMode(); }