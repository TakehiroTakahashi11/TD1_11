#pragma once
#include "BaseEffect.h"
#include <vector>
#define MagicCircleRadius 256
#define MagicCircleMAX 3

class MagicCircleThunder : public BaseEffect {
public:
	/// @brief コンストラクタ
	MagicCircleThunder(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~MagicCircleThunder();

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	struct MagicCircleThunderStruct {
		Vector2D position;
		Vector2D velocity;
		Vector2D rotation;
		float theta = 0.0f;
		float rotatetheta = 0.0f;
		float size = 0.0f;
	};


	Vector2D thunder1pos;
	Vector2D thunder2pos;
	Vector2D thunder3pos;
	int prethunder1_num;
	int prethunder2_num;
	int prethunder3_num;
	bool thunder1_created;
	bool thunder2_created;
	bool thunder3_created;

	std::vector<MagicCircleThunderStruct>effects;
};
