#pragma once
#include "SpecialType.h"
#include "Q.h"
#include <string>

// �������� ������������ �����
class P : public SpecialType {
	// ����
	Q* coefficients; // ��������� �� ����� ���������� ������������, ��������������� � ���� ������������� �����
	size_t power;    // ������� ����������
public:
	// ������������ � �����������
	P();                  // ����������� �� ���������
	P(const std::string); // ����������� �������������� std::string � P
	P(const P&);          // ����������� �����������
	P(P&&) noexcept;      // ����������� ����������� � ���������
	~P();                 // ���������� �� ���������

	// ���������� ����������
	P& operator = (const P&);     // ���������� ��������� ������������
	P& operator = (P&&) noexcept; // ���������� ��������� ������������ � ���������

	// ��������������� ������� �������� ������
	void SetZero() override;               // ��������� ����
	void SetOne() override;                // ��������� �������
	bool IsZero() const override;          // �������� �� ��������� � ����
	bool IsOne() const override;           // �������� �� ��������� � ��������
	std::string ToString() const override; // �������������� P � std::string
	void Normalize() override;             // ������������ �����

	// ������������� �������
	friend P ADD_PP_P(const P&, const P&);            // P-1
	friend P SUB_PP_P(const P&, const P&);            // P-2
	friend P MUL_PQ_P(const P&, const Q&);            // P-3
	friend P MUL_Pxk_P(const P&, const unsigned int); // P-4
	friend Q LED_P_Q(const P&);                       // P-5
	friend N DEG_P_N(const P&);                       // P-6
	friend Q FAC_P_Q(const P&);                       // P-7
	friend P MUL_PP_P(const P&, const P&);            // P-8
	friend P DIV_PP_P(const P&, const P&);            // P-9
	friend P MOD_PP_P(const P&, const P&);            // P-10
	friend P GCF_PP_P(const P&, const P&);            // P-11
	friend P DER_P_P(const P&);                       // P-12
	friend P NMR_P_P(const P&);                       // P-13
};

// ������
P ADD_PP_P(const P&, const P&);            // P-1
P SUB_PP_P(const P&, const P&);            // P-2
P MUL_PQ_P(const P&, const Q&);            // P-3
P MUL_Pxk_P(const P&, const unsigned int); // P-4
Q LED_P_Q(const P&);                       // P-5
N DEG_P_N(const P&);                       // P-6
Q FAC_P_Q(const P&);                       // P-7
P MUL_PP_P(const P&, const P&);            // P-8
P DIV_PP_P(const P&, const P&);            // P-9
P MOD_PP_P(const P&, const P&);            // P-10
P GCF_PP_P(const P&, const P&);            // P-11
P DER_P_P(const P&);                       // P-12
P NMR_P_P(const P&);                       // P-13

