#include<iostream>
#include<vector>
using namespace std;
int N, M, K,f[14][14];
int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", f[i] + j);
}