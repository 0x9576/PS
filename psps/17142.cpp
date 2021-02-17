#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, f[55][55], v[55][55], v1, v2, o[55][55], ans = 999,st;
vector<pair<int, int>> vec;

bool ful() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (!f[i][j])
				return 0;
	return 1;
}

void spr(int t) {
	if (ful()) {
		cout << t<<" ";
		ans = min(ans, t);
		return;
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (f[i][j] == 2) {
				if (!f[i + 1][j] && !v[i + 1][j]) {
					v[i + 1][j] = 1;
					o[i + 1][j] = 2;
				}
				if (!f[i - 1][j] && !v[i - 1][j]) {
					v[i - 1][j] = 1;
					o[i - 1][j] = 2;
				}
				if (!f[i][j + 1] && !v[i][j + 1]) {
					v[i][j + 1] = 1;
					o[i][j + 1] = 2;
				}
				if (!f[i][j - 1] && !v[i][j - 1]) {
					v[i][j - 1] = 1;
					o[i][j - 1] = 2;
				}
			}

	st = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (o[i][j] = 2) {
				f[i][j] = 2;
				st++;
			}
			o[i][j] = 0;
		}
	if (!st)
		return;
	else
		spr(t + 1);
}

void sel(int a, int s) {
	if (s == M - 1) {
		spr(0);
		for (int i = 0; i < 55; i++)
			for (int j = 0; j < 55; j++)
				v[i][j] = 0;
		return;
	}
	v1 = vec[a].first;
	v2 = vec[a].second;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cout << f[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

	for (int i = a + 1; i < vec.size(); i++) {
		f[v1][v2] = 2;
		v[v1][v2] = 1;
		sel(i, s + 1);
		f[v1][v2] = 0;
		v[v1][v2] = 0;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 55; i++)
		for (int j = 0; j < 55; j++)
			f[i][j] = 1;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> f[i][j];
			if (f[i][j] == 2) {
				vec.push_back({ i,j });
				f[i][j] = 0;
			}
		}
	for (int i = 0; i < vec.size() - M + 1; i++)
		sel(i, 0);
	if (ans != 999)
		cout << ans;
	else
		cout << -1;
}