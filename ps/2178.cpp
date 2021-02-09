#include<iostream>
#include<queue>
#include<utility>

using namespace std;
int f[102][102];
int ch[102][102];

int main() {
	int N, M;
	cin >> N >> M;
	char ip;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> ip;
			f[i][j] = ip - '0';
		}
	queue <pair<int,int>> q;
	q.push(make_pair(1, 1));
	ch[1][1] = 1;

	int x, y;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (f[x + 1][y])
			if (!ch[x + 1][y]) {
				q.push(make_pair(x + 1, y));
				ch[x + 1][y] = ch[x][y]+1;
			}
		if (f[x - 1][y])
			if (!ch[x - 1][y]) {
				q.push(make_pair(x - 1, y));
				ch[x - 1][y] = ch[x][y] + 1;
			}
		if (f[x][y-1])
			if (!ch[x][y-1]) {
				q.push(make_pair(x, y-1));
				ch[x][y-1] = ch[x][y] + 1;
			}
		if (f[x][y+1])
			if (!ch[x][y+1]) {
				q.push(make_pair(x, y+1));
				ch[x][y+1] = ch[x][y] + 1;
			}
	}
	cout << ch[N][M];
}
