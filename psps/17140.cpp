#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int r, c, k, f[101][101],ans,rc,cc,co[101],vsi;
vector<pair<int, int>> v;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%d", f[i] + j);
	while (1) {
		rc = 0;
		cc = 0;
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++) {
				if (f[i][j])
					rc = max(rc, i);
				if (f[j][i])
					cc = max(cc, i);
			}
		if (f[r][c] == k)
			break;
		if (ans == 101)
			break;

		if (rc >= cc) {
			for (int i = 1; i <= rc; i++) {
				v.clear();
				memset(co, 0, sizeof(co));
				for (int j = 1; j <= cc; j++) {
					co[f[i][j]]++;
					f[i][j] = 0;
				}
				for (int j = 1; j <= 100; j++)
					if (co[j])
						v.push_back({ j,co[j] });
				sort(v.begin(), v.end(), cmp);
				vsi = v.size();
				if (vsi > 50)
					vsi = 50;
				for (int j = 0; j < vsi; j++) {
					int v1 = v[j].first;
					int v2 = v[j].second;
					f[i][2*j + 1] = v1;
					f[i][2*j + 2] = v2;
				}
			}
		}
		else {
			for (int i = 1; i <= cc; i++) {
				v.clear();
				memset(co, 0, sizeof(co));
				for (int j = 1; j <= rc; j++) {
					co[f[j][i]]++;
					f[j][i] = 0;
				}
				for (int j = 1; j <= 100; j++)
					if (co[j])
						v.push_back({ j,co[j] });
				sort(v.begin(), v.end(), cmp);
				vsi = v.size();
				if (vsi > 50)
					vsi = 50;
				for (int j = 0; j < vsi; j++) {
					int v1 = v[j].first;
					int v2 = v[j].second;
					f[2 * j + 1][i] = v1;
					f[2 * j + 2][i] = v2;
				}
			}
		}
		ans++;
	}
	if (ans > 100)
		cout << "-1";
	else
		cout << ans;
}