#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool ch[1001] = { false };
bool ch2[1001] = { false };

int arr[1001][1001] = { 0, };

int a, b, c;
int d, e;

void def(int x) {
	cout << x << " ";
	ch[x] = true;
	for (int i = 1; i < a + 1; i++) {
		if (arr[x][i] && !ch[i]) {
			def(i);
		}
	}
}


int main() {
	cin >> a >> b >> c;

	for (int i = 0; i < b; i++) {
		cin >> d >> e;
		arr[d][e] = 1;
		arr[e][d] = 1;
	}

	def(c);

	cout << '\n';

	queue <int> q;
	q.push(c);
	ch2[c] = true;

	while (!q.empty()) {
		int w = q.front();
		cout << w << " ";
		q.pop();
		for (int i = 1; i < a + 1; i++) {
			if (arr[w][i] && !ch2[i]) {
				q.push(i);
				ch2[i] = true;
			}
		}
	}

	return 0;
}
