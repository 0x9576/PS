#include<iostream>
using namespace std;
short arr[90], N;

bool ch(int l) {
	for (int i = 2; i <= l / 2; i++)
		for (int j = 0; j <= l-2*i; j++) {
			int cn = 0;
			for (int k = 0; k < i; k++)
				if (arr[j + k] == arr[j + i + k])
					cn++;
			if (cn == i)
				return false;
		}
	return true;
}

void dfs(int a, int l) {
	if (ch(l + 1)) {
		if (l == N-1) {
			for (int i = 0; i < N; i++)
				printf("%d", arr[i]);
			exit(0);
		}
		for (int i = 1; i < 4; i++)
			if (a != i) {
				arr[l + 1] = i;
				dfs(i, l + 1);
			}
	}
	return;
}

int main() {
	cin >> N;
	arr[0] = 1;
	dfs(1, 0);
}