#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,a,b,c,ch[100001],co,cost;
vector <pair<int,pair<int, int>>> v;
int find(int n) {
	if (ch[n] == n) return n;
	return find(ch[n]);
}

void uni(int n1,int n2) {
	n1 = find(n1);
	n2 = find(n2);
	if (n1 < n2) ch[n2] = n1;
	else ch[n1] = n2;
}

bool same(int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return true;
	else return false;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v.push_back({ c,{ a,b } });
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++)
		ch[i] = i;
	for (int i = 0; i < v.size(); i++) {
		int n1 = v[i].second.first;
		int n2 = v[i].second.second;
		if (!same(n1, n2)) {
			co = v[i].first;
			cost += co;
			uni(n1, n2);
		}

	}
	cout << cost-co;
}