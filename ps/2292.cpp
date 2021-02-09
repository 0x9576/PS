#include<iostream>
using namespace std;
int dp[100000], N;
int main() {
	dp[1] = 1;
	for (int i = 2; i < 100000; i++) {
		dp[i] = dp[i - 1] + 6 * (i - 1);
	}
	cin >> N;
	for (int i = 1; i < 100000; i++) {
		if (dp[i] >= N) {
			cout << i;
			exit(0);
		}
	}
}
