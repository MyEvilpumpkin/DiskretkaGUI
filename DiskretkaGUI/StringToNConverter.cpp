#include "StringToNConverter.h"

using namespace std;

void StringToNConverter::Convert(string str) {
	NRecognizer recognizer(str);
	status = recognizer.GetStatus();
	if (status) {
		string tempStr = recognizer.GetPreparedString();
		int pos = 0;
		n = (N*)malloc(sizeof(N));
		n->len = 0;
		n->n = nullptr;
		while (tempStr[pos] != '\0') {
			n->n = (_byte*)realloc(n->n, (n->len + 1) * sizeof(_byte));
			n->n[n->len++] = tempStr[pos] - '0';
			pos++;
		}
		if (!n->len) {
			n->n = (_byte*)malloc(sizeof(_byte));
			n->n[0] = 1;
			n->len++;
		}
		else {
			for (int i = 0; i < (n->len / 2); i++) {
				_byte temp = n->n[i];
				n->n[i] = n->n[n->len - 1 - i];
				n->n[n->len - 1 - i] = temp;
			}
		}
	}
}
