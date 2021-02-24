#include<iostream>
#include<algorithm>
#include<queue>
#define M 105
using namespace std;
int sn, N, o[M][M], f[M][M], p[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }, v[M][M], ans = 9999,bfs;
queue<pair<int, int>> q;

void dfs(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int nr = a + p[i][0];
		int nc = b + p[i][1];
		if (!f[nr][nc] && o[nr][nc]) {
			f[nr][nc] = sn;
			dfs(nr, nc);
		}
	}
}

int main() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			f[i][j] = -1;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", o[i] + j);
			f[i][j] = 0;
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (o[i][j] && !f[i][j]) {
				f[i][j] = ++sn;
				dfs(i, j);
			}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (f[i][j] && (!f[i + 1][j] || !f[i - 1][j] || !f[i][j + 1] || !f[i][j - 1])) {
				int tem = f[i][j];
				v[i][j] = 0;
				q.push({ i, j });
				while (!q.empty()) {
					int q1 = q.front().first;
					int q2 = q.front().second;
					q.pop();
					if (f[q1][q2] > 0 && f[q1][q2] != tem) {
						ans = min(ans, v[q1][q2]-1);
						break;
					}
					for (int i = 0; i < 4; i++) {
						int n1 = q1 + p[i][0];
						int n2 = q2 + p[i][1];
						if ((!v[n1][n2]||v[n1][n2] > v[q1][q2] + 1) && f[n1][n2] != -1 &&f[n1][n2] != tem) {
							v[n1][n2] = v[q1][q2] + 1;
							q.push({ n1,n2 });
						}
					}
					bfs++;
				}
				while (!q.empty())
					q.pop();
			}
		}
	cout << ans;
}