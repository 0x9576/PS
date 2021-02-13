#include<iostream>
#include<vector>
using namespace std;
int N, M, K, f[14][14], a, b, c, A[14][14], ans, z[8][2] = { {-1,-1},{-1,0},{0,-1},{1,0},{0,1},{1,1},{-1,1},{1,-1} };
vector<int> v[14][14];
int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", A[i] + j);
			f[i][j] += 5;
		}

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a][b].push_back(c);
	}
	while (K--) {
		//spring
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				for (int k = v[i][j].size() - 1; k >= 0; k--) {
					if (f[i][j] >= v[i][j][k])
						f[i][j] -= v[i][j][k]++;
					else
						v[i][j][k] *= -1;
				}
		//summer
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				for (int k = v[i][j].size() - 1; k >= 0; k--) {
					if (v[i][j][k] < 0) {
						f[i][j] -= v[i][j][k] / 2;
						v[i][j].erase(v[i][j].begin()+k);
					}
				}
		//autumn
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				for (int k = v[i][j].size() - 1; k >= 0; k--) {
					if (!(v[i][j][k] % 5) && v[i][j][k])
						for(int a =0; a<8; a++)
							v[i + z[a][0]][j + z[a][1]].push_back(1);
				}
		//winter
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				f[i][j] += A[i][j];
		/*cout << K << ": ";
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				for (int k = v[i][j].size() - 1; k >= 0; k--) {
					if (v[i][j][k])
						cout << i << " " << j << " " << v[i][j][k] << endl;
				}*/
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = v[i][j].size() - 1; k >= 0; k--) {
				if (v[i][j][k])
					ans++;
			}
	cout << ans;
}