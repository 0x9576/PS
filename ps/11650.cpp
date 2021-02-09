#include<iostream>
#include<vector>
#include<algorithm>
#define P pair<int,int>
using namespace std;
bool cmp(P p1, P p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	else
		return p1.first < p2.first;
}
int main() {
	vector<P>v;
	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++)
		printf("%d %d\n", v.at(i).first, v.at(i).second);
}