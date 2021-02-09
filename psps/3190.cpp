#include<iostream>
#include<deque>
using namespace std;
int f[105][105];
char r[10001];
deque <pair<int, int>> sn;
int d, s;

void sna(int i, int j) {
	s++;
	if (f[i][j] == 1 || f[i][j] == 2) {
		cout << s;
		exit(0);
	}

	if (f[i][j] != 3) {
		int a = sn.back().first;
		int b = sn.back().second;
		f[a][b] = 0;
		sn.pop_back();
	}
	sn.push_front(make_pair(i, j));
	f[i][j] = 2;
	if (r[s] == 'D')
		d++;
	if (r[s] == 'L')
		d--;
	if (d == -1)
		d = 3;
	if (d == 4)
		d = 0;

	if (d == 0)
		sna(i, j + 1);
	if (d == 1)
		sna(i + 1, j);
	if (d == 2)
		sna(i, j - 1);
	if (d == 3)
		sna(i - 1, j);
}

int main() {
	int N, K, a, b, L, c1;
	sn.push_front(make_pair(1, 1));
	f[1][1] = 2;
	char c2;
	cin >> N >> K;
	for (int i = 0; i <= N + 1; i++)
		for (int j = 0; j <= N + 1; j++)
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1)
				f[i][j] = 1;


	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		f[a][b] = 3;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> c1 >> c2;
		r[c1] = c2;
	}

	sna(1, 2);
}