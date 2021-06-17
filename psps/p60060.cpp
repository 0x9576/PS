#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int ans;
string tem;
int stlen;

struct Trie {
	bool fin;
	Trie* node[26];
	int co[26];
	Trie() {
		fin = 0;
		memset(node, 0, sizeof(node));
		memset(co, 0, sizeof(co));
	}

	void insert(int s) {
		if (!tem[s]) {
			fin = true;
			return;
		}
		int alpha = tem[s] - 'a';
		if (!node[alpha])
			node[alpha] = new Trie();
		co[alpha]++;
		node[alpha]->insert(s + 1);
	}

	void exist(int s) {
		if (fin && !tem[s]) {
			ans++;
			return;
		}
		/*if (fin)
			return;*/
		if (!tem[s])
			return;
		if (tem[s] != '?') {
			int alpha = tem[s] - 'a';
			if (!node[alpha])
				return;
			node[alpha]->exist(s + 1);
		}
		else
			for (int i = 0; i < 26; i++)
				if (node[i])
					ans += co[i];
	}
};

vector<int> solution(vector <string> words, vector<string> queries) {
	Trie* root[10010];
	Trie* r_root[10010];

	for (int i = 0; i < 10010; i++) {
		root[i] = new Trie();
		r_root[i] = new Trie();
	}
	vector<int> answer;
	int len;
	for (auto s : words) {
		tem = s;
		len = s.length();

		root[len]->insert(0);
		tem.clear();
		for (int i = s.length() - 1; i >= 0; i--)
			tem += s[i];
		r_root[len]->insert(0);
	}

	for (auto s : queries) {
		ans = 0;
		tem = s;
		len = s.length();
		if (s[0] != '?')
			root[len]->exist(0);
		else {
			tem.clear();
			for (int i = s.length() - 1; i >= 0; i--)
				tem += s[i];
			r_root[len]->exist(0);
		}
		answer.push_back(ans);
	}
	return answer;
}