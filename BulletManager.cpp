#include "Game.h"
#include "BulletManager.h"
#include "BossAttack1.h"
#include "BossAttack2.h"
#include "Mine.h"
#include "Enemy1.h"

void BulletManager::Init(Game& Game)
{
	// �|�C���^��ۑ�
	pGame = &Game;

	// ��U�x�[�X�G�t�F�N�g�ŏ�����
	for (int i = 0; i < bulletArraySize; i++) {
		 bullets[i] = new BaseBullet(*pGame);
		 bullets[i]->BaseInit();
	}

}

void BulletManager::Update()
{
	for (int i = 0; i < bulletArraySize; i++) {
		bullets[i]->BaseUpdate();
	}
}

void BulletManager::Draw()
{
	for (int i = 0; i < bulletArraySize; i++) {
		bullets[i]->BaseDraw();
	}
}

void BulletManager::Finalise()
{
	for (int i = 0; i < bulletArraySize; i++) {
		delete  bullets[i];
	}
}

int BulletManager::MakeNewBullet(Vector2D position, BulletType bulletType)
{
	// �ǉ�����܂Ń��[�v
	while (true) {
		// ����
		nextIndex++;
		if (nextIndex >= bulletArraySize) {
			nextIndex = 0;
		}

		// �I����Ă�����ǉ�
		if (bullets[nextIndex]->GetIsEnd()) {
			// �����ɍ��킹��case�ύX�A�ǉ�
			switch (bulletType)
			{
			case BulletType::kBossAttack1:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position);// �ǉ�
				break;
			case BulletType::kBossAttack1_1:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position,1);// �ǉ�
				break;
			case BulletType::kBossAttack1_2:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 2);// �ǉ�
				break;
			case BulletType::kBossAttack1_3:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 3);// �ǉ�
				break;
			case BulletType::kBossAttack1_4:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 4);// �ǉ�
				break;
			case BulletType::kBossAttack1_5:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 5);// �ǉ�
				break;
			case BulletType::kBossAttack1_6:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 6);// �ǉ�
				break;
			case BulletType::kBossAttack1_7:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 7);// �ǉ�
				break;
			case BulletType::kBossAttack1_8:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 8);// �ǉ�
				break;
			case BulletType::kBossAttack1_9:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 9);// �ǉ�
				break;
			case BulletType::kBossAttack1_10:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack1(*pGame, position, 10);// �ǉ�
				break;
			case BulletType::kBossAttack2:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new BossAttack2(*pGame, position);// �ǉ�
				break;
			case BulletType::kBossAttackMine1:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new Mine(*pGame, position);// �ǉ�
				break;
			case BulletType::kBossAttackEnemy1:
				delete bullets[nextIndex];// �����Ă�̂�delete
				bullets[nextIndex] = new Enemy1(*pGame, position);// �ǉ�
				break;
			case BulletType::NoneBullet:
			default:
				break;
			}
			// �ǉ��ł����烋�[�v�𔲂���
			break;
		}

	}

	return nextIndex;// �Ǘ��pint��Ԃ�
}

void BulletManager::SetEnd(int bulletNum)
{
	bullets[bulletNum]->SetEnd();
}

bool BulletManager::GetIsEnd(int bulletNum)
{
	return bullets[bulletNum]->GetIsEnd();
}

// �G�t�F�N�g�̔z��
BaseBullet* BulletManager::bullets[bulletArraySize];
// ���ɒǉ�����G�t�F�N�g�̓Y��
int BulletManager::nextIndex;
// �Q�[���̃|�C���^
Game* BulletManager::pGame = nullptr;