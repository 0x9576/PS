#include<iostream>
using namespace std;
bool f[101][101];
bool v[101];
int N, M, a, b, ans;

void dfs(int c) {
	v[c] = true;
	for (int i = 0; i < 101; i++)
		if (f[c][i] && !v[i])
			dfs(i);
	return;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		f[a][b] = true;
		f[b][a] = true;
	}
	dfs(1);
	for (int i = 0; i < 101; i++) {
		if (v[i])
			ans++;
	}
	cout << ans - 1;
}