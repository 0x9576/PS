#include<iostream>
using namespace std;
long dp[102][22], n[102], N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> n[i];
	dp[0][n[0]]++;
	for (int i = 1; i < N-1; i++)
		for (int j = 0; j < 21; j++) {
			if (j - n[i] >= 0)
				dp[i][j - n[i]] += dp[i - 1][j];
			if (j + n[i] <= 20)
				dp[i][j + n[i]] += dp[i - 1][j];
		}
	cout << dp[N - 2][n[N - 1]];
}