#include<iostream>
#include<queue>
using namespace std;
int T, s1, s2, f1, f2, t1, t2, L, v[303][303],
z[8][2] = { {-1,-2},{-2,-1},{-1,2},{-2,1},{1,2},{2,1},{1,-2},{2,-1} };
queue<pair<int, int>> q;
int main() {
	cin >> T;
	while (T--) {
		for (int i = 0; i < 303; i++)
			for (int j = 0; j < 303; j++)
				v[i][j] = -1;
		cin >> L >> s1 >> s2 >> f1 >> f2;
		q.push({ s1,s2 });
		v[s1][s2] = 0;
		while (!q.empty()) {
			s1 = q.front().first;
			s2 = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				t1 = s1 + z[i][0];
				t2 = s2 + z[i][1];
				if (v[t1][t2] == -1 && t1 > -1 && t1 < L && t2 > -1 && t2 < L) {
					v[t1][t2] = v[s1][s2] + 1;
					q.push({ t1,t2 });
				}
			}
		}
		cout << v[f1][f2] << endl;
	}
}