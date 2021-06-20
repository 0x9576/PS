#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int T, N, K, a, b, W;
	cin >> T;
	while (T--) {
		vector<int> edge[1005];
		queue<int> q;
		int con[1005] = { 0, }, level[1005] = { 0, }, ans[1005] = { 0, };
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			cin >> con[i];


		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			edge[a].push_back(b);
			level[b]++;
		}
		cin >> W;

		for (int i = 1; i <= N; i++)
			if (!level[i]) {
				q.push(i);
				ans[i] = con[i];
			}


		for (int i = 1; i <= N; i++) {
			int s = q.front();
			q.pop();

			for (int j = 0; j < edge[s].size(); j++) {
				int d = edge[s][j];
				ans[d] = max(ans[s] + con[d], ans[d]);
				if (!--level[d])
					q.push(d);
			}
		}
		cout << ans[W] << endl;
	}
}