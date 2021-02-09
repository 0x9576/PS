#include<iostream>
using namespace std;
char f[103][103];
bool v[103][103];
int N, a;
void dfs(int i, int j) {
	if (v[i][j])
		return;
	v[i][j] = true;
	if (f[i][j] == f[i + 1][j])
		dfs(i + 1, j);
	if (f[i][j] == f[i - 1][j])
		dfs(i - 1, j);
	if (f[i][j] == f[i][j+1])
		dfs(i, j+1);
	if (f[i][j] == f[i][j - 1])
		dfs(i, j - 1);
}

void ch() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (!v[i][j]) {
				dfs(i, j);
				a++;
			}
	cout << a << " ";
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> f[i][j];
	ch();
	a = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			if (f[i][j] == 'R')
				f[i][j] = 'G';
			v[i][j] = false;
		}
	ch();
}