#include<iostream>
using namespace std;
int f[305][305],o[305][305],N,M,co,p,ans;
bool v[305][305];

bool all_zero() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (f[i][j])
				return 0;
	return 1;
}

void dfs(int a, int b) {
	v[a][b] = 1;
	if (f[a + 1][b] && !v[a+1][b] && f[a+1][b] !=-1) {
		v[a + 1][b] = 1;
		dfs(a + 1, b);
	}
	if (f[a - 1][b] && !v[a - 1][b] && f[a - 1][b] != -1) {
		v[a - 1][b] = 1;
		dfs(a - 1, b);
	}
	if (f[a][b+1] && !v[a][b+1] && f[a][b+1] != -1) {
		v[a][b+1] = 1;
		dfs(a, b+1);
	}
	if (f[a][b - 1] && !v[a][b - 1] && f[a][b - 1] != -1) {
		v[a][b - 1] = 1;
		dfs(a, b - 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < 305; i++)
		for (int j = 0; j < 305; j++) {
			f[i][j] = -1;
			o[i][j] = -1;
		}
	for(int i =1; i<=N; i++)
		for (int j = 1; j <= M; j++) {
			scanf("%d", f[i] + j);
			o[i][j] = f[i][j];
		}
	while (1) {
		if (all_zero()) {
			cout << "0";
			exit(0);
		}
		p = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (!v[i][j] && f[i][j]) {
					p++;
					dfs(i, j);
				}
		if (p != 1)
			break;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) {
				co = 0;
				if (f[i][j]) {
					if (!f[i + 1][j])
						co++;
					if (!f[i][j + 1])
						co++;
					if (!f[i - 1][j])
						co++;
					if (!f[i][j - 1])
						co++;
					if (f[i][j] > co)
						o[i][j] = f[i][j] - co;
					else
						o[i][j] = 0;
				}
			}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) {
				f[i][j] = o[i][j];
				v[i][j] = 0;
			}
		ans++;
	}
	cout << ans;
}