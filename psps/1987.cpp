#include<iostream>
#include<algorithm>
using namespace std;
char f[25][25];
bool v[25][25], d[200];
int ans;

void dfs(int a, int b, int s) {
	ans = max(s, ans);
	v[a][b] = 1;
	d[f[a][b]] = 1;
	if (!d[f[a+1][b]] && !v[a + 1][b]) {
		dfs(a + 1, b, s + 1);
		d[f[a+1][b]] = 0;
		v[a + 1][b] = 0;
	}
	if (!d[f[a][b+1]] && !v[a][b + 1]) {
		dfs(a, b + 1, s + 1);
		d[f[a][b+1]] = 0;
		v[a][b + 1] = 0;
	}
	if (!d[f[a-1][b]] && !v[a - 1][b]) {
		dfs(a - 1, b, s + 1);
		d[f[a - 1][b]] = 0;
		v[a - 1][b] = 0;
	}
	if (!d[f[a][b - 1]] && !v[a][b - 1]) {
		dfs(a, b - 1, s + 1);
		d[f[a][b - 1]] = 0;
		v[a][b - 1] = 0;
	}
}

int main() {
	int R, C;
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> f[i][j];
	d[0] = 1;
	dfs(1, 1, 1);
	cout << ans;
}