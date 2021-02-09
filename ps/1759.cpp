#include<iostream>
#include<algorithm>
using namespace std;
int L, C;
char e[17];
char t[17];
int co;
void p(int a,int s) {
	t[s] = e[a];
	if (s == L - 1) {
		co = 0;
		for (int i = 0; t[i]; i++) {
			if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u') {
				co++;
			}
		}
		if (co > 0&& co<L-1) {
			for (int j = 0; t[j]; j++)
				printf("%c", t[j]);
			puts("");
		}
		return;
	}
	for (int i = a+1; i < C; i++) {
		p(i, s + 1);
	}
}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> e[i];
	}
	sort(e,e+C);
	for (int i = 0; i < C - L+1; i++)
		p(i, 0);
	return 0;
}