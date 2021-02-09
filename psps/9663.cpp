#include<iostream>
using namespace std;
int f[15];
int N, ans;
bool ch(int i) {
	for (int j = 0; j < i; j++) {
		if(f[i]==f[j]||abs(f[i]-f[j])==i-j)
			return false;
	}
	return true;
}

void Q(int i) {
	if (i == N)
		ans++;
	else {
		for (int j = 0; j < N; j++) {
			f[i] = j;
			if (ch(i))
				Q(i + 1);
		}
	}
}

int main() {
	cin >> N;
	Q(0);
	cout << ans;
}