#include <iostream>
#include<algorithm>
using namespace std;

int mem[101][10005], n, k, m[101], c[101], ans = 99999;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> m[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 10003; j++) {
			int ci = c[i];
			int mi = m[i];
			if (ci > j)
				mem[i][j] = mem[i - 1][j];
			else
				mem[i][j] = max(mem[i - 1][j], mi + mem[i - 1][j - ci]);
			if (mem[i][j] >= k)
				ans = min(ans, j);
		}
	}
	cout << ans;
}