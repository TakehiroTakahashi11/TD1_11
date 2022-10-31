#include "ClickEffect.h"
#include "Game.h"
#include "Quad.h"
#include "Datas.h"

ClickEffect::ClickEffect(Game& game, Vector2D pos) : BaseEffect(game,pos)
{
	BaseInit(pos);
}

ClickEffect::~ClickEffect()
{
}

void ClickEffect::Init()
{
	for (int i = 0; i < ClickEffectMaxNum; i++) {
		// position‚ðŒ³‚Éƒ‰ƒ“ƒ_ƒ€‚É‰Šú‰»
		// Effect[i].pos = position;
	}
}

void ClickEffect::Update()
{
	for (int i = 0; i < ClickEffectMaxNum; i++) {
		// Effect[i].pos += Effect[i].velocity;
	}
}

void ClickEffect::Draw()
{
	for (int i = 0; i < ClickEffectMaxNum; i++) {
		// getCameraMain().DrawQuad({ Effect[i].pos,10,10 }, Datas::MouseTex);
	}
}
