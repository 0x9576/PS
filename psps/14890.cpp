#include<iostream>
#include<algorithm>
using namespace std;
int N, L, f[103][103], ans;
bool sl[103][103];

bool chc(int c) {
	for (int i = 0; i < N - 1; i++) {
		if (abs(f[i][c] - f[i + 1][c]) > 1) {
			//cout << c <<  " aa" << endl;
			return 0;
		}

		if (f[i][c] - f[i + 1][c] == 1) {
			if (i + L + 1 > N) {
				//cout << c <<  " aa" << endl;
				return 0;
			}
			else
				for (int j = i + 1; j <= i + L; j++) {
					if (f[i + 1][c] != f[j][c]) {
						//cout << c << " " << j << " aa" << endl;
						return 0;
					}
					sl[j][c] = 1;
				}


		}
		if (f[i][c] - f[i + 1][c] == -1) {
			if (i - L + 1 < 0) {
				//cout << c << " aa" << endl;
				return 0;
			}
			else
				for (int j = i; j >= i - L + 1; j--)
					if (f[i][c] != f[j][c] || sl[j][c]) {
						//cout << c << " aa" << endl;
						return 0;
					}
		}
	}
	//cout << "aac" << c << " " << endl;
	return 1;
}

bool chr(int r) {
	for (int i = 0; i < N - 1; i++) {
		if (abs(f[r][i] - f[r][i + 1]) > 1)
			return 0;
		if (f[r][i] - f[r][i + 1] == 1) {
			if (i + L + 1 > N)
				return 0;
			else
				for (int j = i + 1; j <= i + L; j++) {
					if (f[r][i + 1] != f[r][j])
						return 0;
					sl[r][j] = 1;
				}

		}
		if (f[r][i] - f[r][i + 1] == -1) {
			if (i - L + 1 < 0)
				return 0;
			else
				for (int j = i; j >= i - L + 1; j--)
					if (f[r][i] != f[r][j] || sl[r][j])
						return 0;
		}
	}
	//cout << "aar" << r << " " << endl;
	return 1;
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> f[i][j];
	for (int i = 0; i < N; i++) {
		if (chc(i))
			ans++;
		for (int j = 0; j < N; j++)
			sl[j][i] = 0;
		if (chr(i))
			ans++;
		for (int j = 0; j < N; j++)
			sl[i][j] = 0;
	}
	cout << ans;
}