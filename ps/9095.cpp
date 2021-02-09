#include<iostream>
using namespace std;
int dp[12];
int ans[100001];

int main() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	int T;
	cin >> T;

	int n;

	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		ans[i] = dp[n];
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}