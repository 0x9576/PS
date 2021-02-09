#include<iostream>
#include<algorithm>
using namespace std;
int A[100005], B[100005], N, M;

int BS(int t) {
	int l = 0, r = N - 1, m;
	while (l <= r) {
		m = (l + r) / 2;
		if (A[m] == t) {
			return 1;
		}
		else if (A[m] > t)
			r = m - 1;
		else
			l = m + 1;
	}
	return 0;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d",A + i);
	cin >> M;
	for (int i = 0; i < M; i++)
		scanf("%d", B + i);
	sort(A, A + N);
	for (int i = 0; i < M; i++) {
		printf("%d\n", BS(B[i]));
	}
}