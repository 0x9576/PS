#include <iostream>
#include<algorithm>
using namespace std;
#define MAX 100003

int s[100003][2];
int dp[100003][2];
int ans[100002];

int main() {
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < MAX; k++)
				s[k][j] = 0;
		cin >> n;
		for (int j = 0; j < 2; j++)
			for (int k = 1; k <= n; k++) {
				cin >> s[k][j];
			}
		dp[1][0] = s[1][0];
		dp[1][1] = s[1][1];
		for (int j = 2; j <= n; j++) {
			dp[j][0] = max(dp[j - 1][1], dp[j - 2][1]) + s[j][0];
			dp[j][1] = max(dp[j - 1][0], dp[j - 2][0]) + s[j][1];
		}
		ans[i] = max(dp[n][0], dp[n][1]);
	}
	for (int i = 0; i < T; i++)
		cout << ans[i] << endl;
}