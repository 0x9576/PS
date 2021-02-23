#include<iostream>
#include<algorithm>
using namespace std;
int N, f[505][505], dp[505][505], p[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, ans, r,d;

int dfs(int a, int b) {
	if (dp[a][b])
		return dp[a][b];
	r++;
	dp[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = a + p[i][0], nc = b + p[i][1];
		if (f[a][b] < f[nr][nc])
			dp[a][b] = max(dp[a][b], dfs(nr, nc)+1);
	}
	return dp[a][b];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", f[i] + j);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dfs(i, j);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ans = max(dp[i][j], ans);
	cout << ans;
}