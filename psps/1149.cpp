#include<iostream>
#include<algorithm>
using namespace std;

int e[1002][3];
int dp[1002][3];

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> e[i][j];

	dp[1][0] = e[1][0];
	dp[1][1] = e[1][1];
	dp[1][2] = e[1][2];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1] + e[i][0], dp[i - 1][2] + e[i][0]);
		dp[i][1] = min(dp[i - 1][0] + e[i][1], dp[i - 1][2] + e[i][1]);
		dp[i][2] = min(dp[i - 1][0] + e[i][2], dp[i - 1][1] + e[i][2]);
	}
	int ans = min(min(dp[N][0], dp[N][1]),dp[N][2]);
	cout << ans;
}
