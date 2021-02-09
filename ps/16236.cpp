#include<iostream>
#include<queue>
using namespace std;
int f[25][25], v[25][25], spr, spc, N, r, c, shark, sha_ex, ans, tr, tc;
int main() {
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 25; j++)
			f[i][j] = 99;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> f[i][j];
			if (f[i][j] == 9) {
				spr = i;
				spc = j;
			}
		}
	shark = 2;
	queue <pair<int, int>> q;
	while (1) {
		q.push({ spr, spc });
		v[spr][spc] = 0;
		tr = 99; tc = 99;
		while (!q.empty()) {
			r = q.front().first;
			c = q.front().second;
			q.pop();
			if (f[r][c] && f[r][c] < shark) {
				if ((tr == 99 && tc == 99) || v[tr][tc] > v[r][c]) {
					tr = r; tc = c;
				}
				else if (v[tr][tc] == v[r][c]) {
					if (tr > r) {
						tr = r; tc = c;
					}
					else if (tr == r) {
						if (tc > c) {
							tr = r; tc = c;
						}
					}
				}
			}
			if (f[r - 1][c] <= shark && !v[r - 1][c]) {
				v[r - 1][c] = v[r][c] + 1;
				q.push({ r - 1 , c });
			}
			if (f[r][c - 1] <= shark && !v[r][c - 1]) {
				v[r][c - 1] = v[r][c] + 1;
				q.push({ r , c - 1 });
			}
			if (f[r + 1][c] <= shark && !v[r + 1][c]) {
				v[r + 1][c] = v[r][c] + 1;
				q.push({ r + 1 , c });
			}
			if (f[r][c + 1] <= shark && !v[r][c + 1]) {
				v[r][c + 1] = v[r][c] + 1;
				q.push({ r , c + 1 });
			}
		}
		r = tr;
		c = tc;
		if (!f[r][c] || shark < f[r][c] || (tr==99&&tc==99)) {
			break;
		}
		f[r][c] = 99;
		f[spr][spc] = 0;
		ans += v[r][c];
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				v[i][j] = 0;
		spr = r; spc = c;
		sha_ex++;
		if (sha_ex == shark) {
			shark++;
			sha_ex = 0;
		}
	}
	cout << ans;
}