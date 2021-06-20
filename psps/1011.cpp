#include<iostream>
#include<queue>
using namespace std;
int main() {
	int T, x, y, ac = 1,ans = 0;
	cin >> T;
	while (T--) {
		cin >> x >> y;
		while (y-x>ac*2) {
			x += ac;
			y -= ac;
			ac++;
			ans+=2;
		}
		if (x > y)
			ans--;
		cout << ans << endl;
	}
}