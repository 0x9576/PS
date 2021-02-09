#include<iostream>
using namespace std;
int f[106][106], N, M, co, cc;
bool ch[106][106], o[106][106];

bool chb() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (f[i][j])
				return false;
	return true;
}

void dfs(int a, int b) {
	ch[a][b] = 1;
	if (f[a][b]) {
		o[a][b] = 1;
		return;
	}
	if (!ch[a + 1][b] && a + 1 <= N)
		dfs(a + 1, b);
	if (!ch[a - 1][b] && a - 1 > 0)
		dfs(a - 1, b);
	if (!ch[a][b - 1] && b - 1 > 0)
		dfs(a, b - 1);
	if (!ch[a][b + 1] && b + 1 <= M)
		dfs(a, b + 1);
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> f[i][j];
	co = 1;
	while (true) {
		cc = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (f[i][j])
					cc++;
		dfs(1, 1);

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) {
				if (o[i][j])
					f[i][j] = 0;
				ch[i][j] = 0;
				o[i][j] = 0;
			}
		if (chb())
			break;
		co++;
	}
	cout << co << endl << cc;
}