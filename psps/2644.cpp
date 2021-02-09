#include<iostream>
#include<queue>
#include<utility>
using namespace std;
bool f[102][102];
int ch[102];

int main() {
	queue <int> q;
	int n, m,p1,p2, x, y;
	cin >> n >> p1 >> p2 >> m;
	for (int i = 0; i < 102; i++)
		ch[i] = -1;
	for (int i = 0; i < m; i++) {
		scanf("%d %d",&x,&y);
		f[x][y] = true;
		f[y][x] = true;
	}
	q.push(p1);
	ch[p1] = 0;

	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < 102; i++)
			if (f[x][i]) {
				if (ch[i] == -1) {
					q.push(i);
					ch[i] = ch[x] + 1;
				}
			}
	}

	cout << ch[p2];
}