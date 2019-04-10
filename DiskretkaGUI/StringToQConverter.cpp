#include "StringToQConverter.h"

using namespace std;

void StringToQConverter::Convert(string str) {
	QRecognizer recognizer(str);
	status = recognizer.GetStatus();
	if (status) {
		string tempStr = recognizer.GetPreparedString();
		int pos = 0;
		bool isDenom = false;
		q = (Q*)malloc(sizeof(Q));
		q->num = (Z*)malloc(sizeof(Z));
		q->num->sign = tempStr[pos] == '+';
		q->num->number = (N*)malloc(sizeof(N));
		q->num->number->len = 0;
		q->num->number->n = nullptr;
		q->denom = (N*)malloc(sizeof(N));
		q->denom->len = 0;
		q->denom->n = nullptr;
		while (tempStr[pos + 1] != '\0') {
			if (tempStr[pos + 1] == '/')
				isDenom = true;
			if (tempStr[pos + 1] >= '0' && tempStr[pos + 1] <= '9')
				if (isDenom) {
					q->denom->n = (_byte*)realloc(q->denom->n, (q->denom->len + 1) * sizeof(_byte));
					q->denom->n[q->denom->len++] = tempStr[pos + 1] - '0';
				}
				else {
					q->num->number->n = (_byte*)realloc(q->num->number->n, (q->num->number->len + 1) * sizeof(_byte));
					q->num->number->n[q->num->number->len++] = tempStr[pos + 1] - '0';
				}
			pos++;
		}
		if (!q->denom->len) {
			q->denom->n = (_byte*)malloc(sizeof(_byte));
			q->denom->n[0] = 1;
			q->denom->len++;
		}
		else {
			for (int i = 0; i < (q->denom->len / 2); i++) {
				_byte temp = q->denom->n[i];
				q->denom->n[i] = q->denom->n[q->denom->len - 1 - i];
				q->denom->n[q->denom->len - 1 - i] = temp;
			}
		}
		if (!q->num->number->len) {
			q->num->number->n = (_byte*)malloc(sizeof(_byte));
			q->num->number->n[0] = 1;
			q->num->number->len++;
		}
		else {
			for (int i = 0; i < (q->num->number->len / 2); i++) {
				_byte temp = q->num->number->n[i];
				q->num->number->n[i] = q->num->number->n[q->num->number->len - 1 - i];
				q->num->number->n[q->num->number->len - 1 - i] = temp;
			}
		}
		RED_Q_Q(q);
	}
}
