#include<iostream>
#include<queue>
using namespace std;
int T, w, h, v[1009][1009], fv[1009][1009], ans[109], da[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }, pv, q1, q2, f1, f2, fqs, fq1, fq2;
char f[1009][1009];
queue <pair<int, int>> q, fq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 109; i++)
		ans[i] = -1;
	cin >> T;
	for (int z = 0; z < T; z++) {
		while (!q.empty())
			q.pop();
		while (!fq.empty())
			fq.pop();
		pv = 0;
		for (int i = 0; i < 1009; i++)
			for (int j = 0; j < 1009; j++) {
				f[i][j] = '#';
				v[i][j] = 0;
				fv[i][j] = 0;
			}
		cin >> w >> h;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++) {
				cin >> f[i][j];
				if (f[i][j] == '@') {
					q.push({ i,j });
					v[i][j] = 1;
					f[i][j] = '.';
				}
				if (f[i][j] == '*') {
					fq.push({ i,j });
					fv[i][j] = 1;
				}

			}
		while (!q.empty()) {
			q1 = q.front().first;
			q2 = q.front().second;
			q.pop();
			if (q1 == h || q2 == w || q1 == 1 || q2 == 1) {
				ans[z] = v[q1][q2];
				break;
			}
			if (v[q1][q2] > pv) {
				pv = v[q1][q2];
				fqs = fq.size();
				for (int i = 0; i < fqs; i++) {
					fq1 = fq.front().first;
					fq2 = fq.front().second;
					fq.pop();
					for (int k = 0; k < 4; k++) {
						f1 = fq1 + da[k][0];
						f2 = fq2 + da[k][1];
						if (f[f1][f2] == '.' && !fv[f1][f2]) {
							f[f1][f2] = '*';
							fv[f1][f2] = fv[fq1][fq2] + 1;
							fq.push({ f1,f2 });
						}
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				f1 = q1 + da[i][0];
				f2 = q2 + da[i][1];
				if (f[f1][f2] == '.' && !v[f1][f2]) {
					q.push({ f1,f2 });
					v[f1][f2] = v[q1][q2] + 1;
				}
			}
		}
	}
	for (int i = 0; i < T; i++)
		if (ans[i] == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans[i] << "\n";
}