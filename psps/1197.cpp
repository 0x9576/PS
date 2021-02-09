#include<iostream>
#include<vector>
#include<algorithm>
#define M 10005
using namespace std;
int p[M], V, E, e1, e2, e3,ans;

class Node {
public:
	int n1;
	int n2;
	int n3;
	Node(int a1, int a2, int a3) {
		n1 = a1; n2 = a2; n3 = a3;
	}
};

bool cmp(Node N1, Node N2) {
	return N1.n3 < N2.n3;
}

int fp(int x) {
	if (x == p[x])
		return x;
	else
		return p[x] = fp(p[x]);
}

int main() {
	vector <Node> v;
	cin >> V >> E;
	for (int i = 1; i <= V; i++)
		p[i] = i;
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &e1, &e2, &e3);
		v.push_back(Node(e1, e2, e3));
	}
	int x, y;
	sort(v.begin(),v.end(),cmp);
	for (int i = 0; i < E; i++) {
		x = fp(v.at(i).n1);
		y = fp(v.at(i).n2);
		if (x != y) {
			p[y] = x;
			ans += v.at(i).n3;
		}
	}
	cout << ans;
}