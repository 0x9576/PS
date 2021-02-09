#include<iostream>
using namespace std;
int ans[100000], s[83];
char q[83];
int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		scanf("%s", q);
		for (int i = 0; i < 83; i++) {
			if (q[i] == 'O')
				if (i == 0)
					s[i] = 1;
				else
					s[i] = s[i - 1] + 1;
			if (q[i] == 'X')
				s[i] = 0;
		}
		for (int i = 0; i < 83; i++) {
			ans[t] += s[i];
			s[i] = 0;
			q[i] = 0;
		}
	}
	for (int t = 0; t < T; t++)
		cout << ans[t] << endl;
}