#include<iostream>
using namespace std;
char e[99];
int T,s;
int main() {
	cin >> T;
	while (T--) {
		s = 0;
		scanf("%s", e);
		for (int i = 0; e[i]; i++) {
			if (e[i] == '(')
				s++;
			if (e[i] == ')')
				s--;
			if (s < 0) {
				s = 1;
				break;
			}
		}
		if (s)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		for (int i = 0; i < 99; i++)
			e[i] = 0;
	}
}