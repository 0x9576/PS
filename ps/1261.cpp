#include<iostream>
using namespace std;
int f[105][105], v[105][105], N, M;

void dfs(int a, int b) {
	if (f[a+1][b] != -1 && v[a][b] + f[a + 1][b]<v[a+1][b]) {
		v[a + 1][b] = v[a][b] + f[a + 1][b];
		dfs(a + 1, b);
	}
	if (f[a - 1][b] != -1 && v[a][b] + f[a - 1][b] < v[a - 1][b]) {
		v[a - 1][b] = v[a][b] + f[a - 1][b];
		dfs(a - 1, b);
	}
	if (f[a][b+1] != -1 && v[a][b] + f[a][b+1] < v[a][b+1]) {
		v[a][b+1] = v[a][b] + f[a][b+1];
		dfs(a, b+1);
	}
	if (f[a][b-1] != -1 && v[a][b] + f[a][b-1] < v[a][b-1]) {
		v[a][b-1] = v[a][b] + f[a][b-1];
		dfs(a, b-1);
	}
}

int main() {
	for (int i = 0; i < 105; i++)
		for (int j = 0; j < 105; j++) {
			f[i][j] = -1;
			v[i][j] = 9999;
		}

	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%1d", f[i] + j);
	v[1][1] = 0;
	dfs(1, 1);
	cout << v[N][M];
}