#include<iostream>
using namespace std;
int a, e[4][2];
int main() {
	for (int i = 1; i < 4; i++)
		cin >> e[i][0] >> e[i][1];
	a = (e[2][0] - e[1][0]) * (e[3][1] - e[1][1]) - (e[2][1] - e[1][1]) * (e[3][0] - e[1][0]);
	if (a > 0)
		cout << 1;
	else if (a < 0)
		cout << -1;
	else
		cout << 0;
}