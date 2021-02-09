#include<iostream>
using namespace std;
char w[104], s[104], o[104];
int ans, N, co, fc;

void wf() {
	for (int i = 1; w[i]; i++) {
		if (w[i - 1] != w[i])
			s[co++] = w[i - 1];
		for (int j = 0; s[j]; j++)
			if (w[i] == s[j])
				return;
	}
	fc++;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%s", w);
		wf();
		co = 0;
		for (int j = 0; j < 104; j++) {
			s[j] = o[j];
			w[j] = o[j];
		}
	}
	cout << fc;
}