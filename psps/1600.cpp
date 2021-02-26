#include<iostream>
#include<algorithm>
#include<queue>
#define M 250
#define INF 9999999
using namespace std;
int K, W, H, f[M][M], h[8][2] = { {-1,-2},{-2,-1},{-1,2},{-2,1},{1,-2},{2,-1},{1,2},{2,1} },
v[M][M][34], m[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, ans = INF;
queue < pair<int, pair<int, int>>> q;
int main() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			for (int k = 0; k < 34; k++) {
				f[i][j] = 1;
				v[i][j][k] = INF;
			}

	cin >> K >> W >> H;
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= W; j++)
			scanf("%d", f[i] + j);
	q.push({ K,{1,1} });
	v[1][1][K] = 1;
	while (!q.empty()) {
		int k = q.front().first;
		int a = q.front().second.first;
		int b = q.front().second.second;
		q.pop();
		if (k)
			for (int i = 0; i < 8; i++) {
				int na = a + h[i][0];
				int nb = b + h[i][1];
				if (na > 0 && nb > 0 && !f[na][nb] && (v[a][b][k] + 1 < v[na][nb][k - 1])) {
					v[na][nb][k - 1] = v[a][b][k] + 1;
					q.push({ k - 1,{na,nb} });
				}
			}
		for (int i = 0; i < 4; i++) {
			int na = a + m[i][0];
			int nb = b + m[i][1];
			if (na > 0 && nb > 0 && !f[na][nb] && (v[a][b][k] + 1 < v[na][nb][k])) {
				v[na][nb][k] = v[a][b][k] + 1;
				q.push({ k,{na,nb} });
			}
		}
	}
	for (int i = 0; i <= K; i++)
		ans = min(ans, v[H][W][i]);
	if (ans == INF)
		cout << "-1" << endl;
	else
		cout << ans - 1;
}