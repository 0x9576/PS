#include<iostream>
#include<queue>
using namespace std;
char f[54][54];
int v[54][54];
int R, C;

int main() {
	int s1, s2, d1, d2, lv;
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			v[i][j] = -1;
			cin >> f[i][j];
			if (f[i][j] == 'S') {
				s1 = i; s2 = j;
			}
			if (f[i][j] == 'D') {
				d1 = i; d2 = j;
			}
		}
	queue <pair<int, int>> q;
	q.push({ s1,s2 });
	v[s1][s2] = 0;
	lv = -1;
	while (!q.empty()) {
		s1 = q.front().first;
		s2 = q.front().second;
		if (v[d1][d2] != -1)
			break;
		q.pop();
		queue <pair<int, int>> wq;
		if (lv != v[s1][s2]) {
			for (int i = 1; i <= R; i++)
				for (int j = 1; j <= C; j++)
					if (f[i][j] == '*') {
						if (f[i + 1][j] == '.') {
							wq.push({ i + 1,j });
						}
						if (f[i - 1][j] == '.') {
							wq.push({ i - 1,j });
						}
						if (f[i][j + 1] == '.') {
							wq.push({ i,j + 1 });
						}
						if (f[i][j - 1] == '.') {
							wq.push({ i,j - 1 });
						}
					}
			while (!wq.empty()) {
				f[wq.front().first][wq.front().second] = '*';
				wq.pop();
			}
		}
		if ((f[s1 + 1][s2] == '.' || f[s1 + 1][s2] == 'D') && v[s1 + 1][s2] == -1) {
			q.push({ s1 + 1,s2 });
			v[s1 + 1][s2] = v[s1][s2] + 1;
		}
		if ((f[s1 - 1][s2] == '.' || f[s1 - 1][s2] == 'D') && v[s1 - 1][s2] == -1) {
			q.push({ s1 - 1,s2 });
			v[s1 - 1][s2] = v[s1][s2] + 1;
		}
		if ((f[s1][s2 + 1] == '.' || f[s1][s2 + 1] == 'D') && v[s1][s2 + 1] == -1) {
			q.push({ s1,s2 + 1 });
			v[s1][s2 + 1] = v[s1][s2] + 1;
		}
		if ((f[s1][s2 - 1] == '.' || f[s1][s2 - 1] == 'D') && v[s1][s2 - 1] == -1) {
			q.push({ s1,s2 - 1 });
			v[s1][s2 - 1] = v[s1][s2] + 1;
		}
		lv = v[s1][s2];
	}
	if (v[d1][d2] == -1)
		cout << "KAKTUS";
	else
		cout << v[d1][d2];
}