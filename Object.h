#pragma once
#include "Vector2D.h"

class Object
{
public:
	Object() :position({ 0.0f,0.0f }), velocity({ 1.0f,1.0f }),radian(0.0f) {};
	virtual ~Object() = 0;

	virtual void Update() = 0;
	virtual void Draw() = 0;

private:
	Vector2D position;
	Vector2D velocity;
	float radian;
};