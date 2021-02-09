#include <iostream>
using namespace std;
int h[1001];

int main() {
	for (int i = 1; i < 111; i++) {
		h[i] = i;
		if (i > 99)
			h[i] = h[99];
	}
	int a, b, c;
	for (int i = 111; i < 1000; i++) {
		a = i / 100;
		b = i / 10 - a*10;
		c = i - a * 100 - b * 10;
		if (a + c == 2*b) {
			h[i] = h[i - 1] + 1;
		}
		else {
			h[i] = h[i - 1];
		}
	}
	h[1000] = h[999];

	int n;
	cin >> n;
	cout << h[n];
}