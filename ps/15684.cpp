#include<iostream>
#include<algorithm>
using namespace std;
int N, M, H, e1, e2, ans = 4;
bool ch[12][32];

bool is_cor() {
	for (int i = 1; i <= N; i++) {
		int cl = i, h = 1;
		while (true) {
			if (ch[cl][h])
				cl++;
			else if (ch[cl - 1][h])
				cl--;
			if (h == H) {
				if (cl != i)
					return false;
				break;
			}
			h++;
		}
	}
	return true;
}

void dfs(int a, int b, int s) {
	if (s > 3)
		return;
	if (is_cor())
		ans = min(ans, s);
	if (s < 3) {
		for (int i = a-1; i < N; i++)
			for (int j = b-1; j <= H; j++)
				if (!ch[i][j] && !ch[i + 1][j] && !ch[i - 1][j]) {
					ch[i][j] = true;
					dfs(i, j, s + 1);
					ch[i][j] = false;
				}
	}
}

int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> e1 >> e2;
		ch[e2][e1] = true;
	}
	dfs(1, 1, 0);
	if (ans == 4)
		ans = -1;
	cout << ans;
}