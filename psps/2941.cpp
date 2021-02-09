#include<iostream>
using namespace std;
char w[105];
int co, si;
int main() {
	cin >> w;
	for (int i = 0; w[i] != 0; i++)
		si++;
	for (int i = 0; i < si; i++) {
		if (w[i] == 'c' && w[i + 1] == '=') {
			w[i] = 0; w[i + 1] = 0;
			co++;
		}
		if (w[i] == 'c' && w[i + 1] == '-') {
			w[i] = 0; w[i + 1] = 0;
			co++;
		}
		if (w[i] == 'd' && w[i + 1] == 'z' && w[i + 2] == '=') {
			w[i] = 0; w[i + 1] = 0; w[i + 2] = 0;
			co++;
		}
		if (w[i] == 'd' && w[i + 1] == '-') {
			w[i] = 0; w[i + 1] = 0;
			co++;
		}
		if (w[i] == 'l' && w[i + 1] == 'j') {
			w[i] = 0; w[i + 1] = 0;
			co++;
		}
		if (w[i] == 'n' && w[i + 1] == 'j') {
			w[i] = 0; w[i + 1] = 0;
			co++;
		}
		if (w[i] == 's' && w[i + 1] == '=') {
			w[i] = 0; w[i + 1] = 0;
			co++;
		}
		if (w[i] == 'z' && w[i + 1] == '=') {
			w[i] = 0; w[i + 1] = 0;
			co++;
		}
	}
	for (int i = 0; i < si; i++) {
		if (w[i] != 0)
			co++;
	}
	cout << co;
}