#include "Game.h"
#include "EfffectManager.h"
#include "ClickEffect.h"

void EffectManager::Init(Game& Game)
{
	// �|�C���^��ۑ�
	pGame = &Game;

	// ��U�x�[�X�G�t�F�N�g�ŏ�����
	for (int i = 0; i < effectArraySize; i++) {
		effects[i] = new BaseEffect(*pGame);
		effects[i]->BaseInit();
	}

}

void EffectManager::Update()
{
	for (int i = 0; i < effectArraySize; i++) {
		effects[i]->BaseUpdate();
	}
}

void EffectManager::Draw()
{
	for (int i = 0; i < effectArraySize; i++) {
		effects[i]->BaseDraw();
	}
}

void EffectManager::Finalise()
{
	for (int i = 0; i < effectArraySize; i++) {
		delete effects[i];
	}
}

int EffectManager::MakeNewEffect(Vector2D position, EffectType effectType)
{
	// �ǉ�����܂Ń��[�v
	while (true) {

		// ����
		nextIndex++;
		if (nextIndex >= effectArraySize) {
			nextIndex = 0;
		}

		// �I����Ă�����ǉ�
		if (effects[nextIndex]->GetIsEnd()) {
			// �����ɍ��킹��case�ύX�A�ǉ�
			switch (effectType)
			{
			case EffectType::Click:
				delete effects[nextIndex];// �����Ă�̂�delete
				effects[nextIndex] = new ClickEffect(*pGame, position);// �ǉ�
				break;
			case EffectType::None:
			default:
				break;
			}
			// �ǉ��ł����烋�[�v�𔲂���
			break;
		}

	}

	return nextIndex;// �Ǘ��pint��Ԃ�
}

void EffectManager::SetEnd(int effectNum)
{
	effects[effectNum]->SetEnd();
}

bool EffectManager::GetIsEnd(int effectNum)
{
	return effects[effectNum]->GetIsEnd();
}

// �G�t�F�N�g�̔z��
BaseEffect* EffectManager::effects[effectArraySize];
// ���ɒǉ�����G�t�F�N�g�̓Y��
int EffectManager::nextIndex;
// �Q�[���̃|�C���^
Game* EffectManager::pGame = nullptr;