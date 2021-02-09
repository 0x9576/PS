#include<iostream>
#include<algorithm>
using namespace std;
int n, m, M, co;
char f[1001][1001];

bool ch(int s) {
	for (int i = 0; i <= n - s; i++)
		for (int j = 0; j <= m - s; j++) {
			co = 0;
			for (int k = i; k < i + s; k++)
				for (int l = j; l < j + s; l++)
					if (f[k][l] == '1')
						co++;

			if (co == s * s)
				return true;
		}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> f[i][j];
		}
	M = min(m, n);
	for (int i = 1; i <= M; i++) {
		if (!ch(i)) {
			cout << (i - 1) * (i - 1);
			exit(0);
		}
	}
	cout << M * M;
}