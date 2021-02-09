#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue < pair<int, int>>q;
bool ch[100005] = { false };

int main() {
	int a, b;
	cin >> a >> b;
	int sec = 0;
	int p = a;
	q.push(make_pair(p,sec));
	ch[a] = true;

	while (!q.empty()) {
		p = q.front().first;
		sec = q.front().second;
		q.pop();

		if (p == b) {
			break;
		}

		if (p * 2 < 100001) {
			if (ch[p * 2] == false) {
				q.push(make_pair(p * 2, sec));
				ch[p * 2] = true;
			}
		}

		if (p - 1 < 100001&& p-1>=0) {
			if (ch[p - 1]==false) {
				q.push(make_pair(p - 1, sec + 1));
				ch[p - 1] = true;
			}
		}

		if (p + 1 < 100001) {
			if (ch[p + 1]==false) {
				q.push(make_pair(p + 1, sec + 1));
				ch[p + 1] = true;
			}
		}
	}
	cout << sec << endl;
	return 0;
}
