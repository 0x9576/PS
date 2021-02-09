#include<iostream>
using namespace std;
int dp[1005] = { 0,1,2, }, N;
int main() {
	for (int i = 3; i < 1005; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	cin >> N;
	cout << dp[N];
}