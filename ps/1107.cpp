#include<iostream>
#include<algorithm>
using namespace std;
int remo[10];
int N, M, m, ans, p, len, num, cou;

bool possi(int n) {
	num = n;
	int cou;
	len = 0;
	if (n == 0) {
		if (remo[0] == -1)
			return false;
		len++;
	}

	else {
		while (num != 0) {
			cou = 0;
			p = num % 10;
			for (int i = 0; i < 10; i++) {
				if (p == remo[i])
					cou++;
			}
			num /= 10;
			len++;
			if (cou == 0)
				return false;
		}
	}
	return true;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < 10; i++)
		remo[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> m;
		remo[m] = -1;
	}
	ans = abs(N - 100);
	for (int i = 0; i < 1000000; i++) {
		if (possi(i))
			ans = min(ans, abs(N - i)+len);
	}
	cout << ans;
}