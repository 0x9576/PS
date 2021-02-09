#include<iostream>
#include<math.h>
using namespace std;

void h(int n, int s, int d, int b) {
	if (n == 1) {
		printf("%d %d\n", s, d);
				return;
	}
	h(n - 1, s, b, d);
	printf("%d %d\n", s, d);
	h(n - 1, b, d, s);
}

int main() {
	int n;
	cin >> n;
	cout << ((int)pow(2, n) - 1) << endl;
	h(n, 1, 3, 2);
}