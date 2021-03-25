#include <iostream>
using namespace std;
int T, dp[35][35],a,b;

int com(int b, int a) {
	if (b == a)
		return dp[b][a] = 1;
	if (a == 0)
		return dp[b][a] = 1;
	if (dp[b][a])
		return dp[b][a];
	return dp[b][a] = com(b - 1, a - 1) + com(b - 1, a);
}

int main() {
	cin >> T;
	while (T--) {
		com(35, 13);
		cin >> a >> b;
		cout<< com(b, a)<<endl; //bCa
	}
}