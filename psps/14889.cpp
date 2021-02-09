#include<iostream>
#include<algorithm>
using namespace std;
int t[21][21], N, sta, lin, ans = 99999;
bool st[21];

void sel(int a, int s) {
	st[a] = 1;
	if (s == N/2) {
		sta = 0;
		lin = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (st[i] && st[j])
					sta += t[i][j];
				if(!st[i] && !st[j])
					lin += t[i][j];
			}
		ans = min(ans, abs(sta - lin));
		return;
	}

	for (int i = a + 1; i < N; i++) {
		sel(i, s + 1);
		st[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> t[i][j];
	for (int i = 0; i < N; i++) {
		sel(i, 1);
		st[i] = 0;
	}

	cout << ans;
}