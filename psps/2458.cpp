#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector <int> lar[502];
vector <int> smal[502];
int N, M,l,s,ans;
bool v[502];
void lar_dfs(int a) {
	for (int i = 0; i<lar[a].size(); i++) {
		int nex = lar[a][i];
		if (!v[nex]) {
			v[nex] = 1;
			lar_dfs(nex);
		}
	}
}

void smal_dfs(int a) {
	for (int i = 0; i<smal[a].size(); i++) {
		int nex = smal[a][i];
		if (!v[nex]) {
			v[nex] = 1;
			smal_dfs(nex);
		}
	}
}

bool ch() {
	for (int i = 1; i <= N; i++)
		if (!v[i])
			return 0;
	return 1;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &l, &s);
		lar[s].push_back(l);
		smal[l].push_back(s);
	}
	for (int i = 1; i <= N; i++) {
		memset(v, 0, 502 * sizeof(bool));
		v[i] = 1;
		lar_dfs(i);
		smal_dfs(i);
		if (ch())
			ans++;
	}
	cout << ans;
}