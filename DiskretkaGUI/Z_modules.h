#pragma once
#include "N_modules.h"

// �������� ������ �����
struct Z
{
	N *number; // ����������� �����
	bool sign; // ���� ����� (0 - �������������)
};

Z* inputZ();        // ����
Z* zeroZ();         // ������������� � ����������
Z* assignmentZ(Z*); // ������������
void printZ(Z*);    // �����
Z* freeZ(Z*);       // ������������ ������

N* ABS_Z_N(Z*);      // Z-1
int POZ_Z_D(Z*);     // Z-2
Z* MUL_ZM_Z(Z*);     // Z-3
Z *TRANS_N_Z(N*);    // Z-4
N *TRANS_Z_N(Z*);    // Z-5
Z *ADD_ZZ_Z(Z*, Z*); // Z-6
Z *SUB_ZZ_Z(Z*, Z*); // Z-7
Z *MUL_ZZ_Z(Z*, Z*); // Z-8
Z* DIV_ZN_Z(Z*, N*); // Z-9
Z* MOD_ZN_Z(Z*, N*); // Z-10
