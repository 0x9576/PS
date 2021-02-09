#include<iostream>
using namespace std;
#define DV 1000000000
long long dp[101][10], N, ans;
int main() {
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
			else
				dp[i][j] = dp[i - 1][j -1]+dp[i-1][j+1];
			dp[i][j] %= DV;
		}
	}
	cin >> N;
	for (int i = 1; i < 10; i++) {
		ans += dp[N][i];
		ans %= DV;
	}
	cout << ans;
}