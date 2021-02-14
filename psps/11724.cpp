#include<iostream>
#include<vector>
using namespace std;
int N, M,e1,e2,ans;
bool v[10001];
vector<int> vec[10001];

void dfs(int a) {
	v[a] = 1;
	for (int i = 0; i < vec[a].size(); i++)
		if (!v[vec[a][i]])
			dfs(vec[a][i]);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d %d",&e1,&e2);
		vec[e1].push_back(e2);
		vec[e2].push_back(e1);
	}
	for (int i = 1; i <= N; i++)
		if (!v[i]) {
			dfs(i);
			ans++;
		}
	cout << ans;
}