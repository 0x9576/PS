#include<iostream>
#include<algorithm>
using namespace std;
int f[28][28];
int c[28][28];
int ans[10000];
int cou = 0;
int s = 0;

void dfs(int i, int j) {
	c[i][j] = ++cou;
	if (f[i - 1][j] && !c[i - 1][j])
		dfs(i - 1, j);
	if (f[i][j - 1] && !c[i][j - 1])
		dfs(i, j - 1);
	if (f[i + 1][j] && !c[i + 1][j])
		dfs(i + 1, j);
	if (f[i][j + 1] && !c[i][j + 1])
		dfs(i, j + 1);
}

int main() {
	int N;
	char z;
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> z;
			f[i][j] = z - '0';
		}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (f[i][j] && !c[i][j]) {
				dfs(i, j);
				ans[s++] = cou;
				cou = 0;
			}
		}
	cout << s << endl;
	sort(ans,ans+s);
	for (int i = 0; i < s; i++) {
		printf("%d\n", ans[i]);
	}
}