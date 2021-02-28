#include<iostream>
#include<algorithm>
using namespace std;
int N, k,l,h,ans,co,m;
int main() {
	cin >> N >> k;
	l = 1; h = k;
	while(l<=h){
		co = 0;
		m = (l + h) / 2;
		for (int i = 1; i <= N; i++)
			co += min(m / i, N);
		if (co < k)
			l = m + 1;
		else {
			ans = m;
			h = m - 1;
		}
	}
	cout << ans;
}