#pragma once

/// �� Vector2�Ȃǂ̃N���X�Ŏg���ꍇ�@
///   (Vec + Vec) �� (Vec * float) ���ł���K�v������ �i���Z�q�̃I�[�o�[���[�h�j

// ���`��ԃN���X�i�e���v���[�g�j
template<class TYPE>
class Lerp
{
private:
	float param; // �ω��l
	float deltaParam; // �ω���
	TYPE start, end; // �X�^�[�g�A�G���h
public:
	Lerp() : param(0), deltaParam(0), start(), end() {}
	Lerp(const TYPE& sta, const TYPE& end) : param(0), deltaParam(0), start(sta), end(end) {}
	Lerp(float dpa, const TYPE& sta, const TYPE& end) : param(0), deltaParam(dpa), start(sta), end(end) {};
	Lerp(float par, float dpa, const TYPE& sta, const TYPE& end) : param(par), deltaParam(dpa), start(sta), end(end) {};

	// �A�N�Z�b�T

	float Param() const { return param; }
	float DeltaParam() const { return deltaParam; }
	const TYPE& Start() const { return start; }
	const TYPE& End() const { return end; }

	void SetParam(float par) { param = par; }
	void SetDeltaParam(float dpa) { deltaParam = dpa; }
	void SetStart(const TYPE& sta) { start = sta; }
	void SetEnd(const TYPE& en) { end = en; }

	//

	void Set(float par, float dpa, const TYPE& sta, const TYPE& end) {
		SetParam(par);
		SetDeltaParam(dpa);
		SetStart(sta);
		SetEnd(end);
	}

	// ����
	Lerp& operator++() {
		param += deltaParam;
		return *this;
	}
	// ����
	Lerp operator++(int) {
		Lerp temp = *this;
		++* this;
		return temp;
	}
	// ����
	Lerp& Increment(float deltaTime) {
		param += deltaParam * deltaTime;
		return *this;
	}
	// ����
	Lerp& operator--() {
		param += -deltaParam;
		return *this;
	}
	// ����
	Lerp operator--(int) {
		Lerp temp = *this;
		--* this;
		return temp;
	}
	// ����
	Lerp& Decrement(float deltaTime) {
		param += -deltaParam * deltaTime;
		return *this;
	}

	// ���`���
	static TYPE Calc(float par, const TYPE& sta, const TYPE& end) {
		return 	sta + (end - sta) * par;
	}
	// �v�Z
	TYPE Calc() const {
		return 	start + (end - start) * param;
	}
	// �v�Z
	// �֐��|�C���^�ŃC�[�W���O������
	TYPE Calc(float (* easinc_func)(float)) const {
		return 	start + (end - start) * easinc_func(param);
	}

	bool IsStart() const { return param == 0.0f; }
	bool IsEnd() const { return param == 1.0f; }
	// �[
	bool IsEdge() const { return IsStart() || IsEnd(); }
	// 0����
	bool IsUnder() const { return param < 0.0f; }
	// 1�𒴂���
	bool IsOver() const { return 1.0f < param; }
	// �͈͊O
	bool IsOutRange() const { return IsUnder() || IsOver(); }

	// ���߂�
	void ParamClamp() {
		if (IsUnder()) {
			param = 0.0f;
		}
		if (IsOver()) {
			param = 1.0f;
		}
	}

	// �^�ϊ�
	operator TYPE () const{
		return Calc();
	}
};

// ���`��ԃN���X�ifloat���ꉻ �t�Z�ǉ��j
template<>
class Lerp<float>
{
private:
	float param; // �ω��l
	float deltaParam; // �ω���
	float start, end; // �X�^�[�g�A�G���h
public:
	Lerp() : param(0), deltaParam(0), start(), end() {}
	Lerp(float sta, float end) : param(0), deltaParam(0), start(sta), end(end) {}
	Lerp(float dpa, float sta, float end) : param(0), deltaParam(dpa), start(sta), end(end) {};
	Lerp(float par, float dpa, float sta, float end) : param(par), deltaParam(dpa), start(sta), end(end) {};

	// �A�N�Z�b�T

	float Param() const { return param; }
	float DeltaParam() const { return deltaParam; }
	float Start() const { return start; }
	float End() const { return end; }

	void SetParam(float par) { param = par; }
	void SetDeltaParam(float dpa) { deltaParam = dpa; }
	void SetStart(float sta) { start = sta; }
	void SetEnd(float en) { end = en; }

	//

	void Set(float par, float dpa, float sta, float end) {
		SetParam(par);
		SetDeltaParam(dpa);
		SetStart(sta);
		SetEnd(end);
	}

	// ����
	Lerp& operator++() {
		param += deltaParam;
		return *this;
	}
	// ����
	Lerp operator++(int) {
		Lerp temp = *this;
		++* this;
		return temp;
	}
	// ����
	Lerp& Increment(float deltaTime) {
		param += deltaParam * deltaTime;
		return *this;
	}
	// ����
	Lerp& operator--() {
		param += -deltaParam;
		return *this;
	}
	// ����
	Lerp operator--(int) {
		Lerp temp = *this;
		--* this;
		return temp;
	}
	// ����
	Lerp& Decrement(float deltaTime) {
		param += -deltaParam * deltaTime;
		return *this;
	}

	// ���`���
	static float Calc(float par, float sta, float end) {
		return 	sta + par * (end - sta);
	}
	// �v�Z
	float Calc() const {
		return 	start + param * (end - start);
	}
	// �v�Z
	// �֐��|�C���^�ŃC�[�W���O������
	float Calc(float (*easinc_func)(float)) const {
		return 	start + easinc_func(param) * (end - start);
	}
	// �t�Z
	static float InverseCalc(float param, float sta, float end) {
		return (-sta + param) / (end - sta);
	}
	// �t�Z
	float InverseCalc(float param) const {
		return (-start + param) / (end - start);
	}

	bool IsStart() const { return param == 0.0f; }
	bool IsEnd() const { return param == 1.0f; }
	// �[
	bool IsEdge() const { return IsStart() || IsEnd(); }
	// 0����
	bool IsUnder() const { return param < 0.0f; }
	// 1�𒴂���
	bool IsOver() const { return 1.0f < param; }
	// �͈͊O
	bool IsOutRange() const { return IsUnder() || IsOver(); }

	// ���߂�
	void ParamClamp() {
		if (IsUnder()) {
			param = 0.0f;
		}
		if (IsOver()) {
			param = 1.0f;
		}
	}

	// �^�ϊ�
	operator float () const {
		return Calc();
	}
};
