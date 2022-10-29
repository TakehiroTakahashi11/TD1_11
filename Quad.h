#pragma once
#include "Vector2D.h"
class Quad
{

public:
	Vector2D lefttop;
	Vector2D righttop;
	Vector2D leftbottom;
	Vector2D rightbottom;

public:
	Quad(const Vector2D& lefttop, float width, float height);
	Quad(const Vector2D& lefttop, const Vector2D& righttop, const Vector2D& leftbottom, const Vector2D& rightbottom);
	~Quad();

	// ���s�ړ�
	Quad Translation(const Vector2D& vector) const;
	// ��]
	Quad Rotation(float theta) const;
	// �g��k��
	Quad Scaling(float scale) const;
	// �㉺����ւ�
	Quad VirticalFlip() const;
	// ���E����ւ�
	Quad HorizontalFlip() const;
};

