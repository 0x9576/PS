#include<iostream>
#include<algorithm>
#define INF 901000000
using namespace std;
int N, M, X,a,b,c,dp[1005][1005],ans;
int main() {
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 1005; j++) {
			if(i!=j)
				dp[i][j] = INF;
		}

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		dp[a][b] = c;
	}
	for(int i = 1; i<=N; i++)
		for(int j = 1; j<=N; j++)
			for (int k = 1; k <= N; k++) {
				if (dp[j][i] + dp[i][k] < dp[j][k])
					dp[j][k] = dp[j][i] + dp[i][k];
			}
	for (int i = 1; i <= N; i++)
		ans = max(ans, dp[i][X] + dp[X][i]);
	cout << ans;
}