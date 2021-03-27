#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rot(vector<vector<int>>& key) {
	vector<vector<int>> newkey;
	vector<int>nv;
	for (int i = 0; i < key.size(); i++) {
		for (int j = key.size() - 1; j >= 0; j--)
			nv.push_back(key[j][i]);
		newkey.push_back(nv);
		nv.clear();
	}
	return newkey;
}

bool ch(vector<vector<int>>& tl) {
	for (int i = 0; i < tl.size(); i++)
		for (int j = 0; j < tl.size(); j++) {
			if (!tl[i][j])
				return 0;
		}
	return 1;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int ks = key.size();
	int ls = lock.size();
	int ro = 5;
	bool flag;

	while (ro--) {
		key = rot(key);
		for (int i = -ks; i <= ls + ks; i++)
			for (int j = -ks; j <= ls + ks; j++) {
				vector<vector<int>> tl = lock;
				flag = 1;
				for (int ki = 0; ki < ks; ki++)
					for (int kj = 0; kj < ks; kj++) {
						if (i + ki >= 0 && j + kj >= 0 && j + kj < ls && i + ki < ls) {
							if (key[ki][kj] == 1 && lock[i + ki][j + kj] == 1)
								flag = 0;
							if (key[ki][kj] == 1 && lock[i + ki][j + kj] == 0)
								tl[i + ki][j + kj] = 1;
						}
					}
				if (flag)
					if (ch(tl))
						return 1;
			}
	}
	return 0;
}