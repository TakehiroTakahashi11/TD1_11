#include "Quad.h"
Quad::Quad(const Vector2D& leftbottom, float width, float height) :
	lefttop(leftbottom + Vector2D{ 0, height }),
	righttop(leftbottom + Vector2D{ width, height }),
	leftbottom(leftbottom),
	rightbottom(leftbottom + Vector2D{ width, 0 })
{}
Quad::Quad(const Vector2D& lefttop, const Vector2D& righttop, const Vector2D& leftbottom, const Vector2D& rightbottom) : 
	lefttop(lefttop),
	righttop(righttop),
	leftbottom(leftbottom),
	rightbottom(rightbottom)
{}
Quad::~Quad(){}

Quad Quad::Translation(const Vector2D& vector) const{
	return { lefttop + vector,righttop + vector , leftbottom + vector, rightbottom + vector };
}
Quad Quad::Rotation(float theta) const {
	if (theta != 0) {
		return { lefttop.Rotated(theta),righttop.Rotated(theta) , leftbottom.Rotated(theta), rightbottom.Rotated(theta) };
	}
	return *this;
}
Quad Quad::Scaling(float scale) const{
	return { lefttop  * scale,righttop  * scale , leftbottom  * scale, rightbottom  * scale };
}
Quad Quad::VirticalFlip() const{
	return { leftbottom,rightbottom,lefttop,righttop };
}
Quad Quad::HorizontalFlip() const{
	return { righttop,lefttop,rightbottom,leftbottom };
}