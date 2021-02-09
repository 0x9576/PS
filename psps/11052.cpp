#include<iostream>
#include<algorithm>
using namespace std;
int N, c[10003], dp[10003];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> c[i];
	dp[1] = c[1];
	for (int i = 1; i <= N; i++) {
		dp[i] = c[i];
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i-j]+dp[j], dp[i]);
		}
	}
	cout << dp[N];
}