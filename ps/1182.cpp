#include<iostream>
using namespace std;
int N, S, n[20], ans;

void bt(int a,int s,int p) {
	if (s == S) {
		ans++;
	}
	if (p == N)
		return;
	for (int i = a + 1; i < N; i++)
		bt(i,s+n[i],p+1);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> n[i];
	for (int i = 0; i < N; i++)
		bt(i, n[i],1);
	cout << ans;
}