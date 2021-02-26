#include<iostream>
#define Z 105
using namespace std;
int N, M, c[Z][Z], f[Z][Z],s[Z][Z], p[4][2] = { {1,0},{-1,0},{0,1},{0,-1} },co,ans;

void dfs(int a, int b) {
	f[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		int na = a + p[i][0];
		int nb = b + p[i][1];
		if(!c[na][nb]&&!f[na][nb])
			dfs(na, nb);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < Z; i++)
		for (int j = 0; j < Z; j++)
			c[i][j] = 2;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", c[i] + j);
	while (1) {
		co = 0;
		for (int i = 0; i < Z; i++)
			for (int j = 0; j < Z; j++) {
				if (c[i][j]==1)
					co++;
				f[i][j] = 0;
				s[i][j] = 0;
			}
		if (!co)
			break;
		dfs(1, 1);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (c[i][j])
					for (int k = 0; k < 4; k++) {
						int ni = i + p[k][0];
						int nj = j + p[k][1];
						if (f[ni][nj]==1)
							s[i][j]++;
					}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (s[i][j] > 1)
					c[i][j] = 0;
		ans++;
	}
	cout << ans;
}