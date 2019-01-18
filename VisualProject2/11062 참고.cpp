#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF (1<<29);

using namespace std;

// cards -> 숫자카드, rsum -> 0~i 까지의 합
int cards[1001], rsum[1001];
int dp[1001][1001];

// left ~ right 사이의 카드가 주어질 때 얻을 수 있는 최대 점수
int playing(int left, int right)
{
	if (left == right) return cards[left];
	int& ret = dp[left][right];
	if (ret) return ret;
	// 상대방이 얻는 점수
	int enemy = min(playing(left + 1, right), playing(left, right - 1));
	// 자신이 얻는 점수
	ret = rsum[right] - rsum[left - 1] - enemy;
	return ret;
}
/*
int main()
{
	int c;
	scanf("%d", &c);
	while (c--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &cards[i]);
		memset(dp, 0, sizeof(dp));
		// rsum을 계산
		for (int i = 1; i <= n; i++) rsum[i] = rsum[i - 1] + cards[i];
		printf("%d\n", playing(1, n));
	}
}
*/