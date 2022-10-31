#include "Game.h"
#include "FieldManager.h"

void FieldManager::Init(Game& Game)
{
	// �|�C���^��ۑ�
	pGame = &Game;

	// ��U�x�[�X�G�t�F�N�g�ŏ�����
	for (int i = 0; i < fieldArraySize; i++) {
		fields[i] = new BaseField(*pGame);
		fieldsNums[i] = FieldType::NoneField;
		fields[i]->BaseInit();
	}

}

void FieldManager::Finalise()
{
	for (int i = 0; i < fieldArraySize; i++) {
		delete fields[i];
	}
}

int FieldManager::MakeNewField(Vector2D position, Vector2D width, FieldType fieldType)
{
	// �ǉ�����܂Ń��[�v
	while (true) {

		// ����
		nextIndex++;
		if (nextIndex >= fieldArraySize) {
			nextIndex = 0;
		}

		// �I����Ă�����ǉ�
		if (fields[nextIndex]->GetIsEnd()) {
			// �����ɍ��킹��case�ύX�A�ǉ�
			switch (fieldType)
			{
			case FieldType::DestroyCircle:
				delete fields[nextIndex];// �����Ă�̂�delete
				fields[nextIndex] = new BaseField(*pGame, position, width);// �ǉ�
				fieldsNums[nextIndex] = FieldType::DestroyCircle;// �Ǘ��p�z��ɂ��ǉ�
				break;
			case FieldType::NoneField:
			default:
				break;
			}
			// �ǉ��ł����烋�[�v�𔲂���
			break;
		}

	}

	return nextIndex;// �Ǘ��pint��Ԃ�
}

bool FieldManager::IsField(Vector2D position, FieldType fieldType)
{
	for (int i = 0; i < fieldArraySize; i++) {
		if (fieldsNums[i] == fieldType) {
			if (isHit(position, fields[i]->GetPositon(), fields[i]->GetWidth(), fieldType)) {
				return true;
			}
		}
	}
	return false;
}

void FieldManager::SetPosition(int fieldNum, Vector2D position)
{
	fields[fieldNum]->SetPositon(position);
}

void FieldManager::SetWidth(int fieldNum, Vector2D width)
{
	fields[fieldNum]->SetWidth(width);
}

void FieldManager::SetEnd(int fieldNum)
{
	fields[fieldNum]->SetEnd();
}

bool FieldManager::GetIsEnd(int fieldNum)
{
	return fields[fieldNum]->GetIsEnd();
}

bool FieldManager::isHit(Vector2D t, Vector2D pos, Vector2D wid, FieldType fieldType)
{
	switch (fieldType)
	{
	case DestroyCircle:
		return CollisionCircle(t, pos, wid);
		break;
	case NoneField:
	default:
		break;
	}
}

bool FieldManager::CollisionBox(Vector2D t, Vector2D pos, Vector2D wid)
{
	if (pos.x < t.x && t.x < pos.x + wid.x
		&& pos.y < t.y && t.y < pos.y + wid.y) {
		return true;
	}
	return false;
}

bool FieldManager::CollisionCircle(Vector2D t, Vector2D pos, Vector2D wid)
{
	Vector2D p = pos - t;
	// �ȉ~�Ȃ�΍��W��␳
	if (wid.x != wid.y) {
		p.y *= wid.x / wid.y;
	}

	// ����
	if (p.LengthSquare() < wid.y * wid.y) {
		return true;
	}

	return false;
}

// �t�B�[���h�̔z��
BaseField* FieldManager::fields[fieldArraySize];
// �Ǘ��p�z��
FieldType FieldManager::fieldsNums[fieldArraySize];
// ���ɒǉ�����G�t�F�N�g�̓Y��
int FieldManager::nextIndex;
// �Q�[���̃|�C���^
Game* FieldManager::pGame = nullptr;