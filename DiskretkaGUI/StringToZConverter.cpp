#include "StringToZConverter.h"

using namespace std;

void StringToZConverter::Convert(string str) {
	ZRecognizer recognizer(str);
	status = recognizer.GetStatus();
	if (status) {
		string tempStr = recognizer.GetPreparedString();
		int pos = 0;
		z = (Z*)malloc(sizeof(Z));
		z->sign = tempStr[pos] == '+';
		z->number = (N*)malloc(sizeof(N));
		z->number->len = 0;
		z->number->n = nullptr;
		while (tempStr[pos + 1] != '\0') {
			z->number->n = (_byte*)realloc(z->number->n, (z->number->len + 1) * sizeof(_byte));
			z->number->n[z->number->len++] = tempStr[pos + 1] - '0';
			pos++;
		}
		if (!z->number->len) {
			z->number->n = (_byte*)malloc(sizeof(_byte));
			z->number->n[0] = 1;
			z->number->len++;
		}
		else {
			for (int i = 0; i < (z->number->len / 2); i++) {
				_byte temp = z->number->n[i];
				z->number->n[i] = z->number->n[z->number->len - 1 - i];
				z->number->n[z->number->len - 1 - i] = temp;
			}
		}
	}
}
