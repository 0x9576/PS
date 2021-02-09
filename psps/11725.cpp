#include<iostream>
#include<vector>
using namespace std;
int N,a,b,p[100001];
vector <int> vec[100001];
bool v[100001];

void dfs(int r, int n) {
	v[r] = 1;
	p[r] = n;
	for (int i = 0; i < vec[r].size(); i++)
		if(!v[vec[r].at(i)])
			dfs(vec[r].at(i), r);
}

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	v[1] = 1;
	dfs(1, 1);
	for (int i = 2; i <= N; i++)
		printf("%d\n", p[i]);
}