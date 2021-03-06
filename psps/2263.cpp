#include<iostream>
using namespace std;
int in[100001], post[100001],n,v[100001],inpos[100001];

void pre(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe)
		return;
	int root = post[pe];
	printf("%d ", root);
	int pr = inpos[root];
	pre(is, pr - 1, ps, ps + pr - is - 1);
	pre(pr + 1, ie, ps + pr-is, pe - 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", in + i);
	for (int i = 0; i < n; i++)
		scanf("%d", post + i);
	for (int i = 0; i < n; i++)
		inpos[in[i]] = i;
	pre(0, n - 1, 0, n - 1);
}