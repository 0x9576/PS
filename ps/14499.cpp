#include<iostream>
#include<algorithm>
using namespace std;
int N, M, x, y, K, e;
int f[23][23];
int df2[4] = { 2,1,5,6 };
int df1[4] = { 4,1,3,6 };
int cpy[4];
int dice[7];
int ans[10010];
int cou;

void r() {
	if (!f[y][x])
		f[y][x] = dice[df1[3]];
	else {
		dice[df1[3]] = f[y][x];
		f[y][x] = 0;
	}
	ans[cou++] = dice[df1[1]];
}

void d(int e) {
	if (e == 1) {
		if (x > M-2)
			return;
		copy(df1, df1 + 4, cpy);
		for (int i = 1; i < 4; i++)
			df1[i - 1] = cpy[i];
		df1[3] = cpy[0];
		x++;
	}
	if (e == 2) {
		if (x <= 0)
			return;
		copy(df1, df1 + 4, cpy);
		for (int i = 0; i < 3; i++)
			df1[i + 1] = cpy[i];
		df1[0] = cpy[3];
		if (x > 0)
			x--;
	}
	if (e == 3) {
		if (y <= 0)
			return;
		copy(df2, df2 + 4, cpy);
		for (int i = 1; i < 4; i++)
			df2[i - 1] = cpy[i];
		df2[3] = cpy[0];
		if (y > 0)
			y--;
	}
	if (e == 4) {
		if (y > N-2)
			return;
		copy(df2, df2 + 4, cpy);
		for (int i = 0; i < 3; i++)
			df2[i + 1] = cpy[i];
		df2[0] = cpy[3];
		if (y < N)
			y++;
	}
	if (e == 1 || e == 2) {
		df2[1] = df1[1];
		df2[3] = df1[3];
	}else {
		df1[1] = df2[1];
		df1[3] = df2[3];
	}
	r();
}

int main() {
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> f[i][j];
	for (int i = 0; i < K; i++) {
		cin >> e;
		d(e);
	}

	for (int i = 0; i < cou; i++)
		cout << ans[i] << endl;
}