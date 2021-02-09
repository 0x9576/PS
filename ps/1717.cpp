#include<iostream>
int p[1000001], n, m, e, a, b;
int f(int a) {
	if (a == p[a])
		return a;
	else
		return p[a] = f(p[a]);
}
int main() {
	std::cin >> n >> m;
	for (int i = 0; i <= n; i++)
		p[i] = i;
	while (m--) {
		scanf("%d %d %d", &e, &a, &b);
		if (e) {
			if (f(a) == f(b))
				puts("YES");
			else
				puts("NO");
		}
		else
			p[f(a)] = f(b);
	}
}
