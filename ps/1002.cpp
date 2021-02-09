#include <iostream>
#include <cmath>

using namespace std;
bool contain;

int main() {
	int T;
	int ans[10000] = { 0,0 };
	cin >> T;

	for (int i = 0; i < T; i++) {
		float x1; float y1; float r1;
		float x2; float y2; float r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		float dism = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		float r = r1 + r2;
		float dis = sqrt(dism);

		float rl; float rs;
		if (r1 > r2) {
			rl = r1;
			rs = r2;
		}
		else {
			rl = r2;
			rs = r1;
		}

		if (rl > dis) {
			if (rl-rs == dis) {
				ans[i] = 1;
			}
			else if (rl-rs > dis) {
				ans[i] = 0;
			}
			else if (rl-rs < dis) {
				ans[i] = 2;
			}
		}
		else {
			if (r == dis) {
				ans[i] = 1;
			}
			else if (r < dis) {
				ans[i] = 0;
			}
			else if (r > dis) {
				ans[i] = 2;
			}
		}
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			ans[i] = -1;
		}
	}

	for (int i = 0; i < T; i++) {
		cout << ans[i] << endl;
	}

	return 0;

}