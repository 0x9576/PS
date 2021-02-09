#include<iostream>
#include<algorithm>
using namespace std;
int e[1001], dp[1001], N, ans, tem;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> e[i];
	for (int i = 0; i < N; i++) {
		dp[e[i]] = e[i];
		tem = 0;
		for (int j = e[i]-1; j > 0; j--) {
			tem = max(tem, dp[j]);
		}
		dp[e[i]] += tem;
		ans = max(ans, dp[e[i]]);
	}
	cout << ans;
}