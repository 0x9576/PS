#include<iostream>
#include<algorithm>
using namespace std;
int d[20], p[20], dp[100];
int main() {
	int N, di;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> d[i] >> p[i];
	for (int i = 1; i <= N+1; i++) {
		for (int j = 1; j < i; j++)
			dp[i - 1] = max(dp[j], dp[i - 1]);
		di = i + d[i] - 1;
		dp[di] = max(dp[i - 1] + p[i],dp[di]);
	}
	cout << dp[N];
}