#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, K, ans, arr[1000000] = { 0, };
char w[18][51];
bool ex[50], ch[999];
vector<short>v;

bool readable(int i) {
	for (int j = 0; ; j++) {
		if (!w[i][j])
			break;
		//cout << w[i][j];
		if (!ch[w[i][j] - 'a'])
			return 0;
	}
	//cout << endl;
	return 1;
}

void dfs(int s, int k) {
	if (k == K) {
		/*for (int i = 0; i < 50; i++)
			if (ch[i])
				cout << (char)(i + 'a') << " ";*/
		int st = 0;
		for (int i = 0; i < N; i++)
			if (readable(i)) {
				//cout << "true";
				st++;
			}
		//cout << st << endl;
		ans = max(ans, st);
		return;
	}
	for (int i = s + 1; i < v.size(); i++) {
		int in = v[i];
		ch[in] = 1;
		dfs(i, k + 1);
		ch[in] = 0;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		scanf("%s", w[i]);
		for (int j = 0; w[i][j]; j++) {
			char e = w[i][j];
			if (e != 'a' && e != 'n' && e != 't' && e != 'i' && e != 'c')
				ex[e - 'a'] = 1;
		}
	}
	int alp = 0;
	for (int i = 0; i < 50; i++)
		if (ex[i]) {
			alp++;
			v.push_back(i);
		}
	if (alp + 5 <= K) {
		cout << N;
		exit(0);
	}
	ch['a' - 'a'] = 1;
	ch['n' - 'a'] = 1;
	ch['t' - 'a'] = 1;
	ch['i' - 'a'] = 1;
	ch['c' - 'a'] = 1;
	for (int i = 0; i < v.size(); i++) {
		//cout << v[i] << " ";
		int in = v[i];
		ch[in] = 1;
		dfs(i, 6);
		ch[in] = 0;
	}
	cout << ans;
}