#include<iostream>
#include<vector>
using namespace std;
int f[12][12], sf[12][12][15];
int o[12][12];
int N, M, ans = 99, cn;
vector <pair<int, int>> v;

void s1(int a, int b, int an) {
	an %= 4;
	if (an == 0) {
		for (int i = a - 1; i > 0; i--) {
			if (!f[i][b])
				f[i][b] = 7;
			if (f[i][b] == 6)
				break;
		}
	}
	if (an == 1) {
		for (int i = b + 1; i <= M; i++) {
			if (!f[a][i])
				f[a][i] = 7;
			if (f[a][i] == 6)
				break;
		}
	}
	if (an == 2) {
		for (int i = a + 1; i <= N; i++) {
			if (!f[i][b])
				f[i][b] = 7;
			if (f[i][b] == 6)
				break;
		}
	}
	if (an == 3) {
		for (int i = b - 1; i > 0; i--) {
			if (!f[a][i])
				f[a][i] = 7;
			if (f[a][i] == 6)
				break;
		}
	}
}

void save(int level) {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			sf[i][j][level] = f[i][j];
}

void load(int level) {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			f[i][j] = sf[i][j][level];
}

void dfs(int level) {
	if (level == v.size()+1) {
		cn = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!f[i][j])
					cn++;
			}
		}

		if (ans > cn)
			ans = cn;
		return;
	}
	int a = v.at(level - 1).first, b = v.at(level - 1).second, p = f[a][b];
	if (p == 1)
		for (int i = 0; i < 4; i++) {
			load(level - 1);
			s1(a, b, i);
			save(level);
			dfs(level + 1);
		}
	if (p == 2)
		for (int i = 0; i < 2; i++) {
			load(level - 1);
			s1(a, b, i);
			s1(a, b, i + 2);
			save(level);
			dfs(level + 1);
		}
	if (p == 3)
		for (int i = 0; i < 4; i++) {
			load(level - 1);
			s1(a, b, i);
			s1(a, b, i + 1);
			save(level);
			dfs(level + 1);
		}
	if (p == 4)
		for (int i = 0; i < 4; i++) {
			load(level - 1);
			s1(a, b, i);
			s1(a, b, i + 1);
			s1(a, b, i + 2);
			save(level);
			dfs(level + 1);
		}
	if (p == 5) {
		load(level - 1);
		for (int i = 0; i < 4; i++)
			s1(a, b, i);
		save(level);
		dfs(level + 1);
	}
	return;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 12; j++)
			f[i][j] = 6;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> f[i][j];
			if (f[i][j] < 6 && f[i][j])
				v.push_back({ i,j });
		}
	save(0);
	dfs(1);
	cout << ans;
}