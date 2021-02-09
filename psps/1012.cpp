#include<iostream>
using namespace std;
bool f[51][51];//original
bool c[51][51];//for check
int T, M, N, K, x, y;
int ans[1000001];

void dfs(int i, int j) {
	if (f[i][j] && !c[i][j]) {
		c[i][j] = true;
		if (i < M) dfs(i + 1, j);
		if (j < N) dfs(i, j+1);
		if(i>0) dfs(i-1,j);
		if(j>0) dfs(i, j - 1);
	}
}

int main() {
	cin >> T;
	for (int a = 0; a < T; a++) {
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				f[i][j] = false;
				c[i][j] = false;
			}
		}
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			f[x][y] = true;
		}

		int cou = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (f[i][j] && !c[i][j]) {
					dfs(i, j);
					cou++;
				}
			}
		}
		ans[a] = cou;
	}

	for (int i = 0; i < T; i++)
		cout << ans[i] << endl;

	return 0;
}
