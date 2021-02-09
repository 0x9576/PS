#include<iostream>
using namespace std;
int dp[202][202];
int main() {
	int N, K;
	cin >> K >> N;
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= K; j++)
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 1000000000;
			}
	cout << dp[N][K];
}