#pragma once
#include "Q_modules.h"

// �������� ����������
struct P
{
	Q **k;            // ��������� �� ����� ���������� ������������, ��������������� � ���� ������������� �����
	unsigned int len; // ������� ����������
};

P* deNullP(P*); // �������� ���������� ��������� �� �������� ��������������

P* inputP();        // ����
P* zeroP();         // ������������� � ����������
P* assignmentP(P*); // ������������
void printP(P*);    // �����
P* freeP(P*);       // ������������ ������

P* ADD_PP_P(P*, P*);   // P-1
P* SUB_PP_P(P*, P*);   // P-2
P* MUL_PQ_P(P*, Q*);   // P-3
P* MUL_Pxk_P(P*, int); // P-4
Q* LED_P_Q(P*);        // P-5
N* DEG_P_N(P*);        // P-6
Q* FAC_P_Q(P*);        // P-7
P* MUL_PP_P(P*, P*);   // P-8
P* DIV_PP_P(P*, P*);   // P-9
P* MOD_PP_P(P*, P*);   // P-10
P* GCF_PP_P(P*, P*);   // P-11
P* DER_P_P(P*);        // P-12
P* NMR_P_P(P*);        // P-13
