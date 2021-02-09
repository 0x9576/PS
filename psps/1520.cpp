#include<iostream>
using namespace std;
int f[510][510], N, M, m[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, m1, m2, dp[510][510];

int dfs(int a, int b) {
	if (dp[a][b]==-1) {
		dp[a][b] = 0;
		for (int i = 0; i < 4; i++) {
			m1 = a + m[i][0];
			m2 = b + m[i][1];
			if (f[a][b] < f[m1][m2]) {
				dp[a][b] += dfs(m1, m2);
			}
		}
	}
	return dp[a][b];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < 510; i++)
		for (int j = 0; j < 510; j++) {
			f[i][j] = 99999;
			dp[i][j] = -1;
		}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", f[i] + j);
	dp[1][1] = 1;
	cout << dfs(N,M);
}