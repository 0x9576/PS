#include<iostream>
#include<algorithm>
using namespace std;
int h[102][2];
int c[14][2];
int d[14];
int sl[102];
int N, M, num, hc, cc, ans;

void r(int a, int cou) {
	if (cou == M) {
		int s = 0;
		for (int i = 0; i < hc; i++)
			for (int j = 0; j < M; j++)
				sl[i] = min(sl[i], abs(h[i][0] - c[d[j]][0]) + abs(h[i][1] - c[d[j]][1]));

		for (int i = 0; i < hc; i++)
			s += sl[i];
		ans = min(ans, s);
		for (int i = 0; i < hc; i++)
			sl[i] = 999999;
		return;
	}
	d[cou] = a;

	for(int i = a+1; i<=cc-M+cou+1; i++)
		r(i, cou + 1);
}

int main() {
	ans = 9999999;
	hc = 0; cc = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> num;
			if (num == 1) {
				h[hc][0] = i; h[hc++][1] = j;
			}
			if (num == 2) {
				c[cc][0] = i; c[cc++][1] = j;
			}
		}
	for (int i = 0; i < 102; i++)
			sl[i] = 999999;

	for (int i = 0; i < cc; i++) {
		r(i, 0);
	}
		
	cout << ans;
}