#include<iostream>
#include<queue>
using namespace std;
int city[1002], bus[1002][1002],busa;


int main() {
	int N, M, s, e, a, b, c;
	cin >> N >> M;
	for (int i = 0; i < 1002; i++)
		for (int j = 0; j < 1002; j++)
			bus[i][j] = -1;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		bus[a][b] = c;
	}

	for (int i = 0; i < 1002; i++)
		city[i] = 999999999;
	cin >> s >> e;

	city[s] = 0;

	priority_queue<pair<int, int>>pq;
	pq.push({ 0 , s });

	while (!pq.empty()) {
		a = pq.top().first * -1;
		b = pq.top().second;
		pq.pop();

		if (city[b] < a) continue;

		for (int i = 0; i<1002; i++) {
			if (bus[b][i]!=-1) {
				int nd = a + bus[b][i];

				if (nd < city[i]) {
					city[i] = nd;
					pq.push({ nd * -1 , i });
				}
			}
		}
	}
	cout << city[e];
}