#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000001];

int main() {
	for (int i = 0; i < 1000001; i++)
		dp[i] = 1000001;

	int n;
	cin >> n;

	dp[n] = 0;

	for (int i = n; i > 0; i--) {
		if (i % 3 == 0) {
			dp[i / 3] = min(dp[i / 3], dp[i] + 1);
		}
		if (i % 2 == 0) {
			dp[i / 2] = min(dp[i / 2], dp[i] + 1);
		}
		dp[i - 1] = min(dp[i-1], dp[i] + 1);
	}
	
	cout << dp[1];
}