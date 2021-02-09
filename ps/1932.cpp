#include<iostream>
#include<algorithm>
using namespace std;
int e[505][505];
int dp[505][505];
int main() {
	int n;
	int m = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> e[i][j];
	for(int i = 1; i<=n; i++)
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j-1],dp[i-1][j]) + e[i][j];
			m = max(dp[i][j], m);
		}
	cout << m;
}