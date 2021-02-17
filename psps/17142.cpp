#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define v1 vec[a].first
#define v2 vec[a].second
using namespace std;
int N, M, f[55][55], o[55][55], ans = 9999, st, q1, q2,qm;
vector<pair<int, int>> vec;
queue<pair<int, int>>q;

bool ful() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (!f[i][j])
				return 0;
	return 1;
}

void sel(int i, int s) {
	if (s == M) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (f[i][j] == 2)
					q.push({ i,j });
		qm = 0;
		while (!q.empty()) {
			q1 = q.front().first;
			q2 = q.front().second;
			q.pop();
			if (!f[q1 + 1][q2] || f[q1 + 1][q2] == -1) {
				if (!f[q1 + 1][q2]) {
					f[q1 + 1][q2] = f[q1][q2] + 1;
					qm = max(qm, f[q1 + 1][q2]);
				}
				else {
					f[q1 + 1][q2] = f[q1][q2] + 1;
				}
				q.push({ q1 + 1,q2 });
			}
			if (!f[q1 - 1][q2] || f[q1 - 1][q2] == -1) {
				if (!f[q1 - 1][q2]) {
					f[q1 - 1][q2] = f[q1][q2] + 1;
					qm = max(qm, f[q1 - 1][q2]);
				}
				else {
					f[q1 - 1][q2] = f[q1][q2] + 1;
				}
				q.push({ q1 - 1,q2 });
			}
			if (!f[q1][q2 + 1] || f[q1][q2 + 1] == -1) {
				if (!f[q1][q2+1]) {
					f[q1][q2+1] = f[q1][q2] + 1;
					qm = max(qm, f[q1][q2+1]);
				}
				else {
					f[q1][q2+1] = f[q1][q2] + 1;
				}
				q.push({ q1,q2 + 1 });
			}
			if (!f[q1][q2 - 1] || f[q1][q2 - 1] == -1) {
				if (!f[q1][q2 - 1]) {
					f[q1][q2 - 1] = f[q1][q2] + 1;
					qm = max(qm, f[q1][q2 - 1]);
				}
				else {
					f[q1][q2 - 1] = f[q1][q2] + 1;
				}
				q.push({ q1,q2 - 1 });
			}
		}
		if (ful()) {
			if (qm == 0)
				qm = 2;
			ans = min(ans, qm - 2);
		}
		while (!q.empty())
			q.pop();
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				f[i][j] = o[i][j];
	}
	else {
		for (int a = i + 1; a < vec.size(); a++) {
			f[v1][v2] = 2;
			o[v1][v2] = 2;
			sel(a, s + 1);
			f[v1][v2] = -1;
			o[v1][v2] = -1;
		}
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
				f[i][j] = -1;
			}
			o[i][j] = f[i][j];
		}
	for (int a = 0; a < vec.size() - M + 1; a++) {
		f[v1][v2] = 2;
		o[v1][v2] = 2;
		sel(a, 1);
		f[v1][v2] = -1;
		o[v1][v2] = -1;
	}

	if (ans != 9999) {
		cout << ans;
		exit(0);
	}
	cout << -1;
	return 0;
}