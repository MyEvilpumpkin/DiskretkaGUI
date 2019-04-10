#pragma once
#include <iostream>

// ����������� ���� _byte
typedef char _byte;

// �������� ������������ �����
struct N
{
	_byte *n;         // ��������� �� ������� ������ �����
	unsigned int len; // ���������� �������� � �����
};

int getNumber(); // ���� ��������������� ����� int
N* deNullN(N*);  // �������� ������ ����� � ������ �����
N* intToN(int);  // ������� �� int � N
int NToInt(N*);  // ������� �� int � N

N* zeroN();         // ������������� � ����������
N* assignmentN(N*); // ������������
std::string getString(N*); // �������������� � ������
N* freeN(N*);       // ������������ ������

int COM_NN_D(N*, N*);          // N-1
bool NZER_N_B(N*);             // N-2
N* ADD_1N_N(N*);               // N-3
N* ADD_NN_N(N*, N*);           // N-4
N* SUB_NN_N(N*, N*);           // N-5
N* MUL_ND_N(N*, int);          // N-6
N* MUL_Nk_N(N*, unsigned int); // N-7
N* MUL_NN_N(N*, N*);           // N-8
N* SUB_NDN_N(N*, int, N*);     // N-9
int DIV_NN_Dk(N*, N*, int&);   // N-10
N* DIV_NN_N(N*, N*);           // N-11
N* MOD_NN_N(N*, N*);           // N-12
N* GCF_NN_N(N*, N*);           // N-13
N* LCM_NN_N(N*, N*);           // N-14
