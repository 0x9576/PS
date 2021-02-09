#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int f[52][52], o[52][52], R, C, q1, q2, ans;
int main() {
	queue<pair<int, int>> q;
	char e;
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			cin >> e;
			if (e == 'L')
				f[i][j] = -1;
			o[i][j] = f[i][j];
		}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			if (f[i][j]) {
				q.push({ i,j });
				f[i][j] = 0;
			}
			while (!q.empty()) {
				q1 = q.front().first;
				q2 = q.front().second;
				q.pop();
				if (f[q1 + 1][q2] == -1) {
					f[q1 + 1][q2] = f[q1][q2] + 1;
					q.push({ q1 + 1,q2 });
				}
				if (f[q1 - 1][q2] == -1) {
					f[q1 - 1][q2] = f[q1][q2] + 1;
					q.push({ q1 - 1,q2 });
				}
				if (f[q1][q2 + 1] == -1) {
					f[q1][q2 + 1] = f[q1][q2] + 1;
					q.push({ q1,q2 + 1 });
				}
				if (f[q1][q2 - 1] == -1) {
					f[q1][q2 - 1] = f[q1][q2] + 1;
					q.push({ q1,q2 - 1 });
				}
			}
			for (int k = 0; k < 52; k++)
				for (int l = 0; l < 52; l++) {
					ans = max(ans, f[k][l]);
					f[k][l] = o[k][l];
				}
		}
	cout << ans;
}