#include<iostream>
using namespace std;
int st[1000];
int main() {
	int C, ansi;
	double N, E, G, ans;
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			scanf("%d", st + i);
		E = 0; G = 0;
		for (int i = 0; i < N; i++) {
			E += st[i];
		}
		E /= N;
		for (int i = 0; i < N; i++)
			if (E < st[i])
				G++;
		ans = 100 * G / N;
		ansi = 100 * G / N;
		
		if (ans == (int) ans)
			printf("%d.000", ansi);
		else
			printf("%.3lf", ans);
		puts("%");
	}
}
