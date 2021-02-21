#include<iostream>
#include<stack>
#define M 1000005
using namespace std;
int N,n[M],ans[M];
stack <int> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> n[i];
	s.push(M);
	for (int i = N-1; i >= 0; i--) {
		while (1) {
			if (n[i] < s.top()) {
				ans[i] = s.top();
				s.push(n[i]);
				break;
			}
			s.pop();
		}
	}
	for (int i = 0; i < N; i++) {
		if (ans[i] != M)
			cout << ans[i] << " ";
		else
			cout << "-1 ";
	}
}