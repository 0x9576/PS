#include<iostream>
char t[1000005];
int ans, sw;
int main() {
	scanf("%[^\n]", t);
	for (int i = 0; i < 1000005; i++) {
		if (t[i] != 0 &&t[i] != 32 && !sw) {
			sw = 1;
			ans++;
		}
		if (t[i] == 32 && sw) {
			sw = 0;
		}
	}
	printf("%d", ans);
}
