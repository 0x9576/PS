#include<iostream>
#include<cstring>
using namespace std;
int t,n;
char pn[12];
bool ans;

struct Trie {
	bool fin;
	Trie* node[10];
	Trie() {
		fin = 0;
		for (int i = 0; i < 10; i++)
			node[i] = 0;
	}
	bool ins(char* str) {
		if (!*str) {
			fin = 1;
			return 1;
		}
		if (fin) return 0;
		int cu = *str - '0';
		if (!node[cu]) node[cu] = new Trie();
		else if (node[cu] && !*(str + 1))
			return 0;
		return node[cu]->ins(str + 1);
	}
};

int main() {
	cin >> t;
	while (t--) {
		Trie* root = new Trie();
		cin >> n;
		ans = 1;
		while (n--) {
			scanf("%s", pn);
			if (!ans) continue;
			ans = root->ins(pn);
		}
		cout << (ans ? "YES" : "NO")<<endl;
	}
}