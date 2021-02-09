#include<iostream>
using namespace std;
int main() {
	int n, m, a = 1;
	cin >> n >> m;
	for (int i = 1; i < 10003; i++) {
		if (n % i == 0 && m % i == 0)
			a = i;
		if (i > m && i > n) {
			cout << a << " " << n * m / a;
			exit(0);
		}
	}
}