#include<iostream>
#include<vector>
using namespace std;
int N,x,y,d,g,f[102][102],di,ans,vecs;
vector<int>v;

void cur() {
	for (int i = vecs; i >= 0; i--) {
		di = v.at(i);
		di++;
		if (di == 4)
			di = 0;
		if (di == 0)
			f[y][++x] = 1;
		if (di == 1)
			f[--y][x] = 1;
		if (di == 2)
			f[y][--x] = 1;
		if (di == 3)
			f[++y][x] = 1;
		v.push_back(di);
	}
}

int main() {
	cin >> N;
	while (N--) {
		cin >> x >> y >> d >> g;
		f[y][x] = 1;
		v.push_back(d);
		if (d == 0)
			f[y][++x] = 1;
		if (d == 1)
			f[--y][x] = 1;
		if (d == 2)
			f[y][--x] = 1;
		if (d == 3)
			f[++y][x] = 1;
		for (int i = 1; i <= g; i++) {
			vecs = v.size()-1;
			cur();
		}
		v.clear();
	}
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (f[i][j] && f[i + 1][j] && f[i][j+1] && f[i + 1][j + 1])
				ans++;
	cout << ans;
}
