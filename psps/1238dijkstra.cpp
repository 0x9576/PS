#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 9010000
using namespace std;
int N, M, X, a, b, c, dp1[1005], dp2[1005], ans;
vector<pair<int,int>> edge1[1005];
vector<pair<int,int>> edge2[1005];
int main() {
	cin >> N >> M >> X;
	for (int i = 1; i <= N; i++) {
		dp1[i] = INF;
		dp2[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		edge1[a].push_back({ b,c });
		edge2[b].push_back({ a,c });
	}
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,X });
	dp1[X] = 0;
	while (!pq.empty()) {
		int q1 = -pq.top().first;
		int q2 = pq.top().second;
		pq.pop();
		if (dp1[q2] < q1) continue;
		for (int i = 0; i < edge1[q2].size(); i++) {
			int next =  edge1[q2][i].first;
			int ndis = q1 + edge1[q2][i].second;
			if (ndis < dp1[next]) {
				dp1[next] = ndis;
				pq.push({ -ndis,next });
			}
		}
	}
	priority_queue <pair<int, int>> pq2;
	pq2.push({ 0,X });
	dp2[X] = 0;
	while (!pq2.empty()) {
		int q1 = -pq2.top().first;
		int q2 = pq2.top().second;
		pq2.pop();
		if (dp2[q2] < q1) continue;
		for (int i = 0; i < edge2[q2].size(); i++) {
			int next = edge2[q2][i].first;
			int ndis = q1 + edge2[q2][i].second;
			if (ndis < dp2[next]) {
				dp2[next] = ndis;
				pq2.push({ -ndis,next });
			}
		}
	}
	for (int i = 1; i <= N; i++)
		ans = max(ans, dp1[i] + dp2[i]);

	cout << ans;
}