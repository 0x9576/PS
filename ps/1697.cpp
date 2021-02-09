#include<iostream>
#include<queue>
#define M 100005
using namespace std;
int c[M];

int main() {
	int N, K, x;
	queue <int> q;
	cin >> N >> K;
	q.push(N);
	c[N] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x + 1 < M)
			if (!c[x + 1]) {
				q.push(x + 1);
				c[x + 1] = c[x] + 1;
			}
		if(2 * x < M)
			if (!c[2 * x]) {
				q.push(2 * x);
				c[2 * x] = c[x] + 1;
			}
		if(x > 0)
			if (!c[x - 1]) {
				q.push(x - 1);
				c[x - 1] = c[x] + 1;
			}
		if (c[K])
			break;
	}
	cout << c[K]-1;
}