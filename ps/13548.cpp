#include<iostream>
using namespace std;
int A[1000003];
int main() {
	long long N, B, C, ans;
	ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		ans++;
		if (A[i] < 1)
			continue;
		ans += A[i] / C;
		A[i] -= (A[i] / C) * C;
		if (A[i] > 0)
			ans++;
	}
	cout << ans;
}
