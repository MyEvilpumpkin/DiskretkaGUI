#pragma once
#include <string>
#include "QRecognizer.h"
#include "Q_modules.h"


class StringToQConverter {
	bool status;
	Q* q;
	void Convert(std::string);
public:
	StringToQConverter(std::string str) : status(false), q(nullptr) { Convert(str); }
	~StringToQConverter() { if (q != nullptr) freeQ(q); }
	void Update(std::string str) { if (q != nullptr) freeQ(q); status = false; q = nullptr; Convert(str); }
	bool GetStatus() { return status; }
	Q* GetQ() { return q; }
};
