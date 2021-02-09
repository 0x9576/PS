#include<iostream>
using namespace std;
int main() {
	int N, n, t, f, ans;
	cin >> N;
	t = 0;
	while (true) {
		n = N;
		n -= t * 3;
		if (n<0) {
			ans = -1;
			break;
		}
		if (n % 5 == 0) {
			f = n / 5;
			ans = f + t;
			break;
		}
		t++;
	}
	cout << ans;
}