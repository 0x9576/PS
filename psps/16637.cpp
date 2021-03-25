#include<iostream>
using namespace std;
int N,num[10],dp[10];
char op[9];
int main() {
	cin >> N;
	for (int i = 0; i < N; i+=2) {
		cin >> num[i];
		cin >> op[i/2];
		cin >> num[i + 1];
	}
}