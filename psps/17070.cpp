#include<iostream>
using namespace std;
int r[20][20], N, ans, v[20][20];

void dfs(int i, int j) {
	if (i == N && j == N) {
		ans++;
		return;
	}
	if (!r[i + 1][j] && v[i][j] != 3) {
		v[i + 1][j] = 2;
		dfs(i + 1, j);
		v[i + 1][j] = 0;
	}

	if (!r[i][j + 1] && v[i][j] != 2) {
		v[i][j + 1] = 3;
		dfs(i, j + 1);
		v[i][j] = 0;
	}
	if (!r[i][j + 1] && !r[i + 1][j] && !r[i + 1][j + 1]) {
		v[i + 1][j + 1] = 4;
		dfs(i + 1, j + 1);
		v[i + 1][j + 1] = 0;
	}

}

int main() {
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			r[i][j] = 1;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> r[i][j];
	r[1][1] = 1;
	r[1][2] = 1;
	v[1][2] = 3;
	dfs(1, 2);
	cout << ans;
}
