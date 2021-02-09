#include<iostream>
using namespace std;
long long dp[10005];

int main() {
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	int n;
	cin >> n;

	for (int i = 3; i < 10005; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];
}