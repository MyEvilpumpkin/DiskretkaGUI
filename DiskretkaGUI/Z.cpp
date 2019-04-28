#include "Z.h"
#include "ZRecognizer.h"
#include "Exceptions.h"
#include "TemplateOperations.h"

Z::Z() : number(), sign(true) {

}

Z::Z(const std::string str) : Z() {
	ZRecognizer recognizer(str);
	bool status = recognizer.GetStatus();
	if (status) {
		std::string tempStr = recognizer.GetPreparedString();
		size_t pos = 0;
		sign = tempStr[pos] == '+';
		while (tempStr[pos + 1] != '\0') {
			renew<digit>(number.digits, number.size, number.size + 1);
			number.digits[number.size++] = tempStr[pos + 1] - '0';
			pos++;
		}
		for (size_t i = 0; i < (number.size / 2); i++) {
			digit temp = number.digits[i];
			number.digits[i] = number.digits[number.size - 1 - i];
			number.digits[number.size - 1 - i] = temp;
		}
	}
	else
		throw IncorrectString();
}

Z::Z(const Z& z) : Z() {
	if (this != &z) {
		number = z.number;
		sign = z.sign;
	}
}

Z::Z(Z&& z) noexcept : Z() {
	if (this != &z) {
		number = std::move(z.number);
		sign = z.sign;
	}
}

Z::~Z() {
	
}

Z& Z::operator=(const Z& z) {
	if (this != &z) {
		number = z.number;
		sign = z.sign;
	}
	return *this;
}

Z& Z::operator=(Z&& z) noexcept {
	if (this != &z) {
		number = std::move(z.number);
		sign = z.sign;
	}
	return *this;
}

void Z::SetZero() {
	number.SetZero();
	sign = true;
}

void Z::SetOne() {
	number.SetOne();
	sign = true;
}

bool Z::IsZero() const {
	return number.IsZero();
}

bool Z::IsOne() const {
	return (number.IsOne() && sign);
}

std::string Z::ToString() const {
	std::string str;
	if (!sign)
		str += '-';
	str += number.ToString();
	return str;
}

void Z::Normalize() {
	number.Normalize();
	if (number.IsZero())
		sign = true;
}

// Z-1
N ABS_Z_N(const Z& z) {
	return N(z.number); // ���������� ����� ����������� ����� ����� (����� = ����������� + ����)
}

// Z-2
int POZ_Z_D(const Z& z) {
	if (!NZER_N_B(z.number)) // ���� ����� = 0
		return 0;
	else if (!z.sign) // ���� ����� �������������
		return 1;
	else // ���� ����� �������������
		return 2;
}

// Z-3
Z MUL_ZM_Z(const Z& z) {
	Z result = z; // ����������� ���������� �������� �����
	if (POZ_Z_D(result)) // ���� ����� �� ����
		result.sign = !z.sign; // ������ ���� ���������� �� ���������������
	return result;
}

// Z-4
Z TRANS_N_Z(const N& n) {
	Z result;
	result.number = n; // ����������� ������ ���������� ����������� ����� 
	result.sign = true;
	return result;
}

// Z-5
N TRANS_Z_N(const Z& z) {
	return N(z.number); // ���������� ����� ����������� ����� �����
}

// Z-6
Z ADD_ZZ_Z(const Z& z1, const Z& z2) {
	Z result;
	if (z1.sign == z2.sign) { // ���� ����� ���� ����� ���������
		result.number = ADD_NN_N(z1.number, z2.number); // ���������� �� ������ ����������� �������� ����� ���� �����
		result.sign = z1.sign; // ����������� ���������� ����� ���� ���� �����
	}
	else {
		int com = COM_NN_D(z1.number, z2.number);
		if (com == 2) { // ���� ������ ����� ������ ������� �� ������
			result.number = SUB_NN_N(z1.number, z2.number); // �������� �� �������� ����� �������
			result.sign = z1.sign; // ����������� ���������� ���� ������� �����
		}
		else if (com == 1) { // ���� ������ ����� ������ ������� �� ������
			result.number = SUB_NN_N(z2.number, z1.number); // ��������
			result.sign = z2.sign;
		}
		else // ���� ����� �����
			result.SetZero(); // ��������� ����������� ����
	}
	return result;
}

// Z-7
Z SUB_ZZ_Z(const Z& z1, const Z& z2) {
	Z result;
	if (z1.sign != z2.sign) { // ���� ����� ���� ����� ������
		result.number = ADD_NN_N(z1.number, z2.number); // ���������� �� ������ ����������� �������� ����� ���� �����
		result.sign = z1.sign; // ����������� ���������� ����� ���� ���� �����
	}
	else {
		int com = COM_NN_D(z1.number, z2.number);
		if (com == 2) { // ���� ������ ����� ������ ������� �� ������
			result.number = SUB_NN_N(z1.number, z2.number); // �������� �� �������� ����� �������
			result.sign = z1.sign; // ����������� ���������� ���� ������� �����
		}
		else if (com == 1) { // ���� ������ ����� ������ ������� �� ������
			result.number = SUB_NN_N(z2.number, z1.number); // ��������
			result.sign = !z2.sign;
		}
		else // ���� ����� �����
			result.SetZero(); // ��������� ����������� ����
	}
	return result;
}

// Z-8
Z MUL_ZZ_Z(const Z& z1, const Z& z2) {
	Z result;
	result.number = MUL_NN_N(z1.number, z2.number); // ����������� ���������� �� ������ �������� ������������ ������� ����� �� ������ �� ������
	if (!POZ_Z_D(result)) // ���� �������� - 0
		result.sign = true; // �� ���� ���������� +
	else if (z1.sign == z2.sign) // ���� ����� ���� ����� �����
		result.sign = true; // �� ���� ���������� +
	else
		result.sign = false; // ���� ���������� -
	return result;
}

// Z-9
Z DIV_ZN_Z(const Z& z, const N& n) {
	Z result;
	if (n.IsZero())
		throw DivisionByZero();
	if (COM_NN_D(z.number, n) == 1)
		throw DivisionByMore();
	result.number = DIV_NN_N(z.number, n); // ����� ��� ����������� ����� ������� (��������������� � �����) �� �������
	result.sign = z.sign; // ����������� ����� ���������� ���� �������� �����
	if (!POZ_Z_D(result)) // ���� ��������� ����� ����
		result.sign = true; // �� ���� ���� +
	if (!result.sign && NZER_N_B(MOD_NN_N(z.number, n))) {
		Z one;
		one.SetOne();
		result = SUB_ZZ_Z(result, one);
	}
	return result;
}

// Z-10
Z MOD_ZN_Z(const Z& z, const N& n) {
	return SUB_ZZ_Z(z, MUL_ZZ_Z(DIV_ZN_Z(z, n), TRANS_N_Z(n)));
}

