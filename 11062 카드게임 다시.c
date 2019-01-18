#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main(void) {
	int* deck;
	int caseN, cardN, curcardN;
	int i, j;
	int kw, mw;
	int front, back;
	int maxF, maxB;
	scanf("%d", &caseN);
	for (i = 0; i<caseN; i++) {
		kw = mw = 0;
		scanf("%d", &cardN);
		deck = (int*)malloc(sizeof(int)*cardN);
		for (j = 0; j<cardN; j++) {
			scanf("%d", &deck[j]);
		}
		curcardN = cardN;
		front = 0;
		back = cardN - 1;
		while (curcardN > 2) {
			//±Ù¿ìÂ÷·Ê deck[front], deck[back]
			maxF = MAX(deck[front + 1], deck[back]);
			maxB = MAX(deck[front], deck[back - 1]);
			if (maxF > maxB) {
				if (maxF - maxB > deck[front] - deck[back]) kw += deck[back--];
				else kw += deck[front++];
			}
			else if (maxF < maxB) {
				if (maxB - maxF > deck[back] - deck[front]) kw += deck[front++];
				else kw += deck[back--];
			}
			else {
				if (deck[back] > deck[front]) kw += deck[back--];
				else kw += deck[front++];
			}
			//¸í¿ìÂ÷·Ê
			maxF = MAX(deck[front + 1], deck[back]);
			maxB = MAX(deck[front], deck[back - 1]);
			if (maxF > maxB) {
				if (maxF - maxB > deck[front] - deck[back]) mw += deck[back--];
				else mw += deck[front++];
			}
			else if (maxF < maxB) {
				if (maxB - maxF > deck[back] - deck[front]) mw += deck[front++];
				else mw += deck[back--];
			}
			else {
				if (deck[back] > deck[front]) mw += deck[back--];
				else mw += deck[front++];
			}
			curcardN -= 2;
		}
		switch (curcardN) {
		case 1:
			kw += deck[front];
			break;
		case 2:
			if (deck[front] > deck[back]) {
				kw += deck[front];
				mw += deck[back];
			}
			else {
				kw += deck[back];
				mw += deck[front];
			}
			break;
		}
		printf("%d\n", kw);
		free(deck);
	}
	return 0;
}
