#include<iostream>
using namespace std;

int save[100001];
int ans;
int dp[100001];

int main() {
	for (int i = 0; i < 100001; i++) {
		save[i] = -1001;
	}

	int n;
	int l;
	int r;
	int enter;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> save[i];
	}

	dp[0] = save[0];
	ans = save[0];

	for (int i = 1; i < n; i++) {
		l = dp[i - 1] + save[i];
		r = save[i];
		if (l >= r)
			enter = l;
		else
			enter = r;

		dp[i] = enter;
		if (enter > ans)
			ans = enter;
	}

	cout << ans;

	return 0;
}