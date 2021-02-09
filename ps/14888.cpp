#include <iostream>
#include<algorithm>
using namespace std;
int e[12], N, c[4], n, ma = -1000000000, mi = 1000000000;

void dfs(int n, int s) {
	if (s == N) {
		ma = max(n, ma);
		mi = min(n, mi);
		return;
	}
	if (c[0] > 0) {
		--c[0];
		dfs(n + e[s], s + 1);
		++c[0];
	}
	if (c[1] > 0) {
		--c[1];
		dfs(n - e[s], s + 1);
		++c[1];
	}
	if (c[2] > 0) {
		--c[2];
		dfs(n * e[s], s + 1);
		++c[2];
	}
	if (c[3] > 0) {
		--c[3];
		dfs(n / e[s], s + 1);
		++c[3];
	}

}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> e[i];
	for (int i = 0; i < 4; i++)
		cin >> c[i];
	n = e[0];
	dfs(n, 1);
	cout << ma << " " << mi;
}
