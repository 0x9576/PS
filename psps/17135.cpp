#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, D, f[20][20],o[20][20], tar[3][2],tr,tc,tsc,ans,tf[20][20];
vector <int> vec;

void pa(int a, int s) {
	vec.push_back(a);
	if (s == 3) {
		tsc = 0;
		while (1) {
			for (int k = 0; k < 3; k++) {
				tr = 99; tc = 99;
				for (int i = 1; i <= N; i++)
					for (int j = 1; j <= M; j++)
						if (f[i][j]) {
							int dis = abs(N + 1 - i) + abs(vec[k] - j);
							if (abs(N + 1 - tr) + abs(vec[k] - tc) > dis && dis<=D) {
								tr = i;
								tc = j;
							}
							if (abs(N + 1 - tr) + abs(vec[k] - tc) == abs(N + 1 - i) + abs(vec[k] - j) && j < tc && dis<=D) {
								tr = i;
								tc = j;
							}
						}
				if (tr == 99) {
					tr = 0;
					tc = 0;
				}
				tar[k][0] = tr;
				tar[k][1] = tc;
			}
			for (int k = 0; k < 3; k++) {
				if (tar[k][0]&& f[tar[k][0]][tar[k][1]]) {
					f[tar[k][0]][tar[k][1]] = 0;
					tsc++;
				}
			}
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= M; j++)
					if (i < N)
						tf[i + 1][j] = f[i][j];
			int en = 0;
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= M; j++) {
					f[i][j] = tf[i][j];
					if (f[i][j])
						en++;
					tf[i][j] = 0;
				}
			if (!en)
				break;
		}
		ans = max(ans, tsc);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				f[i][j] = o[i][j];
		return;
	}
	for (int i = a + 1; i <= M; i++) {
		pa(i, s + 1);
		vec.pop_back();
	}
}

int main() {
	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> f[i][j];
			o[i][j] = f[i][j];
		}

	for (int i = 1; i < M - 1; i++) {
		pa(i, 1);
		vec.pop_back();
	}
	cout << ans;
}