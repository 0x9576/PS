#include<iostream>
#include<algorithm>
using namespace std;
int f[520][520], ans;

void dfs(int i, int j, int co, int ind, int a, int b) {
	if (co == 0) {
		ans = max(ans, f[i][j] + f[i + 1][j] + f[i + 2][j] + f[i + 1][j + 1]);
		ans = max(ans, f[i][j] + f[i][j-1] + f[i][j-2] + f[i-1][j-1]);
		ans = max(ans, f[i][j] + f[i-1][j] + f[i-2][j] + f[i-1][j-1]);
		ans = max(ans, f[i][j] + f[i][j+1] + f[i][j+2] + f[i + 1][j + 1]);
	}
	if (co == 4) {
		ans = max(ans, ind);
		return;
	}
	if (a != i + 1 || b != j)
		dfs(i + 1, j, co + 1, ind + f[i][j], i, j);
	if (a != i - 1 || b != j)
		dfs(i - 1, j, co + 1, ind + f[i][j], i, j);
	if (a != i || b != j + 1)
		dfs(i, j + 1, co + 1, ind + f[i][j], i, j);
	if (a != i || b != j - 1)
		dfs(i, j - 1, co + 1, ind + f[i][j], i, j);
}

int main() {
	int N, M;
	cin >> N >> M;
	ans = 0;
	for (int i = 4; i < N + 4; i++)
		for (int j = 4; j < M + 4; j++)
			cin >> f[i][j];
	for (int i = 4; i < N + 5; i++)
		for (int j = 4; j < M + 5; j++)
			dfs(i, j, 0, 0, i, j);
	cout << ans;
	return 0;
}