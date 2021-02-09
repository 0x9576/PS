#include<iostream>
#include<algorithm>
using namespace std;
char e1[1002], e2[1002];
int dp[1005][1005], i, j;
int main() {
	scanf("%s %s", e1 + 1, e2 + 1);
	for (i = 1; e1[i]; i++)
		for (j = 1; e2[j]; j++) {
			dp[i][j] = max({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (e1[i] == e2[j]) });
		}
	cout << dp[i - 1][j - 1];
}