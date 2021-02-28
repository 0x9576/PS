#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, con[502], e, id[502], dp[502];
vector<int>v[502];
queue<int>q;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> con[i];
		while (1) {
			cin >> e;
			if (e == -1)
				break;
			v[e].push_back(i);
			id[i]++;
		}
	}
	for (int i = 1; i <= N; i++)
		if (!id[i]) {
			q.push(i);
			dp[i] = con[i];
		}
	while (!q.empty()) {
		int q1 = q.front();
		q.pop();
		for (int i = 0; i < v[q1].size(); i++) {
			int nex = v[q1][i];
			if (dp[nex] < dp[q1] + con[nex])
				dp[nex] = dp[q1] + con[nex];
			if (!--id[nex])
				q.push(nex);
		}
	}
	for (int i = 1; i <= N; i++)
		cout << dp[i] << endl;
}