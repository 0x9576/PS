#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 170000000
using namespace std;
int d[3][802], a, b, c, N, E, v1, v2,ans;
vector<pair<int, int>> v[802];

void dijkstra(int s,int z) {
	priority_queue <pair<int, int>> pq;
	d[z][s] = 0;
	pq.push({ s,0 });
	int pq1, pq2, n, nd;
	while (!pq.empty()) {
		pq1 = pq.top().first;
		pq2 = -pq.top().second;
		pq.pop();
		if (d[z][pq1] < pq2)
			continue;
		for (int i = 0; i < v[pq1].size(); i++) {
			n = v[pq1].at(i).first;
			nd = pq2 + v[pq1].at(i).second;
			if (d[z][n] > nd) {
				d[z][n] = nd;
				pq.push({ n,-nd });
			}
		}
	}
}
int main() {
	for (int i = 0; i < 802; i++) {
		for(int j = 0; j<3; j++)
			d[j][i] = INF;
	}
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	dijkstra(1, 0);
	dijkstra(v1, 1);
	dijkstra(v2, 2);
	ans = min(d[0][v1] + d[1][v2] + d[2][N], d[0][v2] + d[2][v1] + d[1][N]);
	if (ans >= INF)
		cout << -1;
	else
		cout << ans;
}