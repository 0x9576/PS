#define INF 10000000
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a,b,c,f[102][102];
int main() {
	for (int i = 0; i < 102; i++)
		for (int j = 0; j < 102; j++) {
			f[i][j] = INF;
			if (i == j)
				f[i][j] = 0;
		}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		f[a][b] = min(f[a][b],c);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (f[i][j] >= INF)
				printf("0 ");
			else
				printf("%d ", f[i][j]);
		}
		puts("");
	}
}