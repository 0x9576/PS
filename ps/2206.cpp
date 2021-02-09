#include<iostream>
#include<queue>
using namespace std;
int f[1009][1009], N, M, v[1009][1009][2], a, b, c, d;

class Node {
public:
	int an;
	int bn;
	int cn;
	bool dn;
	Node(int c1, int c2, int c3, bool c4) {
		an = c1;
		bn = c2;
		cn = c3;
		dn = c4;
	}
};

int main() {
	cin >> N >> M;
	for (int i = 0; i < 1009; i++)
		for (int j = 0; j < 1009; j++) {
			v[i][j][0] = 1;
			v[i][j][1] = 1;
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			scanf("%1d", f[i] + j);
			v[i][j][0] = 0;
			v[i][j][1] = 0;
		}

	queue <Node> q;
	q.push(Node(1, 1, 1, 1));
	v[1][1][1] = 1;
	v[1][1][0] = 1;
	while (!q.empty()) {
		Node no = q.front();
		a = no.an;
		b = no.bn;
		c = no.cn;
		d = no.dn;
		q.pop();
		if (a == N && b == M)
			break;
		if (!v[a + 1][b][d]) {
			if (!f[a + 1][b]) {
				q.push(Node(a + 1, b, c + 1, d));
				v[a + 1][b][d] = 1;
				if (d)
					v[a + 1][b][d - 1] = 1;
			}
			if (f[a + 1][b] && d) {
				q.push(Node(a + 1, b, c + 1, 0));
				v[a + 1][b][d - 1] = 1;
			}
		}
		if (!v[a - 1][b][d]) {
			if (!f[a - 1][b]) {
				q.push(Node(a - 1, b, c + 1, d));
				v[a - 1][b][d] = 1;
				if (d)
					v[a - 1][b][d - 1] = 1;
			}
			if (f[a - 1][b] && d) {
				q.push(Node(a - 1, b, c + 1, 0));
				v[a - 1][b][d - 1] = 1;
			}
		}
		if (!v[a][b + 1][d]) {
			if (!f[a][b + 1]) {
				q.push(Node(a, b + 1, c + 1, d));
				v[a][b + 1][d] = 1;
				if (d)
					v[a][b + 1][d - 1] = 1;
			}
			if (f[a][b + 1] && d) {
				q.push(Node(a, b + 1, c + 1, 0));
				v[a][b + 1][d - 1] = 1;
			}
		}
		if (!v[a][b - 1][d]) {
			if (!f[a][b - 1]) {
				q.push(Node(a, b - 1, c + 1, d));
				v[a][b - 1][d] = 1;
				if (d)
					v[a][b - 1][d - 1] = 1;
			}
			if (f[a][b - 1] && d) {
				q.push(Node(a, b - 1, c + 1, 0));
				v[a][b - 1][d - 1] = 1;
			}
		}
	}
	if (v[N][M][0])
		cout << c;
	else
		cout << -1;
}