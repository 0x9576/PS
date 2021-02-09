#include<iostream>
using namespace std;
char f[16][9];
bool ch[16][9], v[16][9];
int con, ans, co;

void dfs(int a, int b) {
	ch[a][b] = 1;
	v[a][b] = 1;
	co++;
	if (f[a][b] == f[a][b + 1] && !v[a][b + 1])
		dfs(a, b + 1);
	if (f[a][b] == f[a + 1][b] && !v[a + 1][b])
		dfs(a + 1, b);
	if (f[a][b] == f[a - 1][b] && !v[a - 1][b])
		dfs(a - 1, b);
	if (f[a][b] == f[a][b - 1] && !v[a][b - 1])
		dfs(a, b - 1);
}

int main() {
	for (int i = 1; i < 13; i++)
		for (int j = 1; j < 7; j++)
			cin >> f[i][j];
	while (true) {
		con = 0;
		for (int i = 1; i < 13; i++)
			for (int j = 1; j < 7; j++)
				if (f[i][j] != '.' && !v[i][j]) {
					co = 0;
					dfs(i, j);
					if (co > 3) {
						for (int i = 1; i < 13; i++)
							for (int j = 1; j < 7; j++) {
								if (ch[i][j]) {
									f[i][j] = '.';
								}
							}
						con++;
					}
					for (int i = 1; i < 13; i++)
						for (int j = 1; j < 7; j++) {
							ch[i][j] = 0;
						}
				}
		if (!con)
			break;
		for (int k = 0; k < 12; k++)
			for (int i = 1; i < 13; i++)
				for (int j = 1; j < 7; j++) {
					if (f[i][j] != '.' && f[i + 1][j] == '.') {
						f[i + 1][j] = f[i][j];
						f[i][j] = '.';
					}
					v[i][j] = 0;
				}
		ans++;
	}
	cout << ans;
}