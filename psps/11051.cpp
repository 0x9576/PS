#include<iostream>
using namespace std;
int dp[1005][1005];
int main() {
	dp[0][0] = 1;
	for (int i = 1; i < 1005; i++)
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] %= 10007;
		}
	int N, K;
	cin >> N >> K;
	cout << dp[N][K];
}
