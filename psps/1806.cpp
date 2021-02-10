#include<iostream>
using namespace std;
int e[100000],N,S,l,r,s;
int main() {
	cin >> N>>S;
	for (int i = 0; i < N; i++)
		scanf("%d",e + i);
	while (1) {
		if (S > s)
			s += e[r++];
	}
}