#pragma once
#include <string>
#include "ZRecognizer.h"
#include "Z_modules.h"


class StringToZConverter {
	bool status;
	Z* z;
	void Convert(std::string);
public:
	StringToZConverter(std::string str) : status(false), z(nullptr) { Convert(str); }
	~StringToZConverter() { if (z != nullptr) freeZ(z); }
	void Update(std::string str) { if (z != nullptr) freeZ(z); status = false; z = nullptr; Convert(str); }
	bool GetStatus() { return status; }
	Z* GetZ() { return z; }
};
