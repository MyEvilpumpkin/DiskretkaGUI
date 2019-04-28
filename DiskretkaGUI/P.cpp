#include "P.h"
#include "PRecognizer.h"
#include "Exceptions.h"
#include "TemplateOperations.h"

P::P() : coefficients(nullptr), power(0) {

}

P::P(const std::string str) : P() {
	PRecognizer recognizer(str);
	bool status = recognizer.GetStatus();
	if (status) {
		struct Part {
			Q coefficient;
			int power;
			Part() : coefficient(), power(0) {}
		};
		Part* parts = nullptr;
		std::string tempStr = recognizer.GetPreparedString();
		size_t pos = 0;
		bool isEnd = false;
		int maxPower = -1;
		size_t numOfParts = 0;
		do {
			int pow = 0;
			bool isX = false;
			bool isDenom = false;
			Q q;
			q.numerator.sign = tempStr[pos] == '+';
			while (tempStr[pos + 1] != '+' && tempStr[pos + 1] != '-' && tempStr[pos + 1] != '\0') {
				if (tempStr[pos + 1] == 'x')
					isX = true;
				if (tempStr[pos + 1] == '/')
					isDenom = true;
				if (tempStr[pos + 1] >= '0' && tempStr[pos + 1] <= '9')
					if (isX)
						pow = pow * 10 + tempStr[pos + 1] - '0';
					else
						if (isDenom) {
							renew<digit>(q.denominator.digits, q.denominator.size, q.denominator.size + 1);
							q.denominator.digits[q.denominator.size++] = tempStr[pos + 1] - '0';
						}
						else {
							renew<digit>(q.numerator.number.digits, q.numerator.number.size, q.numerator.number.size + 1);
							q.numerator.number.digits[q.numerator.number.size++] = tempStr[pos + 1] - '0';
						}
				pos++;
			}
			if (tempStr[pos + 1] == '\0')
				isEnd = true;
			else
				pos++;
			if (!q.denominator.size)
				q.denominator.SetOne();
			else {
				for (size_t i = 0; i < (q.denominator.size / 2); i++) {
					digit temp = q.denominator.digits[i];
					q.denominator.digits[i] = q.denominator.digits[q.denominator.size - 1 - i];
					q.denominator.digits[q.denominator.size - 1 - i] = temp;
				}
			}
			if (!q.numerator.number.size)
				q.numerator.number.SetOne();
			else {
				for (size_t i = 0; i < (q.numerator.number.size / 2); i++) {
					digit temp = q.numerator.number.digits[i];
					q.numerator.number.digits[i] = q.numerator.number.digits[q.numerator.number.size - 1 - i];
					q.numerator.number.digits[q.numerator.number.size - 1 - i] = temp;
				}
			}
			if (isX && !pow)
				pow = 1;
			if (pow > maxPower)
				maxPower = pow;
			renew<Part>(parts, numOfParts, numOfParts + 1);
			parts[numOfParts].coefficient = q;
			parts[numOfParts++].power = pow;
		} while (!isEnd);
		coefficients = new Q[maxPower + 1];
		power = maxPower;
		for (int i = 0; i <= maxPower; i++)
			coefficients[i].SetZero();
		for (size_t i = 0; i < numOfParts; i++)
			coefficients[parts[i].power] = ADD_QQ_Q(coefficients[parts[i].power], parts[i].coefficient);
		delete[] parts;
		Normalize();
	}
	else
		throw IncorrectString();
}

P::P(const P& p) : P() {
	if (this != &p)
		if (p.coefficients != nullptr) {
			power = p.power;
			coefficients = new Q[power + 1];
			for (size_t i = 0; i < power + 1; i++)
				coefficients[i] = p.coefficients[i];
		}
}

P::P(P&& p) noexcept : P() {
	if (this != &p) {
		power = p.power;
		coefficients = p.coefficients;
		p.power = 0;
		p.coefficients = nullptr;
	}
}

P::~P() {
	delete[] coefficients;
}

P& P::operator=(const P& p) {
	if (this != &p) {
		if (p.coefficients != nullptr) {
			delete[] coefficients;
			power = p.power;
			coefficients = new Q[power + 1];
			for (size_t i = 0; i < power + 1; i++)
				coefficients[i] = p.coefficients[i];
		}
	}
	return *this;
}

P& P::operator=(P&& p) noexcept {
	if (this != &p) {
		delete[] coefficients;
		power = p.power;
		coefficients = p.coefficients;
		p.power = 0;
		p.coefficients = nullptr;
	}
	return *this;
}

void P::SetZero() {
	coefficients = new Q[1];
	coefficients[0].SetZero();
}

void P::SetOne() {
	coefficients = new Q[1];
	coefficients[0].SetOne();
}

bool P::IsZero() const {
	if (!power && coefficients != nullptr)
		return coefficients[0].IsZero();
	else
		return (false);
}

bool P::IsOne() const {
	if (!power && coefficients != nullptr)
		return coefficients[0].IsOne();
	else
		return (false);
}

std::string P::ToString() const {
	std::string str;
	for (int i = (int)power; i >= 0; i--) {
		if (!(coefficients[i].IsZero())) {
			if (i != power)
				if (coefficients[i].numerator.sign)
					str += "+ ";
			if (coefficients[i].IsOne() && i != 0) {
				if (!coefficients[i].numerator.sign)
					str += "- ";
			}
			else {
				str += coefficients[i].ToString();
				if (i != 0)
					str += " * ";
			}
			if (i > 1) {
				str += "x^";
				str += std::to_string(i);
				str += " ";
			}
			else if (i == 1)
				str += "x ";
		}
		else if (power == 0)
			str += "0";
	}
	return str;
}

void P::Normalize() {
	if (power > 0) {
		int i;
		bool flag = true;
		for (i = (int)power; i >= 0 && flag; i--) // ���� �� ��������� ������� ��� ���� ������ ����
			if (POZ_Z_D(coefficients[i].numerator)) // ���� ����������� ����������� - �� ���� 
				flag = false; // �������� ����
		if (!flag || i == -1) {
			renew<Q>(coefficients, power + 1, (size_t)i + (size_t)2);
			power = (size_t)i + (size_t)1;
		}
	}
}

// P-1
P ADD_PP_P(const P& p1, const P& p2) {
	P result;
	const P* first,* second;
	if (p1.power> p2.power) { // ����������, � ������ ���������� ������� ������ �, ���� ����, �������� �� �������
		first = &p1;
		second = &p2;
	}
	else {
		first = &p2;
		second = &p1;
	}
	result.coefficients = new Q[first->power + 1]; // �������� ������ ��� ����� �����������
	result.power = first->power; // ������� ����� ����� ������� �������� �� �����������
	for (size_t i = 0; i <= first->power; i++) { // ���� �� ������� ������� �������� ����� �� ��������� 
		if (i > second->power) // ���� ����������� ������� ������� ���������� ������ ������� �������
			result.coefficients[i] = first->coefficients[i]; // ����������� ����� ����������� ������� ���������� (�.�. � ������� �� � ������ ���)
		else
			result.coefficients[i] = ADD_QQ_Q(first->coefficients[i], second->coefficients[i]); // ����� ���������� �������� �������������
	}
	result.Normalize();
	return result;
}

// P-2
P SUB_PP_P(const P& p1, const P& p2) {
	P result;
	size_t maxPower = p1.power > p2.power ? p1.power : p2.power;
	result.coefficients = new Q[maxPower + 1]; // �������� ������ ��� �������� �����������
	result.power = maxPower; // ������� �������� ����� ������� �������� �� �����������
	if (maxPower == p1.power)
		for (size_t i = 0; i <= maxPower; i++) // ���� �� ������� ������� �������� ����� �� ���������
			if (i > p2.power) // ���� ����������� ������� ������� ���������� ������ ������� �������
				result.coefficients[i] = p1.coefficients[i];
			else
				result.coefficients[i] = SUB_QQ_Q(p1.coefficients[i], p2.coefficients[i]); // ����� ���������� ��������� �������������
	else
		for (size_t i = 0; i <= maxPower; i++) // ���� �� ������� ������� �������� ����� �� ���������
			if (i > p1.power) { // ���� ����������� ������� ������� ���������� ������ ������� �������
				Q temp;
				temp.SetZero();
				result.coefficients[i] = SUB_QQ_Q(temp,p2.coefficients[i]);
			}
			else
				result.coefficients[i] = SUB_QQ_Q(p1.coefficients[i], p2.coefficients[i]); // ����� ���������� ��������� �������������
	result.Normalize();
	return result;
}

// P-3
P MUL_PQ_P(const P& p, const Q& q) {
	P result;
	result.coefficients = new Q[p.power + 1];
	result.power = p.power;
	for (size_t i = 0; i <= result.power; i++) // ���� �� �������� ������������ �� ��������
		result.coefficients[i] = MUL_QQ_Q(p.coefficients[i], q); // ����������� �������� ������������ ��������� ������������ �������� ������������ ���������
	result.Normalize();
	return result; // ���������� �� ������������ �����
}

// P-4
P MUL_Pxk_P(const P& p, const unsigned int k) {
	P result;
	result.coefficients = new Q[p.power + k + 1]; // ��������� ������
	result.power = p.power + k; // ����������� ������� ����������-���������� ����� ������� ��������� ���������� � ������� k
	for (size_t i = k; i <= result.power; i++) // ���� �� �������� ������������ ���������� �� ������� k
		result.coefficients[i] = p.coefficients[i - k]; // ����������� �������� ������������ ����������-���������� ����������� ��������� ���������� "���������" �� k
	if (k)
		for (size_t i = 0; i <= k - 1; i++) // ���� �� ������� k-1 �� �������� ������������ ����������
			result.coefficients[i].SetZero(); // ������� ��� ��������� �� ���� �������
	result.Normalize();
	return result;
}

// P-5
Q LED_P_Q(const P& p) {
	return RED_Q_Q(p.coefficients[p.power]); // ���������� ����������� �������� �������� ������������
}

// P-6
N DEG_P_N(const P& p) {
	return N(std::to_string(p.power));
}

// P-7
Q FAC_P_Q(const P& p) {
	Q temp;
	temp.SetOne();
	Q result; // ��������� ����� - ��� ����������, ����������� - ��� ������������
	if (p.IsZero())
		result.SetZero();
	else {
		N nod = TRANS_Z_N(TRANS_Q_Z(p.coefficients[p.power])); // ��� ����������, ���������� ����������� ��������, ������ ��������� �������� ������������ ����������
		N nok = TRANS_Z_N(TRANS_Q_Z(DIV_QQ_Q(temp, p.coefficients[p.power]))); // ��� ������������, ���������� ����������� ��������, ������ ����������� �������� ������������ ����������
		for (int i = (int)p.power - 1; i >= 0; i--) // ���������� ��� ������������ ����������, ������� � "������������" (�.�. ������� ����� � ��� ����������)
			if (!p.coefficients[i].IsZero())
				nok = LCM_NN_N(nok, TRANS_Z_N(TRANS_Q_Z(DIV_QQ_Q(temp, p.coefficients[i])))); // ������� ���������� ��� ������ ��� � ������� ������������	
		for (int i = (int)p.power - 1; i >= 0; i--) // ���������� ��� ������������ ����������, ������� � "������������" (�.�. ������� ����� � ��� ����������)
			if (!p.coefficients[i].IsZero())
				nod = GCF_NN_N(nod, TRANS_Z_N(TRANS_Q_Z(p.coefficients[i]))); // ������� ���������� ��� ������ ��� � ������� ������������
		result = TRANS_Z_Q(TRANS_N_Z(nod));
		result = DIV_QQ_Q(result, TRANS_Z_Q(TRANS_N_Z(nok)));
	}
	return result;
}

// P-8
P MUL_PP_P(const P& p1, const P& p2) {
	P result;
	result.SetZero();
	for (size_t i = 0; i <= p1.power; i++)
		result = ADD_PP_P(result, MUL_Pxk_P(MUL_PQ_P(p2, p1.coefficients[i]), (const unsigned int)i));
	return result;
}

// P-9
P DIV_PP_P(const P& p1, const P& p2) {
	P result; // ������� �� ������� �����������
	if (p2.IsZero())
		throw DivisionByZero();
	if (p1.power < p2.power)
		result.SetZero();
	else {
		result.power = p1.power - p2.power;
		result.coefficients = new Q[result.power + 1];
		P part = p1; // ������� �� �������
		for (int i = (int)p1.power; i >= (int)p2.power; i--) {
			if (i <= part.power)
				result.coefficients[i - p2.power] = DIV_QQ_Q(part.coefficients[i], p2.coefficients[p2.power]); // ���������� ������������ ����� �������� � ����������
			else
				result.coefficients[i - p2.power].SetZero();
			part = SUB_PP_P(part, MUL_Pxk_P(MUL_PQ_P(p2, result.coefficients[i - p2.power]), (const unsigned int)(i - p2.power))); // �������� �� ������� ����� ��������, ���������� �� ��������
		}
	}
	return result;
}

// P-10
P MOD_PP_P(const P& p1, const P& p2) {
	P result = SUB_PP_P(p1, MUL_PP_P(DIV_PP_P(p1, p2), p2)); // �������� �������� ���������� � ������������ ���������� �� ������� �������� ���������� �� ������� ��� ������� � �������� ����������
	result.Normalize();
	return result;
}

// P-11
P GCF_PP_P(const P& p1, const P& p2) {
	P result;
	P first = p1;
	P second = p2;
	while (!second.IsZero() && !first.IsZero()) // ���� ���� ��� ���������� - �� �������
		if (first.power > second.power) // ���� ������� ������� ���������� ������ ������� �������
			first = MOD_PP_P(first, second); // ����������� ��� ������� �� ������� �����������
		else if (first.power < second.power)
			second = MOD_PP_P(second, first);
		else {
			Q q1 = LED_P_Q(p1);
			Q zero;
			zero.SetZero();
			if (POZ_Z_D(TRANS_Q_Z(q1)) == 1)
				q1 = SUB_QQ_Q(zero, q1);
			Q q2 = LED_P_Q(p2);
			if (POZ_Z_D(TRANS_Q_Z(q2)) == 1)
				q2 = SUB_QQ_Q(zero, q2);
			if (POZ_Z_D(TRANS_Q_Z(SUB_QQ_Q(q1, q2))) != 1)
				first = MOD_PP_P(first, second); // ����������� ��� ������� �� ������� �����������
			else
				second = MOD_PP_P(second, first);
		}
	if (second.IsZero()) // ���� ������� ������� ���������� ��������� ������ �������
		result = first; // ����������� ���������� (�������) �������� ������� ����������
	else
		result = second; // ��������
	if (POZ_Z_D(TRANS_Q_Z(LED_P_Q(result))) == 1) {
		P zero;
		zero.SetZero();
		result = SUB_PP_P(zero, result);
	}
	return result;
}

// P-12
P DER_P_P(const P& p) {
	P result;
	if (!p.power)
		result.SetZero();
	else {
		result.coefficients = new Q[p.power];
		result.power = p.power - 1;
		for (int i = (int)p.power - 1; i >= 0; i--) // ���� �� �������� ������������ ����������
			result.coefficients[i] = MUL_QQ_Q(p.coefficients[i + 1], TRANS_Z_Q(TRANS_N_Z(N(std::to_string(i + 1))))); // ����������� �������� ������������ �������� 
	}
	return result;
}

// P-13
P NMR_P_P(const P& p) {
	P result;
	if (p.power) {
		result = DIV_PP_P(p, GCF_PP_P(p, DER_P_P(p))); // ������� �� ������� �����������  
		Q temp;
		temp.SetOne();
		result = MUL_PQ_P(result, DIV_QQ_Q(temp, FAC_P_Q(result))); // ����������� ���������� �������� ������������
	}
	else
		result = p;
	return result;
}

