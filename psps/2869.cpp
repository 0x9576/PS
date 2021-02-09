#include<iostream>
using namespace std;
int main() {
	long long A, B, V, ans, left = 1, right = 1000000000, mid;
	cin >> A >> B >> V;
	while (left <= right) {
		mid = (left + right) / 2;
		if ((A - B) * (mid - 1) + A >= V) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans;
}