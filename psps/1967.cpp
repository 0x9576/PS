#include <iostream>
#include <vector>
#include<cstring>
using namespace std;
vector<pair<int, int>> vec[10002];
int n, a, b, c, dz, dl, fv, sv;
bool v[10002];

void dfs(int z, int l) {
	if (v[z])
		return;
	v[z] = 1;
	if (l > dl) {
		dz = z;
		dl = l;
	}
	for (int i = 0; i < vec[z].size(); i++) {
		fv = vec[z][i].first;
		sv = vec[z][i].second;
		dfs(fv, sv + l);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	dfs(1, 0);
	dl = 0;
	memset(v, 0, 10001);
	dfs(dz, 0);
	cout << dl;
}