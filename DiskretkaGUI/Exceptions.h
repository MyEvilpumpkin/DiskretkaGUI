#pragma once
#include <exception>

class IncorrectString : public std::exception {
public:
	IncorrectString() : std::exception("������: ������� ������������ ������") { }
};

class ArithmeticalError : public std::exception {
public:
	ArithmeticalError(const char* str) : std::exception(str) { }
};

class SubtractionError : public ArithmeticalError {
public:
	SubtractionError() : ArithmeticalError("������: ������� ��������� �������� ������������ ����� �� ��������") { }
};

class DivisionByZero : public ArithmeticalError {
public:
	DivisionByZero() : ArithmeticalError("������: ������� ������� �� 0") { }
};

class DivisionByMore : public ArithmeticalError {
public:
	DivisionByMore() : ArithmeticalError("������: ������� ������� �������� ������ (�� ������) �� ������� �����������") { }
};

class NotADigit : public ArithmeticalError {
public:
	NotADigit() : ArithmeticalError("������: ������� ��������� �� �����, � �� �� �����") { }
};

class Error : public std::exception {
public:
	Error(const char* str) : std::exception(str) { }
};

