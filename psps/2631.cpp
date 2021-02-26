#include<iostream>
#include<algorithm>
#define M 211
using namespace std;
int dp[M],e[M],N,tem,a;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", e + i);
	for (int i = 1; i <= N; i++) {
		tem = 0;
		for (int j = 1; j < i; j++) {
			if (e[j] < e[i])
				tem = max(dp[j], tem);
		}
		dp[i] = tem + 1;
		a = max(dp[i], a);
	}
	cout << N - a;
}