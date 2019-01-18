#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF (1<<29);

using namespace std;

// cards -> ����ī��, rsum -> 0~i ������ ��
int cards[1001], rsum[1001];
int dp[1001][1001];

// left ~ right ������ ī�尡 �־��� �� ���� �� �ִ� �ִ� ����
int playing(int left, int right)
{
	if (left == right) return cards[left];
	int& ret = dp[left][right];
	if (ret) return ret;
	// ������ ��� ����
	int enemy = min(playing(left + 1, right), playing(left, right - 1));
	// �ڽ��� ��� ����
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
		// rsum�� ���
		for (int i = 1; i <= n; i++) rsum[i] = rsum[i - 1] + cards[i];
		printf("%d\n", playing(1, n));
	}
}
*/