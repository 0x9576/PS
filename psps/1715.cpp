#include<iostream>
#include<queue>
using namespace std;
int N,n,tq,ans;
priority_queue <int> pq;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		pq.push(-n);
	}
	while(!pq.empty()) {
		if (!tq) {
			tq = -pq.top();
			ans += tq;
			pq.pop();
		}
		else {
			tq -= pq.top();
			ans -= pq.top();
			pq.pop();
			pq.push(-tq);
			tq = 0;
		}
	}
	ans -= tq;
	if (N == 1)
		ans = 0;
	cout << ans;
}