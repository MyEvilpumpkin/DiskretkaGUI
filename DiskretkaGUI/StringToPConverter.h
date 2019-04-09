#pragma once
#include <string>
#include "PRecognizer.h"
#include "P_modules.h"


class StringToPConverter {
	bool status;
	P* p;
	void Convert(std::string);
public:
	StringToPConverter(std::string str) : status(false), p(nullptr) { Convert(str); }
	~StringToPConverter() { if (p != nullptr) freeP(p); }
	void Update(std::string str) { if (p != nullptr) freeP(p); status = false; p = nullptr; Convert(str); }
	bool GetStatus() { return status; }
	P* GetP() { return p; }
};
