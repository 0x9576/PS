#include<iostream>
#include<algorithm>
using namespace std;
int w[10003];
int dp[10003];
int main() {
	int n, fm;
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	dp[1] = w[1];
	dp[2] = w[1] + w[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 2],dp[i-3]+w[i-1]) + w[i],dp[i-1]);
	}
	cout << dp[n];
}