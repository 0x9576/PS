#include<iostream>
#include<stack>
using namespace std;
int t[500001], ans[500001];
int main() {
	int N, st;
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", t + i);
	stack <pair<int,int>> s;
	s.push({ 1,t[1] });
	for (int i = 2; i <= N; i++) {
		while (!s.empty()) {
			if (s.top().second = t[i]) {
				ans[i] = s.top().first;
				break;
			}
			s.pop();
		}
		s.push({ i,t[i] });
	}
	for (int i = 1; i <= N; i++)
		printf("%d ", ans[i]);
}