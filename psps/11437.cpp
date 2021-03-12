#include<iostream>
#include<vector>
using namespace std;
vector<int> edge[50001];
int N, a, b, M,d[50001],p[50001];

void dfs(int a, int s) {
	d[a] = s;
	for (int nex : edge[a]) {
		if (!d[nex]) {
			p[nex] = a;
			dfs(nex, s + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1, 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (d[a] > d[b]) {
			while (d[a] != d[b])
				a = p[a];
		}
		else
			while (d[a] != d[b])
				b = p[b];
		while (a != b) {
			a = p[a];
			b = p[b];
		}
		cout << a << "\n";
	}
}