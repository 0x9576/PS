#include<iostream>
#include<algorithm>
using namespace std;
int e[100004], N, S, l, h, s, ans = 999999;
int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++)
		scanf("%d", e + i);
	while (1) {
		if (h > N)
			break;
		if (S > s)
			s += e[++h];
		if (S <= s) {
			ans = min(ans, h - l);
			s -= e[++l];
		}
	}
	if (ans == 999999)
		cout << "0" << endl;
	else
		cout << ans;
}