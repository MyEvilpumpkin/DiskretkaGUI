#include "StringToPConverter.h"

using namespace std;

struct Part {
	Q* coef;
	int power;
};

void StringToPConverter::Convert(string str) {
	PRecognizer recognizer(str);
	status = recognizer.GetStatus();
	if (status) {
		p = (P*)malloc(sizeof(P));
		Part* parts = nullptr;
		string tempStr = recognizer.GetPreparedString();
		int pos = 0;
		bool isEnd = false;
		int maxPower = -1;
		int numOfParts = 0;
		do {
			int power = 0;
			bool isX = false;
			bool isDenom = false;
			Q* q = (Q*)malloc(sizeof(Q));
			q->num = (Z*)malloc(sizeof(Z));
			q->num->sign = tempStr[pos] == '+';
			q->num->number = (N*)malloc(sizeof(N));
			q->num->number->len = 0;
			q->num->number->n = nullptr;
			q->denom = (N*)malloc(sizeof(N));
			q->denom->len = 0;
			q->denom->n = nullptr;
			while (tempStr[pos + 1] != '+' && tempStr[pos + 1] != '-' && tempStr[pos + 1] != '\0') {
				if (tempStr[pos + 1] == 'x')
					isX = true;
				if (tempStr[pos + 1] == '/')
					isDenom = true;
				if (tempStr[pos + 1] >= '0' && tempStr[pos + 1] <= '9')
					if (isX)
						power = power * 10 + tempStr[pos + 1] - '0';
					else
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
			if (tempStr[pos + 1] == '\0')
				isEnd = true;
			else
				pos++;
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
			if (isX && !power)
				power = 1;
			if (power > maxPower)
				maxPower = power;
			parts = (Part*)realloc(parts, (numOfParts + 1) * sizeof(Part));
			parts[numOfParts].coef = q;
			parts[numOfParts++].power = power;
		} while (!isEnd);
		p->k = (Q**)malloc((maxPower + 1) * sizeof(Q*));
		p->len = maxPower;
		for (int i = 0; i <= maxPower; i++)
			p->k[i] = zeroQ();
		for (int i = 0; i < numOfParts; i++) {
			Q* temp = ADD_QQ_Q(p->k[parts[i].power], parts[i].coef);
			freeQ(p->k[parts[i].power]);
			freeQ(parts[i].coef);
			p->k[parts[i].power] = temp;
		}
		deNullP(p);
		free(parts);
	}
}
