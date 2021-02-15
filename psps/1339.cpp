#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int N,slen,ans,alp[26];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin >> N;
	while (N--) {
		char s[10];
		scanf("%s", s);
		slen = strlen(s);
		for (int i = 0; i < slen; i++)
			alp[s[i] - 65] += (int)pow(10, slen - i-1);
	}
	sort(alp,alp+26,cmp);
	for (int i = 0; i < 10; i++)
		ans += alp[i] * (9 - i);
	cout << ans;
}