#include <iostream>
#include<algorithm>
using namespace std;

int p[1001];
int dp[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);
	dp[0] = p[0];
	int sum = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + p[i];
		sum += dp[i];
	}

	cout << sum;
}