#include <vector>

using namespace std;

int f[104][104][2];

bool is_stable() {
	for (int i = 0; i < 103; i++)
		for (int j = 0; j < 103; j++) {
			if (f[i][j][1] != 2 && i) {
				if (!j) {
					if (f[i - 1][j + 1][0] == 2 && f[i - 1][j][0] == 2)
						return 0;
				}
				else if (f[i - 1][j + 1][0] == 2 && f[i - 1][j][0] == 2 && (f[i][j - 1][1] == 2 || f[i][j + 1][1] == 2))
					return 0;
			}
			if (f[i][j][0] != 2 && i) {
				if (j) {
					if (f[i][j][1] == 2 && f[i][j - 1][1] == 2 && f[i - 1][j][0] == 2)
						return 0;
				}
				else {
					if (f[i][j][1] == 2 && f[i - 1][j][0] == 2)
						return 0;
				}
			}
		}
	return 1;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	for (int i = 0; i < 104; i++)
		for (int j = 0; j < 104; j++) {
			f[i][j][0] = 2;
			f[i][j][1] = 2;
		}


	int x, y, con, st, tem0,tem1;

	for (vector<int> v : build_frame) {
		x = v[0];
		y = v[1];
		st = v[2];
		con = v[3];
		tem1 = f[y][x][1];
		tem0 = f[y][x][0];
		if (con) {
			if (st == 1)
				f[y][x][1] = 1;
			if (st == 0)
				f[y][x][0] = 0;
		}
		else {
			if (f[y][x][1] == 1 && st == 1)
				f[y][x][1] = 2;
			if (f[y][x][0] == 0 && st == 0)
				f[y][x][0] = 2;
		}
		if (!is_stable()) {
			f[y][x][1] = tem1;
			f[y][x][0] = tem0;
		}
	}

	for (int x = 0; x < 104; x++)
		for (int y = 0; y < 104; y++)
			for (int j = 0; j <= 1; j++)
				if (f[y][x][j] != 2) {
					vector<int> ans;
					ans.push_back(x);
					ans.push_back(y);
					ans.push_back(f[y][x][j]);
					answer.push_back(ans);
				}

	return answer;
}
