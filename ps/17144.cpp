#include<iostream>
using namespace std;
int f[54][54], s[54][54];

int main() {
	for (int i = 0; i < 54; i++)
		for (int j = 0; j < 54; j++)
			f[i][j] = -2;
	int R, C, T, ap, ans = 0;
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> f[i][j];

	for (int t = 0; t < T; t++) {
		for (int i = 0; i < 54; i++)
			for (int j = 0; j < 54; j++) {
				s[i][j] = f[i][j];
				if (f[i][j] == -1)
					ap = i;
			}

		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++) {
				if (f[i][j] > 4) {
					int co = 0, fd = f[i][j] / 5;
					if (f[i + 1][j] > -1) {
						s[i + 1][j] += fd;
						co++;
					}
					if (f[i][j + 1] > -1) {
						s[i][j + 1] += fd;
						co++;
					}
					if (f[i - 1][j] > -1) {
						s[i - 1][j] += fd;
						co++;
					}
					if (f[i][j - 1] > -1) {
						s[i][j - 1] += fd;
						co++;
					}
					s[i][j] -= co * (f[i][j] / 5);
				}
			}
		for (int i = 0; i <= R; i++)
			for (int j = 0; j <= C; j++)
				f[i][j] = s[i][j];

		for (int i = 1; i < ap - 1; i++)
			f[i + 1][1] = s[i][1];
		for (int j = 1; j < C; j++) {
			f[1][j] = s[1][j + 1];
			f[R][j] = s[R][j + 1];
		}
		for (int i = 1; i < ap; i++)
			f[i][C] = s[i + 1][C];
		for (int j = 3; j <= C; j++) {
			f[ap - 1][j] = s[ap - 1][j - 1];
			f[ap][j] = s[ap][j - 1];
		}
		for (int i = ap + 1; i <= R; i++)
			f[i][C] = s[i - 1][C];
		for (int i = ap; i < R; i++)
			f[i][1] = s[i + 1][1];
		f[ap - 1][1] = -1;
		f[ap][1] = -1;
		f[ap - 1][2] = 0;
		f[ap][2] = 0;
	}

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (f[i][j] > -1)
				ans += f[i][j];

	cout << ans;
}