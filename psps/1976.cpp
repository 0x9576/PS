#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
bool f[203][203], v[203];
int N, M, t[1009],cn;

void dfs(int c, int d) {
	v[c] = 1;
	if (c == d) {
		cn = c;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!v[i] && f[c][i])
			dfs(i, d);
	}
}

int main() {
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> f[i][j];
	for (int i = 0; i < M; i++)
		cin >> t[i];
	for (int i = 0; i < M - 1; i++) {
		cn = 0;
		dfs(t[i], t[i + 1]);
		if (cn != t[i + 1]) {
			cout << "NO";
			exit(0);
		}
		memset(v, 0, 203 * sizeof(bool));
	}
		cout << "YES";
}