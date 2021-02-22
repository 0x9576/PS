#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int T, cons[1010], N, K, k1, k2, d, q1, dp[1010], nr[1010],si = sizeof(dp);

int main() {
	cin >> T;
	while (T--) {
		memset(dp, 0, si);
		memset(cons, 0, si);
		memset(nr, 0, si);
		vector<int> edge[1010];
		queue<int> q;
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
			scanf("%d", cons + i);
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &k1, &k2);
			edge[k1].push_back(k2);
			++nr[k2];
		}
		for (int i = 1; i <= N; i++)
			if (!nr[i]) {
				q.push(i);
				dp[i] = cons[i];
			}
		cin >> d;

		while (!q.empty()) {
			q1 = q.front();
			q.pop();
			if (q1 == d)
				break;
			for (int i = 0; i < edge[q1].size(); i++) {
				int nex = edge[q1][i];
				if (dp[nex] < dp[q1] + cons[nex])
					dp[nex] = dp[q1] + cons[nex];
				if (!--nr[nex])
					q.push(nex);
			}
		}
		cout << dp[d] << endl;
	}
}