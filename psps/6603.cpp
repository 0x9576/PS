#include<iostream>
#include<cstring>
using namespace std;
int S[14],k,O[6];

void com(int a,int s) {
	O[s] = S[a];
	if (s == 5) {
		for (int i = 0; i < 6; i++)
			printf("%d ", O[i]);
		puts("");
	}
	if (s < 5) {
		for (int i = a + 1; S[i]; i++)
			com(i, s + 1);
	}
}

int main() {
	while (1) {
		memset(S, 0, sizeof(S));
		memset(O, 0, sizeof(O));
		cin >> k;
		if (!k)
			break;
		for (int i = 0; i < k; i++)
			scanf("%d",S + i);
		for (int i = 0; i <= k-6; i++) {
			com(i, 0);
		}
		puts("");
	}
}