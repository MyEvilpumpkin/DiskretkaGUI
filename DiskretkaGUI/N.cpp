#include "N.h"
#include "NRecognizer.h"
#include "Exceptions.h"
#include "TemplateOperations.h"

N::N() : digits(nullptr), size((size_t)0) {

}

N::N(const std::string str) : N() {
	NRecognizer recognizer(str);
	bool status = recognizer.GetStatus();
	if (status) {
		std::string tempStr = recognizer.GetPreparedString();
		int pos = 0;
		while (tempStr[pos] != '\0') {
			renew<digit>(digits, size, size + 1);
			digits[size++] = tempStr[pos] - '0';
			pos++;
		}
		for (size_t i = 0; i < (size / 2); i++) {
			digit temp = digits[i];
			digits[i] = digits[size - 1 - i];
			digits[size - 1 - i] = temp;
		}
	}
	else
		throw IncorrectString();
}

N::N(const N& n) : N() {
	if (this != &n) {
		if (n.size) {
			size = n.size;
			digits = new digit[size];
			memcpy(digits, n.digits, size * sizeof(digit));
		}
	}
}

N::N(N&& n) noexcept : N() {
	if (this != &n) {
		size = n.size;
		n.size = 0;
		digits = n.digits;
		n.digits = nullptr;
	}
}

N::~N() {
	delete[] digits;
}

N& N::operator=(const N& n) {
	if (this != &n) {
		delete[] digits;
		digits = nullptr;
		size = 0;
		if (n.size) {
			size = n.size;
			digits = new digit[size];
			memcpy(digits, n.digits, size * sizeof(digit));
		}
	}
	return *this;
}

N& N::operator=(N&& n) noexcept {
	if (this != &n) {
		delete[] digits;
		size = 0;
		size = n.size;
		n.size = 0;
		digits = n.digits;
		n.digits = nullptr;
	}
	return *this;
}

void N::SetZero() {
	delete[] digits;
	digits = nullptr;
	digits = new digit[1];
	digits[0] = 0;
	size = 1;
}

void N::SetOne() {
	delete[] digits;
	digits = nullptr;
	digits = new digit[1];
	digits[0] = 1;
	size = 1;
}

bool N::IsZero() const {
	return (size == 1 && digits[0] == 0);
}

bool N::IsOne() const {
	return (size == 1 && digits[0] == 1);
}

std::string N::ToString() const {
	std::string str;
	for (int i = (int)size - 1; i >= 0; i--)
		str += (digits[i] + '0');
	return str;
}

void N::Normalize() {
	if (size > 1) {
		int i;
		bool flag = false;
		for (i = (int)size - 1; i >= 0 && !flag; i--)
			flag = digits[i];
		renew<digit>(digits, size, (size_t)i + (size_t)2);
		size = (size_t)i + (size_t)2;
	}
}

unsigned int N::ToUInt() {
	unsigned int num = 0;
	for (int i = (int)size - 1; i >= 0; i--)
		num = num * 10 + digits[i];
	return num;
}

// N-1
int COM_NN_D(const N& n1, const N& n2) {
	if (n1.size > n2.size) // ���� ������ ����� ������ �������
		return 2;
	else if (n1.size < n2.size) // ���� ������ ����� ������ �������
		return 1;
	else {
		for (int i = (int)n1.size - 1; i >= 0; i--) // ���� �� ��������� �����
			if (n1.digits[i] > n2.digits[i]) // ���� ����� ������� ����� ������ ����� �������
				return 2;
			else if (n1.digits[i] < n2.digits[i]) // ��������
				return 1;
		return 0; // ���� ����� ���� ����� � ��� �� ����� ��������� ����� (����� �����)
	}
}

// N-2
bool NZER_N_B(const N& n) {
	return (n.size != 1 || n.digits[0] != 0); // ����� ����� 0, ���� � ����� ���� ������ ���� ������ � �� ����� 0
}

// N-3
N ADD_1N_N(const N& n) {
	N result = n;
	if (result.digits[0] != 9) // ���� ��������� ������ ����� �� ����� 9, �� ���������� � ���� �������
		result.digits[0]++;
	else { // ���� ��������� ������ ����� 9, �� �������� ��� � ��� ����������� ������� �� ���� � ���������� ������� � ������ �� ������� 
		size_t count = 0;
		while (result.digits[count] == 9)
			result.digits[count++] = 0;
		if (count == result.size) { // ���� � ����� ��� ����� �������, �� ���������� ������� ����� ������
			renew<digit>(result.digits, result.size, result.size + 1);
			result.size++;
			result.digits[count] = 1; // �������� ������ ������� ����� �������
		}
		else
			result.digits[count]++; // ���� � ����� �� ��� �������, �� ������ �� ������� ����������� �� �������
	}
	return result;
}

// N-4
N ADD_NN_N(const N& n1, const N& n2) {
	N result;
	bool temp = false;
	const N* first,* second;
	if (COM_NN_D(n1, n2) == 2) { // ���� n1>n2
		first = &n1;
		second = &n2;
	}
	else { // ���� n1<n2
		first = &n2;
		second = &n1;
	}
	result.digits = new digit[first->size];
	result.size = first->size;
	for (size_t i = 0; i < first->size; i++) {
		if (i < second->size) {
			result.digits[i] = first->digits[i] + second->digits[i] + temp; // ���������� ��������������� �������
			temp = result.digits[i] > 9;
			result.digits[i] %= 10; // ���������� ������
		}
		else if (temp) {
			result.digits[i] = first->digits[i] + temp; // ����������� ��������������� �������
			temp = result.digits[i] > 9;
			result.digits[i] %= 10; // ���������� ������
		}
		else
			result.digits[i] = first->digits[i];
	}
	if (temp) { // ������� ������, ���� �����
		renew<digit>(result.digits, result.size, result.size + 1);
		result.size++;
		result.digits[result.size - 1] = temp;
	}
	return result;
}

// N-5
N SUB_NN_N(const N& n1, const N& n2) {
	N result;
	bool temp = false;
	int com = COM_NN_D(n1, n2);
	if (com == 2) { // �������� �� ������������ ��������� ������
		result.digits = new digit[n1.size]; // ��������� ������ ��� ��������� ����� ����������
		result.size = n1.size;
		for (size_t i = 0; i < n1.size; i++) { // ���� �� ����� �����
			if (i < n2.size) { // ���� ������� ������ ����� �������� ����� (����� "�������������" ���� �� �����)
				result.digits[i] = n1.digits[i] - n2.digits[i] - temp; // �������� ������������ ���������
				temp = result.digits[i] < 0;
				if (temp)
					result.digits[i] += 10;
			}
			else {
				if (temp)
					if (n1.digits[i] == 0)
						result.digits[i] = 9;
					else {
						result.digits[i] = n1.digits[i] - temp;
						temp = false;
					}
				else
					result.digits[i] = n1.digits[i]; // ����� �� ������ � ������� �� ������, � ������ "������������" �� � ���������
			}
		}
		result.Normalize(); // ����������� �������������� ���������� ����
	}
	else if (com == 1)
		throw SubtractionError();
	else
		result.SetZero();
	return result;
}

// N-6
N MUL_ND_N(const N& n, const unsigned int d) {
	N result;
	if (d > 9)
		throw NotADigit();
	if (!d)
		result.SetZero();
	else if (d == 1)
		result = n;
	else {
		result.size = n.size;
		result.digits = new digit[result.size];
		int temp = 0;
		for (size_t i = 0; i < n.size; i++) {
			result.digits[i] = n.digits[i] * d + temp; // ������������� ��������� = ������ * ����� + �������
			temp = result.digits[i] / 10; // ���������� �������
			result.digits[i] %= 10; // ���������� ������
		}
		if (temp) { // ������ ��� ���� ������, ���� ������� �� 0
			renew<digit>(result.digits, result.size, result.size + 1);
			result.size++;
			result.digits[result.size - 1] = temp;
		}
	}
	return result;
}

// N-7
N MUL_Nk_N(const N& n, const unsigned int k) {
	N result;
	if (!NZER_N_B(n))
		result.SetZero();
	else {
		result.size = n.size + k; // �������������� ������ ������ ����� ��������� ����� � �������� ������� k
		result.digits = new digit[result.size]; // �������� ������ ��� ������ �����
		for (size_t i = 0; i < result.size; i++) // ���� �� ����� �����
			if (i < k) // ���� ������� ������ ������ k
				result.digits[i] = 0; // "���������" ���� ����� �� 10
			else
				result.digits[i] = n.digits[i - k]; // ����������� �� ����� ������� (�� k ������) ����� ��������� �����
	}
	return result;
}

// N-8
N MUL_NN_N(const N& n1, const N& n2) {
	N result;
	result.SetZero();
	if (NZER_N_B(n1) && NZER_N_B(n2))
		for (size_t i = 0; i < n2.size; i++) // � ����������, ���������� ������� 0, � ������ ���� ����� ������������ i-�� ����� ������� �����������
			result = ADD_NN_N(result, MUL_Nk_N(MUL_ND_N(n1, n2.digits[i]), (const unsigned int)i));  // ���������� �� ������ ����������� � �� 10^i
	return result;
}

// N-9
N SUB_NDN_N(const N& n1, const unsigned int d, const N& n2) {
	N result;
	if (d > 9)
		throw NotADigit();
	int com = COM_NN_D(n1, n2);
	result = SUB_NN_N(n1, MUL_ND_N(n2, d)); // �������� �� ������� ����� ������ (����������� �� �����)
	return result;
}

// N-10
int DIV_NN_Dk(const N& n1, const N& n2, int& k) {
	int result = 1, flag;
	k = 0;
	const N* first,* second;
	int com = COM_NN_D(n1, n2);
	if (com == 2) { // ���� ������� - ������ �����
		first = &n1;
		second = &n2;
	}
	else { // ���� ������� - ������ �����
		first = &n2;
		second = &n1;
	}
	if (second->IsZero())
		throw DivisionByZero();
	if (com) {
		k = (int)(first->size - second->size);
		N temp = MUL_Nk_N(*second, k);
		if (COM_NN_D(*first, temp) == 1)
			temp = MUL_Nk_N(*second, --k); // ��������� ���������� ������������ �������� � 10^k, ������� ��������
		do
			flag = COM_NN_D(*first, MUL_ND_N(temp, ++result)); // ��������� ������������ �� ����� � ���������� ��� � �������
		while (flag != 1 && result < 9);
		if (flag == 1)
			result--; // ���������� �������� �������
	}
	return result;
}

// N-11
N DIV_NN_N(const N& n1, const N& n2) {
	N result; // ������� �� �������
	result.SetZero();
	const N* first,* second;
	int com = COM_NN_D(n1, n2);
	if (com == 2) {
		first = &n1;
		second = &n2;
	}
	else {
		first = &n2;
		second = &n1;
	}
	if (second->IsZero())
		throw DivisionByZero();
	if (com) {
		N part = *first; // ��������� ������� �� �������
		int k = 0;
		if (NZER_N_B(*second))
			do {
				N tempRes; // C������� ������������ ������ ����� ������� �� 10^k
				tempRes.SetZero();
				tempRes.digits[0] = DIV_NN_Dk(part, *second, k); // ��������� ������ ����� � ������� ������� ��� �������
				N temp = MUL_Nk_N(tempRes, k); // �������� �� 10^k
				result = ADD_NN_N(result, temp); // �������� �� 10^k � ��������� ��������� ��������� � ������
				part = SUB_NN_N(part, MUL_NN_N(temp, *second)); // ���������� ���������� �������
			} while (COM_NN_D(part, *second) != 1);
	}
	else
		result.digits[0] = 1;
	return result;
}

// N-12
N MOD_NN_N(const N& n1, const N& n2) {
	N result;
	int com = COM_NN_D(n1, n2);
	if (com == 2)
		result = SUB_NN_N(n1, MUL_NN_N(DIV_NN_N(n1, n2), n2)); // �������� �������� ����� � ������������
	else if (com == 1)
		result = SUB_NN_N(n2, MUL_NN_N(DIV_NN_N(n1, n2), n1)); // �������� �������� ����� � ������������
	else
		result.SetZero();
	return result;
}

// N-13
N GCF_NN_N(const N& n1, const N& n2) {
	N result;
	N first = n1;
	N second = n2;
	while (NZER_N_B(first) && NZER_N_B(second)) // ���� ��� ����� - �� ����
		if (COM_NN_D(first, second) > 1) // ���� ������ ������ �������
			first = MOD_NN_N(first, second); // ������� ������� �� ������� ������� �� ������
		else
			second = MOD_NN_N(second, first); // ����� - ������� �� ������� ������� �� ������
	if (COM_NN_D(first, second) != 2) // ���� ������ ����� - ������ �������
		result = second;
	else
		result = first;
	return result;
}

// N-14
N LCM_NN_N(const N& n1, const N& n2) {
	return DIV_NN_N(MUL_NN_N(n1, n2), GCF_NN_N(n1, n2));
}

