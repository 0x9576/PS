#include<iostream>
using namespace std;
int N, n3, cn;

void r(int n) {
	n3 = n;
	int a = 10 * (n3 % 10) + (n3 % 10 + n3 / 10) % 10;
	cn++;
	if (N == a)
		return;
	r(a);
	return;
}

int main() {
	cin >> N;
	r(N);
	cout << cn;
}
