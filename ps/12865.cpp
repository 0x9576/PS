#include <iostream>
#include<queue>
using namespace std;
int p[101][2];
int vm = 0;
int dp[100002][102];

int main() {
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < 102; j++)
			dp[i][j] = -1;
	}

	int n, k, z, w, v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		p[i][0] = w;
		p[i][1] = v;
		if (w <= k) {
			dp[w][i] = v;
		}
	}

	int o;

	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j <= k; j++) {
			if (dp[j][i] != -1) {
				z = j + p[i + 1][0];
				if (z <= k) {
					o = dp[j][i] + p[i + 1][1];
					dp[z][i + 1] = o;
					if (o > vm)
						vm = o;
				}
				if (dp[j][i + 1] < dp[j][i]) {
					dp[j][i + 1] = dp[j][i];
					if (dp[j][i + 1] > vm)
						vm = dp[j][i + 1];
				}
			}
		}
	}

	cout << vm;

	return 0;
}