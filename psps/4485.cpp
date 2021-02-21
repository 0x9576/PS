#include<iostream>
#include<algorithm>
#include<queue>
#define INF 99999
using namespace std;
int N, f[130][130], v[130][130], p[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, ans,pb;
queue < pair<int, int>> q;

int main() {
	while (1) {
		pb++;
		ans = INF;
		cin >> N;
		if (!N)
			break;
		for (int i = 0; i < 130; i++)
			for (int j = 0; j < 130; j++) {
				f[i][j] = -1;
				v[i][j] = INF;
			}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", f[i] + j);
		v[1][1] = f[1][1];
		q.push({ 1,1 });
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			if (a == N && b == N) {
				ans = min(ans, v[N][N]);
			}
			for (int i = 0; i < 4; i++)
				if (v[a + p[i][0]][b + p[i][1]] > v[a][b] + f[a + p[i][0]][b + p[i][1]] && f[a + p[i][0]][b + p[i][1]] != -1) {
					v[a + p[i][0]][b + p[i][1]] = v[a][b] + f[a + p[i][0]][b + p[i][1]];
					q.push({ a + p[i][0], b + p[i][1] });
				}
		}
		printf("Problem %d: %d\n", pb, ans);
	}
}