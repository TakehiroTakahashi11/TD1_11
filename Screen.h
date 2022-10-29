#pragma once

class Texture;
class Vector2D;
class Quad;

class Screen
{
private:
	static Vector2D mScreenCenter;

public:
	static void DrawQuad(const Quad& quad, const Texture& texture, int x_anim, int y_anim, unsigned int color);

private:
	Screen() {}
	~Screen() {}
};