#include "Game.h"
#include "FieldManager.h"

void FieldManager::Init(Game& Game)
{
	// ポインタを保存
	pGame = &Game;

	// 一旦ベースエフェクトで初期化
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
	// 追加するまでループ
	while (true) {

		// 検索
		nextIndex++;
		if (nextIndex >= fieldArraySize) {
			nextIndex = 0;
		}

		// 終わっていたら追加
		if (fields[nextIndex]->GetIsEnd()) {
			// 処理に合わせてcase変更、追加
			switch (fieldType)
			{
			case FieldType::DestroyCircle:
				delete fields[nextIndex];// 入ってるのをdelete
				fields[nextIndex] = new BaseField(*pGame, position, width);// 追加
				fieldsNums[nextIndex] = FieldType::DestroyCircle;// 管理用配列にも追加
				break;
			case FieldType::NoneField:
			default:
				break;
			}
			// 追加できたらループを抜ける
			break;
		}

	}

	return nextIndex;// 管理用intを返す
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
	// 楕円ならば座標を補正
	if (wid.x != wid.y) {
		p.y *= wid.x / wid.y;
	}

	// 判定
	if (p.LengthSquare() < wid.y * wid.y) {
		return true;
	}

	return false;
}

// フィールドの配列
BaseField* FieldManager::fields[fieldArraySize];
// 管理用配列
FieldType FieldManager::fieldsNums[fieldArraySize];
// 次に追加するエフェクトの添字
int FieldManager::nextIndex;
// ゲームのポインタ
Game* FieldManager::pGame = nullptr;