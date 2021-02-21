#include<iostream>
#include<queue>
#define INF 99999
using namespace std;
int N, f[130][130], v[130][130], p[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, pb;

int main() {
	while (1) {
		priority_queue <pair<int, pair<int, int>>> pq;
		pb++;
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
		pq.push({-f[1][1],{ 1,1 }});
		while (!pq.empty()) {
			int c = -pq.top().first;
			int a = pq.top().second.first;
			int b = pq.top().second.second;
			if (a == N && b == N)
				break;
			pq.pop();
			for (int i = 0; i < 4; i++)
				if (v[a + p[i][0]][b + p[i][1]] > c + f[a + p[i][0]][b + p[i][1]] && f[a + p[i][0]][b + p[i][1]] != -1) {
					v[a + p[i][0]][b + p[i][1]] = v[a][b] + f[a + p[i][0]][b + p[i][1]];
					pq.push({ -(c + f[a + p[i][0]][b + p[i][1]]) ,{ a + p[i][0], b + p[i][1] } });
				}
		}
		printf("Problem %d: %d\n", pb, v[N][N]);
	}
}