#pragma once
#include <string>
#include "NRecognizer.h"
#include "N_modules.h"

class StringToNConverter {
	bool status;
	N* n;
	void Convert(std::string);
public:
	StringToNConverter(std::string str) : status(false), n(nullptr) { Convert(str); }
	~StringToNConverter() { if (n != nullptr) freeN(n); }
	void Update(std::string str) { if (n != nullptr) freeN(n); status = false; n = nullptr; Convert(str); }
	bool GetStatus() { return status; }
	N* GetN() { return n; }
};
