#include<iostream>
#include<queue>
bool v[1000005];
using namespace std;
int main() {
	int F, S, G, U, D, q1, q2;
	cin >> F >> S >> G >> U >> D;
	queue<pair<int, int>> q;
	q.push({ S,0 });
	v[S] = true;
	while (!q.empty()) {
		q1 = q.front().first;
		q2 = q.front().second;
		q.pop();
		if (q1 == G) {
			cout << q2;
			exit(0);
		}

		if (q1 + U <= F && !v[q1 + U]) {
			q.push({ q1 + U,q2 + 1 });
			v[q1+U] = true;
		}
		if (q1 - D > 0 && !v[q1 - D]) {
			q.push({ q1 - D,q2 + 1 });
			v[q1 - D] = true;
		}
	}
	cout << "use the stairs";
}