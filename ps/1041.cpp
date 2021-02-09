#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	long long T;
	cin >> T;
	long long dice[6];
	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
	}
	long long f2 = 100;
	long long sum2 = 0;
	long long f3 = 150;
	long long sum3 = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 6; k++) {
				if (i != j && i + j != 5) {
					sum2 = dice[i] + dice[j];
					if (f2 > sum2) {
						f2 = sum2;
					}
					if (i != k && i + k != 5) {
						if (j != k && j + k != 5) {
							sum3 = dice[i] + dice[j] + dice[k];
							if (f3 > sum3) {
								f3 = sum3;
							}
						}
					}
				}
			}
		}
	}
	long long ans = 0;
	sort(dice, dice + 6);
	if (T == 1) {
		for (int i = 0; i < 5; i++) {
			ans += dice[i];
		}
		cout << ans;
	}
	long long p2 = 4 + 8 * (T - 2);
	long long p1 = 4 * (T - 2) * (T - 1) + (T - 2) * (T - 2);
	if (T >= 2) {
		ans = 4 * f3 + p2 * f2 + p1 * dice[0];
		cout << ans;
	}
	return 0;
}
