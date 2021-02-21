#include<iostream>
#include<algorithm>
using namespace std;
int n[1002], m[1002],mr[1002],N,ans;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", n + i);
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < i; j++)
			if (n[i] > n[j])
				m[i] = max(m[i],m[j] + 1);
	for (int i = N; i >= 0; i--)
		for (int j = N+1; j > i; j--)
			if (n[i] > n[j])
				mr[i] = max(mr[i], mr[j] + 1);
	for (int i = 1; i <= N; i++)
		ans = max(ans, m[i] + mr[i]);
	cout << ans-1;
}