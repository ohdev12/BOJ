#include <iostream>
#include <vector>

using namespace std;

int eachTime[1001];
int totalTime[1001];
vector<int> subBdgs[1001];

void find(int target) {
	int size = subBdgs[target].size();
	if (size == 0) {
		totalTime[target] = eachTime[target];
		return;
	}
	int max, curTarget;
	curTarget = subBdgs[target].at(0);
	if(totalTime[curTarget]==-1) find(curTarget);
	max = totalTime[curTarget];
	for (int i = 1; i < size; i++) {
		curTarget = subBdgs[target].at(i);
		if (totalTime[curTarget] == -1) find(curTarget);
		if (max < totalTime[curTarget]) max = totalTime[curTarget];
	}
	totalTime[target] = eachTime[target] + max;
}

int main(void) {
	int caseN;
	int bdgN, ruleN;
	int target;
	scanf("%d", &caseN);
	while (caseN--) {
		for (int i = 1; i <= 1000; i++) totalTime[i] = -1;
		scanf("%d %d", &bdgN, &ruleN);
		for (int i = 1; i <= bdgN; i++) scanf("%d", &eachTime[i]);
		int b1, b2;
		for (int i = 0; i < ruleN; i++) {
			scanf("%d %d", &b1, &b2);
			subBdgs[b2].push_back(b1);
		}
		scanf("%d", &target);
		find(target);
		printf("%d\n", totalTime[target]);
		for (int i = 1; i <= bdgN; i++) subBdgs[i].clear();
	}
	return 0;
}