#include "P_modules.h"

// �������� ���������� ��������� �� �������� ��������������
P* deNullP(P* p)
{
	if (p->len > 0)
	{
		int i;
		bool flag = true;
		for (i = p->len; i >= 0 && flag; i--) // ���� �� ��������� ������� ��� ���� ������ ����
			if (POZ_Z_D(p->k[i]->num)) // ���� ����������� ����������� - �� ���� 
				flag = false; // �������� ����
		if (!flag || i == -1)
		{
			for (int len = p->len; len > i + 1; len--)
				freeQ(p->k[len]);
			p->len = i + 1;
			p->k = (Q**)realloc(p->k, (p->len + 1) * sizeof(Q*));
		}
	}
	return p;
}

// ����
P* inputP()
{
	int amount;
	int maxPower = -1;
	P* p = (P*)malloc(sizeof(P));
	p->k = (Q**)malloc(sizeof(Q*));
	printf("������� ���������� �������������: ");
	do
	{
		amount = getNumber();
		if (amount == 0)
			printf("������� ������������ ������. ������� ����� > 0: ");
	} while (amount == 0);
	int* powerBuffer = (int*)malloc(amount * sizeof(int));
	for (int i = 0; i < amount; i++)
	{
		printf("***\n����������� %d\n", i + 1);
		Q* temp = inputQ();
		printf("������� ������� x: ");
		int power = getNumber();
		if (power > maxPower)
		{
			maxPower = power;
			p->k = (Q**)realloc(p->k, (maxPower + 1) * sizeof(Q*));
			p->len = maxPower;
		}
		bool f = false;
		for (int j = 0; j < i && !f; j++)
			if (powerBuffer[j] == power) f = true;
		if (f)
			freeQ(p->k[power]);
		p->k[power] = assignmentQ(temp);
		freeQ(temp);
		powerBuffer[i] = power;
	}
	for (int i = maxPower; i >= 0; i--)
	{
		bool f = false;
		for (int j = 0; j < amount && !f; j++)
			if (powerBuffer[j] == i) f = true;
		if (!f)
			p->k[i] = zeroQ();
	}
	free(powerBuffer);
	puts("");
	return p;
}
// ������������� � ����������
P* zeroP()
{
	P* p = (P*)malloc(sizeof(P));
	p->k = (Q**)malloc(sizeof(Q*));
	p->len = 0;
	p->k[0] = zeroQ();
	return p;
}
// ������������
P* assignmentP(P* p)
{
	P* result = (P*)malloc(sizeof(P));
	result->len = p->len;
	result->k = (Q**)malloc((result->len + 1) * sizeof(Q*));
	for (unsigned int i = 0; i <= result->len; i++)
		result->k[i] = assignmentQ(p->k[i]);
	return result;
}
// �����
void printP(P* p)
{
	for (int i = p->len; i >= 0; i--)
	{
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0))
		{
			if (i != p->len)
				if (p->k[i]->num->sign)
					printf("+ ");
			if (p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 1 && i != 0 && p->k[i]->denom->len == 1 && p->k[i]->denom->n[0] == 1)
			{
				if (!p->k[i]->num->sign)
					printf("- ");
			}
			else
			{
				printQ(p->k[i]);
				if (i != 0)
					printf(" * ");
			}
			if (i > 1)
				printf("x^%d ", i);
			else if (i == 1)
				printf("x ");
		}
		else if (p->len == 0)
			printf("0");
	}
}
// ������������ ������
P* freeP(P* p)
{
	for (unsigned int i = 0; i <= p->len; i++)
		freeQ(p->k[i]);
	free(p->k);
	free(p);
	return p;
}

// P-1
P* ADD_PP_P(P* p1, P* p2)
{
	P* result = (P*)malloc(sizeof(P));
	P *first, *second;
	if (p1->len > p2->len) // ����������, � ������ ���������� ������� ������ �, ���� ����, �������� �� �������
	{
		first = p1;
		second = p2;
	}
	else
	{
		first = p2;
		second = p1;
	}
	result->k = (Q**)malloc((first->len + 1) * sizeof(Q*)); // �������� ������ ��� ����� �����������
	result->len = first->len; // ������� ����� ����� ������� �������� �� �����������
	for (unsigned int i = 0; i <= first->len; i++) // ���� �� ������� ������� �������� ����� �� ��������� 
	{
		if (i > second->len) // ���� ����������� ������� ������� ���������� ������ ������� �������
			result->k[i] = assignmentQ(first->k[i]); // ����������� ����� ����������� ������� ���������� (�.�. � ������� �� � ������ ���)
		else
			result->k[i] = ADD_QQ_Q(first->k[i], second->k[i]); // ����� ���������� �������� �������������
	}
	return deNullP(result);
}
// P-2
P* SUB_PP_P(P* p1, P* p2)
{
    P* result = (P*)malloc(sizeof(P));
    P *first, *second;
    if (p1->len > p2->len) // ����������, � ������ ���������� ������� ������ �, ���� ����, �������� �� �������
    {
        first = p1;
        second = p2;
    }
    else
    {
        first = p2;
        second = p1;
    }
    result->k = (Q**)malloc((first->len + 1) * sizeof(Q*)); // �������� ������ ��� �������� �����������
    result->len = first->len; // ������� �������� ����� ������� �������� �� �����������
    for (unsigned int i = 0; i <= first->len; i++) // ���� �� ������� ������� �������� ����� �� ���������
    {
        if (i > second->len) // ���� ����������� ������� ������� ���������� ������ ������� �������
		{
            result->k[i] = assignmentQ(first->k[i]); // ����������� �������� ����������� ������� ���������� (�.�. � ������� �� � ������ ���)
            result->k[i]->num->sign = !result->k[i]->num->sign; // ������ ����
        }
        else
            result->k[i] = SUB_QQ_Q(p1->k[i], p2->k[i]); // ����� ���������� ��������� �������������
    }
    return deNullP(result);
}
// P-3
P* MUL_PQ_P(P* p, Q* q)
{
	P* result = (P*)malloc(sizeof(P));
	result->k = (Q**)malloc((p->len + 1) * sizeof(Q*));
	result->len = p->len;
	for (unsigned int i = 0; i <= result->len; i++) // ���� �� �������� ������������ �� ��������
		result->k[i] = MUL_QQ_Q(p->k[i], q); // ����������� �������� ������������ ��������� ������������ �������� ������������ ���������
	return deNullP(result); // ���������� �� ������������ �����
}
// P-4
P* MUL_Pxk_P(P* p, int k)
{
	P* result = (P*)malloc(sizeof(P));
	result->k = (Q**)malloc((p->len + k + 1) * sizeof(Q*)); // ��������� ������
	result->len = p->len + k; // ����������� ������� ����������-���������� ����� ������� ��������� ���������� � ������� k
	for (int i = result->len; i >= k; i--) // ���� �� �������� ������������ ���������� �� ������� k
		result->k[i] = assignmentQ(p->k[i - k]); // ����������� �������� ������������ ����������-���������� ����������� ��������� ���������� "���������" �� k
	for (int i = k - 1; i >= 0; i--) // ���� �� ������� k-1 �� �������� ������������ ����������
		result->k[i] = zeroQ(); // ������� ��� ��������� �� ���� �������
	return deNullP(result);
}
// P-5
Q* LED_P_Q(P* p)
{
	for (int i = p->len; i >= 0; i--) // ���� �� ������� ������� ���������� �� �������
		if (POZ_Z_D(p->k[i]->num)) // ���� ������� ����������� != 0
			return assignmentQ(RED_Q_Q(p->k[i])); // ���������� ����������� �������� ����� ������������
	return assignmentQ(RED_Q_Q(p->k[0])); // � ������� ������ ���������� ����������� �������� �������� ������������
}
// P-6
N* DEG_P_N(P* p)
{
	int power = 0; // ������� �������
	bool flag = true; // �������������� ���� ��� ��������
	for (int i = p->len; i >= 0 && flag; i--) // ���� �� �������� ������������ ���������� ��� ���� ������ ����
		if (POZ_Z_D(p->k[i]->num)) // ���� ����������� ����������� != 0
		{
			power = i; // ��������������� � �������� �������
			flag = false; // �������� ����
		}
	return intToN(power);
}
// P-7
Q* FAC_P_Q(P* p)
{
	N* nod = assignmentN(p->k[p->len]->num->number); // ��� ����������, ���������� ����������� ��������, ������ ��������� �������� ������������ ����������
	N* nok = assignmentN(p->k[p->len]->denom); // ��� ������������, ���������� ����������� ��������, ������ ����������� �������� ������������ ����������
	Q* result = (Q*)malloc(sizeof(Q)); // ��������� ����� - ��� ����������, ����������� - ��� ������������
	result->num = (Z*)malloc(sizeof(Z));
	N* temp;
	int i; // ��� �������� ������������� ����������
	for (i = (p->len) - 1; i >= 0; i--) // ���������� ��� ������������ ����������, ������� � "������������" (�.�. ������� ����� � ��� ����������)
	{
		temp = LCM_NN_N(nok, p->k[i]->denom); // ������� ���������� ��� ������ ��� � ������� ������������	
		freeN(nok);
		nok = temp;
	}
	for (i = (p->len) - 1; i >= 0; i--) // ���������� ��� ������������ ����������, ������� � "������������" (�.�. ������� ����� � ��� ����������)
	{
		int flag = POZ_Z_D(p->k[i]->num); // �������� ������������ �� ����
		if (flag) {
			temp = GCF_NN_N(nod, p->k[i]->num->number); // ������� ���������� ��� ������ ��� � ������� ������������
			freeN(nod);
			nod = temp;
		}
	}
	result->num->number = nod; // ����������� result->num �������� nod
	result->num->sign = true;
	result->denom = nok; // ����������� result->denom �������� ���
	return result;
}
// P-8
P* MUL_PP_P(P* p1, P* p2)
{
	P *result = zeroP();
	for (unsigned int i = 0; i <= p1->len; i++)
	{
		P* temp = MUL_PQ_P(p2, p1->k[i]); // �������� ������ ��������� ���������� �� ��� ������������ �������
		P* tmp = MUL_Pxk_P(temp, i); // �������� ������������ �� ������� ����������� ������� ������� ����������
		freeP(temp);
		temp = ADD_PP_P(result, tmp); // ����������� � ���������� ������������
		freeP(result);
		result = temp;
		freeP(tmp);
	}
	return result;
}
// P-9
P* DIV_PP_P(P* p1, P* p2)
{
	P* result; // ������� �� ������� �����������
	if (p1->len < p2->len)
		result = zeroP();
	else
	{
		result = (P*)malloc(sizeof(P));
		result->len = p1->len - p2->len;
		result->k = (Q**)malloc((result->len + 1) * sizeof(Q*));
		P* part = assignmentP(p1); // ������� �� �������
		for (unsigned int i = p1->len; i >= p2->len; i--)
		{
			if (i <= part->len)
				result->k[i - p2->len] = DIV_QQ_Q(part->k[i], p2->k[p2->len]); // ���������� ������������ ����� �������� � ����������
			else
				result->k[i - p2->len] = zeroQ();
			P* temp = MUL_PQ_P(p2, result->k[i - p2->len]); // ��������� �������� �� "����������" �����������
			P* tmp = MUL_Pxk_P(temp, (i - p2->len)); // ���������� � ����������� �������
			freeP(temp);
			temp = SUB_PP_P(part, tmp); // �������� �� ������� ����� ��������, ���������� �� ��������
			freeP(tmp);
			freeP(part);
			part = temp;
		}
		freeP(part);
	}	
	return result;
}
// P-10
P* MOD_PP_P(P* p1, P* p2)
{
	P* result = DIV_PP_P(p1, p2); // ��������� ������� �������� ���������� �� ������� ��� �������
	P* temp = MUL_PP_P(result, p2); // ������������ ���������� �� ������� � �������� ����������
	freeP(result);
	result = SUB_PP_P(p1, temp); // �������� �������� ���������� � ������������
	freeP(temp);
	return result;
}
// P-11
P* GCF_PP_P(P* p1, P* p2)
{
	P *result, *temp;
	P* first = assignmentP(p1);
	P* second = assignmentP(p2);
	while ((second->len != 0 || NZER_N_B(second->k[0]->num->number)) && (first->len != 0 || NZER_N_B(first->k[0]->num->number))) // ���� ���� ��� ���������� - �� �������
	{
		if (first->len > second->len) // ���� ������� ������� ���������� ������ ������� �������
		{
			temp = MOD_PP_P(first, second); // ����������� ��� ������� �� ������� �����������
			freeP(first);
			first = temp;
		}
		else
		{
			temp = MOD_PP_P(second, first);
			freeP(second);
			second = temp;
		}
	}
	if (first->len > second->len) // ���� ������� ������� ���������� ��������� ������ �������
	{
		result = first; // ����������� ���������� (�������) �������� ������� ����������
		freeP(second);
	}
	else
	{
		result = second; // ��������
		freeP(first);
	}
	return result;
}
// P-12
P* DER_P_P(P* p)
{
	P* result = (P*)malloc(sizeof(P));
	result->k = (Q**)malloc(p->len * sizeof(Q*));
	result->len = p->len - 1;
	for (int i = p->len - 1; i >= 0; i--) // ���� �� �������� ������������ ����������
	{
		N* iton = intToN(i + 1);
		Z* temp = TRANS_N_Z(iton);
		freeN(iton);
		Q* tmp = TRANS_Z_Q(temp);
		result->k[i] = MUL_QQ_Q(p->k[i + 1], tmp); // ����������� �������� ������������ �������� 
		freeZ(temp);
		freeQ(tmp);
	}
	return result;
}
// P-13
P* NMR_P_P(P* p)
{
	P* result = DER_P_P(p); // �������������� ��������� ����������� �� ��������� ����������
	P* temp = GCF_PP_P(p, result); // ����������� ���������� �������� ���� ��������� ���������� � ����������
	freeP(result);
	result = DIV_PP_P(p, temp); // ������� �� ������� �����������  
	freeP(temp);
	Q* q = zeroQ();
	q->num->number->n[0] = 1;
	Q* tmp = FAC_P_Q(result);
	Q* tmpr = DIV_QQ_Q(q, tmp);
	temp = result;
	result = MUL_PQ_P(temp, tmpr); // ����������� ���������� �������� ������������
	freeQ(tmp);
	freeQ(tmpr);
	freeP(temp);
	freeQ(q);
	return result;
}
