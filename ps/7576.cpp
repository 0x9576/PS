#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
int t[1005][1005];
int c[1005][1005];
queue <pair<int, int>> q;
int N, M, ch;

void cf(int i, int j) {
	if (t[i][j] == 0 && c[i][j] == -1) {
		q.push(make_pair(i, j));
		c[i][j] = ch;
	}
}

int main() {
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 1005; j++) {
			t[i][j] = -1; c[i][j] = -1;
		}
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &t[i][j]);

	int m = -1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (t[i][j] == 1 && c[i][j] == -1) {
				q.push(make_pair(i, j));
				c[i][j] = 0;
			}
		}

	int i, j;
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		ch = c[i][j] + 1;
		q.pop();
		cf(i - 1, j);
		cf(i + 1, j);
		cf(i, j - 1);
		cf(i, j + 1);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!t[i][j] && c[i][j] == -1) {
				cout << "-1";
				return 0;
			}
			else
				m = max(c[i][j], m);
		}
	}
	cout << m;
}