#include<iostream>
#include<vector>
#include<algorithm>
int ans, N, e, zn;
using namespace std;
vector<int> pv;
vector<int> mv;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &e);
		if (e < 0)
			mv.push_back(e);
		if (e > 1)
			pv.push_back(e);
		if (e == 1)
			ans++;
		if (e == 0)
			zn++;
	}
	sort(pv.begin(), pv.end());
	sort(mv.begin(), mv.end());
	if (pv.size() == 1) {
		ans += pv[0];
	}
	else if (pv.size())
		if (pv.size() % 2) {//È¦¼öÀÎ °æ¿ì
			for (int i = pv.size() - 2; i >0 ; i-=2)
				ans += pv[i] * pv[i + 1];
			ans += pv[0];
		}
		else
			for (int i = pv.size() - 2; i >=0 ; i-=2)
				ans += pv[i] * pv[i + 1];

	if (mv.size() == 1) {
		ans += mv[0];
	}
	else if (mv.size())
		if (mv.size() % 2) {//È¦¼öÀÎ °æ¿ì
			for (int i = 0; i < mv.size() - 2; i+=2)
				ans += mv[i] * mv[i + 1];
			if (!zn)
				ans += mv[mv.size() - 1];
		}
		else
			for (int i = 0; i < mv.size() - 1; i+=2)
				ans += mv[i] * mv[i + 1];

	cout << ans;
}