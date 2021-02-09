#include<iostream>
using namespace std;
long long dp[92];
int main() {
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 90; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int n;
	cin >> n;
	cout << dp[n];
}