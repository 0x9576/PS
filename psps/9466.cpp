#include<iostream>
#include<cstring>
using namespace std;
int n,e[100001],T,ans,v[100001];

void dfs(int a) {
	int next = e[a];
	v[a] = 1;
	if(!v[next])
		dfs(next);
	if (v[next] == 1) {
		for (int i = next; i != a; i = e[i])
			ans++;
		ans++;
	}
	v[a] = 2;
}
int main() {
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			scanf("%d", e + i);
		}

		for (int i = 1; i <= n; i++)
			if (!v[i]) {
				dfs(i);
			}
		cout << n-ans << endl;
		memset(e, 0, sizeof(e));
		memset(v, 0, sizeof(v));
	}
}