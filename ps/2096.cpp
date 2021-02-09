#include<iostream>
#include<algorithm>
using namespace std;
int  en[3], N, dp1[2][3], dp2[2][3];
int main() {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		if (i < N)
			scanf("%d %d %d", en + 0, en + 1, en + 2);
		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				dp1[0][j] = en[j];
				dp2[0][j] = en[j];
			}
		}
		if (i > 0 && i<N) {
			dp1[i % 2][0] = max(dp1[(i - 1) % 2][0], dp1[(i - 1) % 2][1]) + en[0];
			dp1[i % 2][1] = max(dp1[(i - 1) % 2][0], max(dp1[(i - 1) % 2][1], dp1[(i - 1) % 2][2])) + en[1];
			dp1[i % 2][2] = max(dp1[(i - 1) % 2][1], dp1[(i - 1) % 2][2]) + en[2];
			dp2[i % 2][0] = min(dp2[(i - 1) % 2][0], dp2[(i - 1) % 2][1]) + en[0];
			dp2[i % 2][1] = min(dp2[(i - 1) % 2][0], min(dp2[(i - 1) % 2][1], dp2[(i - 1) % 2][2])) + en[1];
			dp2[i % 2][2] = min(dp2[(i - 1) % 2][1], dp2[(i - 1) % 2][2]) + en[2];
		}
		if (i == N) {
			dp1[i % 2][1] = max(dp1[(i - 1) % 2][0], max(dp1[(i - 1) % 2][1], dp1[(i - 1) % 2][2]));
			dp2[i % 2][1] = min(dp2[(i - 1) % 2][0], min(dp2[(i - 1) % 2][1], dp2[(i - 1) % 2][2]));
		}
	}
	cout << dp1[N%2][1] << " " << dp2[N%2][1];
}