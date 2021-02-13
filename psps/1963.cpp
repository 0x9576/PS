#include<iostream>
#include<queue>
using namespace std;
int v[10000],T,a1,a2,a3,a4,n,m,tem;
bool p[10000];
queue<int> q;
int main() {
	p[0] = 1;
	p[1] = 1;
	for (int i = 0; i < 10000; i++) {
		if (!p[i]) {
			for (int j = i * 2; j < 10000; j += i)
				p[j] = 1;
		}
		v[i] = -1;
	}
	cin >> T;
	while (T--) {
		cin >> n >> m;
		q.push(n);
		v[n] = 0;
		while (!q.empty()) {
			n = q.front();
			q.pop();
			a1 = n / 1000;
			if (n == m)
				break;
			for (int i = 1; i < 10; i++) {
				tem = n + 1000 * (i - a1);
				if (!p[tem] && v[tem] == -1) {
					v[tem] = v[n] + 1;
					q.push(tem);
				}
			}
			a2 = (n-a1*1000) / 100;
			for (int i = 0; i < 10; i++) {
				tem = n + 100 * (i - a2);
				if (!p[tem] && v[tem] == -1) {
					v[tem] = v[n] + 1;
					q.push(tem);
				}
			}
			a3 = (n - a1 * 1000 - a2 *100) / 10;
			for (int i = 0; i < 10; i++) {
				tem = n + 10 * (i - a3);
				if (!p[tem] && v[tem] == -1) {
					v[tem] = v[n] + 1;
					q.push(tem);
				}
			}
			a4 = n - a1 * 1000 - a2 * 100 -10 * a3;
			for (int i = 0; i < 10; i++) {
				tem = n + (i - a4);
				if (!p[tem] && v[tem] == -1) {
					v[tem] = v[n] + 1;
					q.push(tem);
				}
			}
		}
		while (!q.empty())
			q.pop();
		if (v[m] != -1)
			cout << v[m]<<endl;
		else
			cout << "Impossible"<<endl;
		for (int i = 0; i < 10000; i++)
			v[i] = -1;
	}
}