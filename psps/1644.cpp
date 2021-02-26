#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool dp[4000001];
int N, ans;
vector <int> p;
queue <pair<int, int>> q;
int main() {
	cin >> N;
	for (int i = 2; i < 4000001; i++)
		if (!dp[i]) {
			for (int j = i * 2; j < 4000001; j += i)
				dp[j] = 1;
		}
	for (int i = 2; i < 4000001; i++)
		if (!dp[i])
			p.push_back(i);
	for (int i = 0; i < p.size(); i++)
		q.push({ p[i],i });
	while (!q.empty()) {
		int q1 = q.front().first;
		int q2 = q.front().second;
		q.pop();
		if (N == q1)
			ans++;
		else if(q2+1<p.size())
			if (q1 + p[q2 + 1] <= N)
				q.push({ q1 + p[q2 + 1],q2 + 1 });
	}
	cout << ans;
}