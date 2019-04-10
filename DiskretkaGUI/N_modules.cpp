#include "N_modules.h"

// ���� ��������������� ����� int
int getNumber()
{
	char* number = nullptr, symbol;
	int length;
	bool error;
	do
	{
		length = 0;
		error = false;
		do
		{
			symbol = getchar();
			if (symbol >= '0' && symbol <= '9')
			{
				number = (char*)realloc(number, (length + 1) * sizeof(char));
				number[length++] = symbol;
			}
			else if (symbol != '\n')
				error = true;
		} while (symbol != '\n');
		if (error)
			printf("������� ������������ ������. ������� ��������������� �����: ");
	} while (error || length == 0);
	number = (char*)realloc(number, (length + 1) * sizeof(char));
	number[length] = '\0';
	int toReturn = atoi(number);
	free(number);
	return toReturn;
}
// �������� ������ ����� � ������ �����
N* deNullN(N* n)
{
	if (n->len > 1)
	{
		int i;
		bool flag = false;
		for (i = n->len - 1; i >= 0 && !flag; i--)
			flag = n->n[i];
		n->n = (_byte*)realloc(n->n, (i + 2) * sizeof(_byte));
		n->len = i + 2;
	}
	return n;
}
// ������� �� int � N
N* intToN(int d)
{
	N* n = (N*)malloc(sizeof(N));
	int len = 0, buffer = d;
	while (buffer > 0)
	{
		buffer = buffer / 10;
		len++;
	}
	if (!len)
		len++;
	n->len = len;
	n->n = (_byte*)malloc(len * sizeof(_byte));
	for (int i = len - 1; i >= 0; i--)
	{
		n->n[len - 1 - i] = d % 10;
		d /= 10;
	}
	return n;
}
// ������� �� N � int
int NToInt(N* n) {
	int d = 0;
	for (int i = n->len - 1; i >= 0; i--)
		d = d * 10 + n->n[i];
	return d;
}
// ������������� � ����������
N* zeroN()
{
	N* n = (N*)malloc(sizeof(N));
	n->n = (_byte*)malloc(sizeof(_byte));
	n->n[0] = 0;
	n->len = 1;
	return n;
}
// ������������
N* assignmentN(N* n)
{
	N* result = (N*)malloc(sizeof(N));
	result->n = (_byte*)malloc(n->len * sizeof(_byte));
	for (unsigned int i = 0; i < n->len; i++)
		result->n[i] = n->n[i];
	result->len = n->len;
	return result;
}
// �������������� � ������
std::string getString(N* n) {
	std::string str;
	for (int i = n->len - 1; i >= 0; i--)
		str += (n->n[i] + '0');
	return str;
}
// ������������ ������
N* freeN(N* n)
{
	free(n->n);
	free(n);
	return n;
}

// N-1
int COM_NN_D(N* n1, N* n2)
{
	if (n1->len > n2->len) // ���� ������ ����� ������ �������
		return 2;
	else if (n1->len < n2->len) // ���� ������ ����� ������ �������
		return 1;
	else
	{
		for (int i = n1->len - 1; i >= 0; i--) // ���� �� ��������� �����
			if (n1->n[i] > n2->n[i]) // ���� ����� ������� ����� ������ ����� �������
				return 2;
			else if (n1->n[i] < n2->n[i]) // ��������
				return 1;
		return 0; // ���� ����� ���� ����� � ��� �� ����� ��������� ����� (����� �����)
	}
}
// N-2
bool NZER_N_B(N* n)
{
	return (n->len != 1 || n->n[0] != 0); // ����� ����� 0, ���� � ����� ���� ������ ���� ������ � �� ����� 0
}
// N-3
N* ADD_1N_N(N* n)
{
	N* result = assignmentN(n);
	if (result->n[0] != 9) // ���� ��������� ������ ����� �� ����� 9, �� ���������� � ���� �������
		result->n[0]++;
	else // ���� ��������� ������ ����� 9, �� �������� ��� � ��� ����������� ������� �� ���� � ���������� ������� � ������ �� ������� 
	{
		unsigned int count = 0;
		while (result->n[count] == 9)
			result->n[count++] = 0;
		if (count == result->len) // ���� � ����� ��� ����� �������, �� ���������� ������� ����� ������
		{
			result->n = (_byte*)realloc(result->n, ++result->len * sizeof(_byte));  // ������ ����� ������
			result->n[count] = 1; // �������� ������ ������� ����� �������
		}
		else
			result->n[count]++; // ���� � ����� �� ��� �������, �� ������ �� ������� ����������� �� �������
	}
	return result;
}
// N-4
N* ADD_NN_N(N* n1, N* n2)
{
	N* result = (N*)malloc(sizeof(N));
	bool temp = false;
	N *first, *second;
	if (COM_NN_D(n1, n2) == 2) // ���� n1>n2
	{
		first = n1;
		second = n2;
	}
	else // ���� n1<n2
	{
		first = n2;
		second = n1;
	}
	result->n = (_byte*)malloc(first->len * sizeof(_byte));
	result->len = first->len;
	for (unsigned int i = 0; i < first->len; i++)
	{
		if (i < second->len)
		{
			result->n[i] = first->n[i] + second->n[i] + temp; // ���������� ��������������� �������
			temp = result->n[i] > 9;
			result->n[i] %= 10; // ���������� ������
		}
		else if (temp)
		{
			result->n[i] = first->n[i] + temp; // ����������� ��������������� �������
			temp = result->n[i] > 9;
			result->n[i] %= 10; // ���������� ������
		}
		else
			result->n[i] = first->n[i];
	}
	if (temp) // ������� ������, ���� �����
	{
		result->n = (_byte*)realloc(result->n, ++result->len * sizeof(_byte));
		result->n[result->len - 1] = temp;
	}
	return result;
}
// N-5
N* SUB_NN_N(N* n1, N* n2)
{
	N* result;
	bool temp = false;
	if (COM_NN_D(n1, n2) == 2) // �������� �� ������������ ��������� ������
	{
		result = (N*)malloc(sizeof(N));
		result->n = (_byte*)malloc(n1->len * sizeof(_byte)); // ��������� ������ ��� ��������� ����� ����������
		result->len = n1->len;
		for (unsigned int i = 0; i < n1->len; i++) // ���� �� ����� �����
		{
			if (i < n2->len) // ���� ������� ������ ����� �������� ����� (����� "�������������" ���� �� �����)
			{
				result->n[i] = n1->n[i] - n2->n[i] - temp; // �������� ������������ ���������
				temp = result->n[i] < 0;
				if (temp)
					result->n[i] += 10;
			}
			else
			{
				if (temp)
					if (n1->n[i] == 0)
						result->n[i] = 9;
					else
					{
						result->n[i] = n1->n[i] - temp;
						temp = false;
					}
				else
					result->n[i] = n1->n[i]; // ����� �� ������ � ������� �� ������, � ������ "������������" �� � ���������
			}
		}
		deNullN(result); // ����������� �������������� ���������� ����
	}
	else
		result = zeroN();
	return result;
}
// N-6
N* MUL_ND_N(N* n, int d)
{
	N* result;
	if (!d)
		result = zeroN();
	else if (d == 1)
		result = assignmentN(n);
	else
	{
		result = (N*)malloc(sizeof(N));
		result->len = n->len;
		result->n = (_byte*)malloc(result->len * sizeof(_byte));
		int temp = 0;
		for (unsigned int i = 0; i < n->len; i++)
		{
			result->n[i] = n->n[i] * d + temp; // ������������� ��������� = ������ * ����� + �������
			temp = result->n[i] / 10; // ���������� �������
			result->n[i] %= 10; // ���������� ������
		}
		if (temp) // ������ ��� ���� ������, ���� ������� �� 0
		{
			result->n = (_byte*)realloc(result->n, ++result->len * sizeof(_byte));
			result->n[result->len - 1] = temp;
		}
	}
	return result;
}
// N-7
N* MUL_Nk_N(N* n, unsigned int k)
{
	N* result;
	if (!NZER_N_B(n))
		result = zeroN();
	else
	{
		result = (N*)malloc(sizeof(N));
		result->len = n->len + k; // �������������� ������ ������ ����� ��������� ����� � �������� ������� k
		result->n = (_byte*)malloc(result->len * sizeof(_byte)); // �������� ������ ��� ������ �����
		for (unsigned int i = 0; i < result->len; i++) // ���� �� ����� �����
			if (i < k) // ���� ������� ������ ������ k
				result->n[i] = 0; // "���������" ���� ����� �� 10
			else
				result->n[i] = n->n[i - k]; // ����������� �� ����� ������� (�� k ������) ����� ��������� �����
	}
	return result;
}
// N-8
N* MUL_NN_N(N* n1, N* n2)
{
	N *result = zeroN();
	if (NZER_N_B(n1) && NZER_N_B(n2))
		for (unsigned int i = 0; i < n2->len; i++) // � ����������, ���������� ������� 0, � ������ ���� ����� ������������ i-�� ����� ������� �����������
		{
			N* tmp = MUL_ND_N(n1, n2->n[i]);
			N* temp = MUL_Nk_N(tmp, i); // ���������� �� ������ ����������� � �� 10^i
			freeN(tmp);
			tmp = ADD_NN_N(result, temp);
			freeN(result);
			freeN(temp);
			result = tmp;
		}
	return result;
}
// N-9
N* SUB_NDN_N(N* n1, int d, N* n2)
{
	N *result, *temp;
	if (COM_NN_D(n1, n2) == 2) // ���� ������ ����� ������ �������
	{
		temp = MUL_ND_N(n2, d); // ������� ��������� �� �����
		result = SUB_NN_N(n1, temp); // �������� �� �������� ����� ������� (����������� �� �����)
	}
	else
	{
		temp = MUL_ND_N(n1, d); // ������� ��������� �� �����
		result = SUB_NN_N(n2, temp); // �������� �� �������� ����� ������� (����������� �� �����)
	}
	freeN(temp);
	return result;
}
// N-10
int DIV_NN_Dk(N* n1, N* n2, int& k)
{
	int result = 1, flag;
	k = 0;
	N *first, *second;
	int com = COM_NN_D(n1, n2);
	if (com == 2) // ���� ������� - ������ �����
	{
		first = n1;
		second = n2;
	}
	else // ���� ������� - ������ �����
	{
		first = n2;
		second = n1;
	}
	if (com)
	{
		k = first->len - second->len;
		N* temp = MUL_Nk_N(second, k);
		if (COM_NN_D(first, temp) == 1)
		{
			freeN(temp);
			temp = MUL_Nk_N(second, --k); // ��������� ���������� ������������ �������� � 10^k, ������� ��������
		}
		do
		{
			N* tmp = MUL_ND_N(temp, ++result); // ��������� ������������ �� �����
			flag = COM_NN_D(first, tmp); // ���������� ��� � �������
			freeN(tmp);
		} while (flag != 1);
		result--; // ���������� �������� �������
		freeN(temp);
	}
	return result;
}
// N-11
N* DIV_NN_N(N* n1, N* n2)
{
	N* result = zeroN(); // ������� �� �������
	N *first, *second;
	int com = COM_NN_D(n1, n2);
	if (com == 2)
	{
		first = n1;
		second = n2;
	}
	else
	{
		first = n2;
		second = n1;
	}
	if (com)
	{
		N* part = assignmentN(first); // ��������� ������� �� �������
		int k = 0;
		if (NZER_N_B(second))
			do
			{
				N* tempRes = zeroN(); // C������� ������������ ������ ����� ������� �� 10^k
				tempRes->n[0] = DIV_NN_Dk(part, second, k); // ��������� ������ ����� � ������� ������� ��� �������
				N* temp = MUL_Nk_N(tempRes, k); // �������� �� 10^k
				freeN(tempRes);
				tempRes = ADD_NN_N(result, temp); // ���������� ���������� ���������� � ������
				freeN(result);
				result = tempRes;
				tempRes = MUL_NN_N(temp, second);
				freeN(temp);
				temp = SUB_NN_N(part, tempRes); // ���������� ���������� �������
				freeN(part);
				part = temp;
				freeN(tempRes);
			} while (COM_NN_D(part, second) != 1);
		freeN(part);
	}
	else
		result->n[0] = 1;
	return result;
}
// N-12
N* MOD_NN_N(N* n1, N* n2)
{
	N *tmp, *result;
	N* temp = DIV_NN_N(n1, n2); // ��������� �� ������� �������� ����� �� �������
	if (COM_NN_D(n1, n2) == 2)
	{
		tmp = MUL_NN_N(temp, n2); // ������������ ��������� � �������� �����
		result = SUB_NN_N(n1, tmp); // �������� �������� ����� � ������������
	}
	else
	{
		tmp = MUL_NN_N(temp, n1); // ������������ ��������� � �������� �����
		result = SUB_NN_N(n2, tmp); // �������� �������� ����� � ������������
	}
	freeN(temp);
	freeN(tmp);
	return result;
}
// N-13
N* GCF_NN_N(N* n1, N* n2)
{
	N *result, *temp;
	N* first = n1;
	N* second = n2;
	while (NZER_N_B(first) && NZER_N_B(second)) // ���� ��� ����� - �� ����
	{
		if (COM_NN_D(first, second) > 1) // ���� ������ ������ �������
		{
			temp = MOD_NN_N(first, second); // ������� ������� �� ������� ������� �� ������
			if (first != n1)
				freeN(first);
			first = temp;
		}
		else
		{
			temp = MOD_NN_N(second, first); // ����� - ������� �� ������� ������� �� ������
			if (second != n2)
				freeN(second);
			second = temp;
		}
	}
	if (COM_NN_D(first, second) != 2) // ���� ������ ����� - ������ �������
	{
		if (second != n2)
			result = second;
		else
			result = assignmentN(second);
		if (first != n1)
			freeN(first);
	}
	else
	{
		if (first != n1)
			result = first;
		else
			result = assignmentN(first);
		if (second != n2)
			freeN(second);
	}
	return result;
}
// N-14
N* LCM_NN_N(N* n1, N* n2)
{
	N* nod = GCF_NN_N(n1, n2); // ��� ���� �����
	N* temp = MUL_NN_N(n1, n2); // ������������ ���� �����
	N* nok = DIV_NN_N(temp, nod); // ��� ���� �����
	freeN(nod);
	freeN(temp);
	return nok;
}
