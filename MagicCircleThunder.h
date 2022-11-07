#pragma 
#include "BaseEffect.h"
#include <vector>
#define MagicCircleRadius 512
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
		float theta;
		float rotatetheta;
		float size;
	};

	std::vector<MagicCircleThunderStruct>effects;
};
