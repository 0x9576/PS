#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int f[55][55], com, N, L, R, ans;
bool c[55][55];

vector<pair<int, int>>v;

void dfs(int a, int b) {
	c[a][b] = true;
	int fab = f[a][b];
	com += fab;
	v.push_back({ a,b });
	if (abs(fab - f[a + 1][b]) >= L && abs(fab - f[a + 1][b]) <= R && !c[a+1][b])
		dfs(a + 1, b);
	if (abs(fab - f[a - 1][b]) >= L && abs(fab - f[a - 1][b]) <= R && !c[a - 1][b])
		dfs(a - 1, b);
	if (abs(fab - f[a][b + 1]) >= L && abs(fab - f[a][b + 1]) <= R && !c[a][b+1])
		dfs(a, b + 1);
	if (abs(fab - f[a][b - 1]) >= L && abs(fab - f[a][b - 1]) <= R && !c[a][b - 1])
		dfs(a, b - 1);
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < 55; i++)
		for (int j = 0; j < 55; j++)
			f[i][j] = 999;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> f[i][j];
	while (true) {
		int cnt = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				if (!c[i][j]) {
					com = 0;
					dfs(i, j);
					if (v.size() > 1)
						cnt++;
					com /= v.size();
					for (int i = 0; i < v.size(); i++) {
						int v1 = v.at(i).first;
						int v2 = v.at(i).second;
						f[v1][v2] = com;
					}
					v.clear();
				}
			}
		if (cnt == 0)
			break;
		for (int i = 0; i < 55; i++)
			for (int j = 0; j < 55; j++)
				c[i][j] = false;
		ans++;
	}

	cout << ans;
}