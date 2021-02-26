#include<iostream>
#include<algorithm>
using namespace std;
int e[512][2], dp[512][512],N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &e[i][0], &e[i][1]);
	for (int i = 1; i < N; i++)
		dp[i][i + 1] = e[i][0] * e[i][1] * e[i + 1][1];
	for (int g = 2; g < N; g++)
		for (int i = 1; i <= N - g; i++) {
			int j = i + g;
			for (int k = i; k <= j - 1; k++) {
				int tem = dp[i][k] + dp[k + 1][j] + e[i][0] * e[k][1] * e[j][1];
				if (!dp[i][j])
					dp[i][j] = tem;
				else
					dp[i][j] = min(dp[i][j], tem);
			}
		}
	cout << dp[1][N];
}