#include<iostream>
#include<vector>
using namespace std;
int K, V, E, e1, e2, v[20003], edge;
vector<int> vec[20003];

void dfs(int a, int cn) {
	//cout <<":"<< a << " " << cn << endl;
	if (cn == 3)
		cn = 1;
	v[a] = cn;
	for (int i = 0; i < vec[a].size(); i++) {
		edge = vec[a].at(i);
		if (!v[edge]) {
			dfs(edge,cn+1);
		}
	}
}

bool che() {
	for (int a = 1; a <= V; a++)
		for (int i = 0; i < vec[a].size(); i++) {
			edge = vec[a].at(i);
			if (v[a]==v[edge])
				return 0;
		}
	return 1;
}

int main() {
	cin >> K;
	while (K--) {
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &e1, &e2);
			vec[e1].push_back(e2);
			vec[e2].push_back(e1);
		}
		for (int i = 1; i <= V; i++)
			if (!v[i])
				dfs(i,1);
		if (che())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		for (int i = 0; i < 20003; i++) {
			v[i] = 0;
			vec[i].clear();
		}
	}
}