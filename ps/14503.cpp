#include<iostream>
using namespace std;
int f[55][55];
int v[55][55];
int d, cou;

void bot(int r, int c) {
	if (!v[r][c]) {
		v[r][c] = ++cou;
	}
	if (v[r][c - 1] && v[r + 1][c] && v[r][c + 1] && v[r - 1][c]) {
		if (d == 0 && v[r + 1][c] > 1) {
			bot(r + 1, c);
		}
		else if (d == 1 && v[r][c - 1] > 1) {
			bot(r, c - 1);
		}
		else if (d == 2 && v[r - 1][c] > 1) {
			bot(r - 1, c);
		}
		else if (d == 3 && v[r][c + 1] > 1) {
			bot(r, c + 1);
		}
		else {
			cout << cou - 1;
			exit(0);
		}
	}
	else {
		if (d == 0) {
			d = 3;
			if (!v[r][c - 1])
				bot(r, c - 1);
			else
				bot(r, c);
		}
		if (d == 1) {
			d = 0;
			if (!v[r - 1][c])
				bot(r - 1, c);
			else
				bot(r, c);
		}
		if (d == 2) {
			d = 1;
			if (!v[r][c + 1])
				bot(r, c + 1);
			else
				bot(r, c);
		}
		if (d == 3) {
			d = 2;
			if (!v[r + 1][c])
				bot(r + 1, c);
			else
				bot(r, c);
		}
	}
}

int main() {
	int N, M, r, c;
	cou = 1;
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
		}
	bot(r, c);
}