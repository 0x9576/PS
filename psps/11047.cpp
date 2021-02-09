#include<iostream>
using namespace std;
int m[12];
int main() {
	int N, K, c;
	c = 0;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> m[i];
	while (K!=0) {
		for (int i = N; i > 0; i--) {
			if (m[i] <= K) {
				K -= m[i]; c++; break;
			}
		}
	}
	cout << c;
	return 0;
}