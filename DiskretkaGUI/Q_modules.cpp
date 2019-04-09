#include "Q_modules.h"

// ����
Q* inputQ()
{
	Q* q = (Q*)malloc(sizeof(Q));
	printf("������� ���������: ");
	q->num = inputZ();
	printf("������� �����������: ");
	bool error;
	do
	{
		error = false;
		q->denom = inputN();
		if (q->denom->len == 1 && q->denom->n[0] == 0)
		{
			error = true;
			freeN(q->denom);
			printf("������� ������������ ������. ������� ����������� > 0: ");
		}
	} while (error);
	return q;
}
// ������������� � ����������
Q* zeroQ()
{
	Q* q = (Q*)malloc(sizeof(Q));
	q->num = zeroZ();
	q->denom = zeroN();
	q->denom->n[0] = 1;
	return q;
}
// ������������
Q* assignmentQ(Q* q)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->num = assignmentZ(q->num);
	result->denom = assignmentN(q->denom);
	return result;
}
// �����
void printQ(Q* q)
{
	if (!q->num->sign)
		printf("- ");
	printN(q->num->number);
	if (q->denom->len != 1 || q->denom->n[0] != 1)
	{
		printf("/");
		printN(q->denom);
	}
}
// ������������ ������
Q* freeQ(Q* q)
{
	freeN(q->denom);
	freeZ(q->num);
	free(q);
	return q;
}

// Q-1
Q* RED_Q_Q(Q* q)
{
	N* d = GCF_NN_N(q->num->number, q->denom); // ����������� d �������� ���� (������ ��������� �����) � ����������� ����� 
	while (d->len != 1 || d->n[0] != 1) // �� ��� ��� ���� d �� ������ ������ 1  
	{
		N* temp = DIV_NN_N(q->num->number, d); // ��������� ��������� �� d
		freeN(q->num->number);
		q->num->number = temp;
		temp = DIV_NN_N(q->denom, d); // ��������� ����������� �� d
		freeN(q->denom);
		q->denom = temp;
		freeN(d);
		d = GCF_NN_N(q->num->number, q->denom); // ����������� d �������� ���� (������ ��������� �����) � ����������� �����  
	}
	freeN(d);
	return q;
}
// Q-2
bool INT_Q_B(Q* q)
{
	return (RED_Q_Q(q)->denom->len == 1 && RED_Q_Q(q)->denom->n[0] == 1); // ���������� ���������� ������������ � ���, ��� ����������� ����� = 1
}
// Q-3
Q* TRANS_Z_Q(Z* z)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->denom = zeroN();
	result->denom->n[0] = 1;
	result->num = assignmentZ(z); // ������������ ��������� ���������� �������� ������ �����
	return result;
}
// Q-4
Z* TRANS_Q_Z(Q* q)
{
	return assignmentZ(RED_Q_Q(q)->num); // ���������� �������� ��������� ����������� ����� 
}
// Q-5
Q* ADD_QQ_Q(Q* q1, Q* q2)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->denom = MUL_NN_N(q1->denom, q2->denom); // ������� ������������ � ���������� � �����������
	Z* z1 = (Z*)malloc(sizeof(Z));
	z1->number = MUL_NN_N(q1->num->number, q2->denom); // ����������� �������� ����������� q1 ������������ ��������� q1 � ����������� q2 
	z1->sign = q1->num->sign; // �������� ���� ��������� q1
	Z* z2 = (Z*)malloc(sizeof(Z));
	z2->number = MUL_NN_N(q2->num->number, q1->denom); // ����������� �������� ����������� q2 ������������ ��������� q2 � ����������� q1
	z2->sign = q2->num->sign; // �������� ���� ��������� q2
	result->num = ADD_ZZ_Z(z1, z2);
	freeZ(z1);
	freeZ(z2);
	return RED_Q_Q(result);
}
// Q-6
Q* SUB_QQ_Q(Q* q1, Q* q2)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->denom = MUL_NN_N(q1->denom, q2->denom); // ������� ������������ � ���������� � �����������
	Z* z1 = (Z*)malloc(sizeof(Z));
	z1->number = MUL_NN_N(q1->num->number, q2->denom); // ����������� �������� ����������� q1 ������������ ��������� q1 � ����������� q2 
	z1->sign = q1->num->sign; // �������� ���� ��������� q1
	Z* z2 = (Z*)malloc(sizeof(Z));
	z2->number = MUL_NN_N(q2->num->number, q1->denom); // ����������� �������� ����������� q2 ������������ ��������� q2 � ����������� q1
	z2->sign = q2->num->sign; // �������� ���� ��������� q2
	result->num = SUB_ZZ_Z(z1, z2);
	freeZ(z1);
	freeZ(z2);
	return RED_Q_Q(result);
}
// Q-7
Q* MUL_QQ_Q(Q* q1, Q* q2)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->denom = MUL_NN_N(q1->denom, q2->denom); // ����������� ���������
	result->num = MUL_ZZ_Z(q1->num, q2->num); // ����������� �����������
	return RED_Q_Q(result);
}
// Q-8
Q* DIV_QQ_Q(Q* q1, Q* q2)
{
	Q* result;
	if (!POZ_Z_D(q1->num) || !POZ_Z_D(q2->num)) // E��� ��������� = 0
		result = zeroQ();
	else
	{
		result = (Q*)malloc(sizeof(Q));
		result->num = (Z*)malloc(sizeof(Z));
		result->num->sign = q1->num->sign == q2->num->sign; // ��������� ����� ���������� ������������ ������ ���� ����������
		result->num->number = MUL_NN_N(q1->num->number, q2->denom); // ��������� ��������� ���������� ������������ ������� ��������� � ������� �����������
		result->denom = MUL_NN_N(q1->denom, q2->num->number); // ��������� ����������� ���������� ������������ ������� ����������� � ������� ���������
	}
	return RED_Q_Q(result);
}
