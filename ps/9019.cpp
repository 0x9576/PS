#include<iostream>
#include<queue>
using namespace std;
int nd[4];
bool visited[10001];
queue < pair<int, vector<char>>> q;
vector<char> v;

int D(int n) {
	n *= 2;
	n %= 10000;
	return n;
}

int S(int n) {
	n -= 1;
	if (n < 0)
		n = 9999;
	return n;
}

int L(int n) {
	nd[0] = n / 1000;
	n %= 1000;
	nd[1] = n / 100;
	n %= 100;
	nd[2] = n / 10;
	n %= 10;
	nd[3] = n;
	return nd[1] * 1000 + nd[2] * 100 + nd[3] * 10 + nd[0];
}

int R(int n) {
	nd[0] = n / 1000;
	n %= 1000;
	nd[1] = n / 100;
	n %= 100;
	nd[2] = n / 10;
	n %= 10;
	nd[3] = n;
	return nd[3] * 1000 + nd[0] * 100 + nd[1] * 10 + nd[2];
}

int main() {
	int T, e1, e2, d, ac = 0;
	cin >> T;
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &e1, &e2);
		q.push({ e1,v });
		visited[e1] = true;
		while (!q.empty()) {
			int f = q.front().first;
			v = q.front().second;
			if (f == e2) {
				for (int i = 0; i < v.size(); i++)
					printf("%c", v.at(i));
				if (t < T - 1)
					puts("");
				break;
			}
			d = D(f);
			if (!visited[d]) {
				v.push_back('D');
				q.push({ d,v });
				visited[d] = true;
				v = q.front().second;
			}

			d = S(f);
			if (!visited[d]) {
				v.push_back('S');
				q.push({ d,v });
				visited[d] = true;
				v = q.front().second;
			}

			d = L(f);
			if (!visited[d]) {
				v.push_back('L');
				q.push({ d,v });
				visited[d] = true;
				v = q.front().second;
			}

			d = R(f);
			if (!visited[d]) {
				v.push_back('R');
				q.push({ d,v });
				visited[d] = true;
				v = q.front().second;
			}
			q.pop();
		}
		v.clear();
		q = queue < pair<int, vector<char>>>();
		for (int i = 0; i < 10001; i++)
			visited[i] = false;
	}
}