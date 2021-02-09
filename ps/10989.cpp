#include<iostream>
int e[10001];
int main() {
	int N, a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d",&a);
		e[a]++;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < e[i]; j++)
			printf("%d\n", i);
	}
}