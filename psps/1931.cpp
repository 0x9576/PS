#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int>& v1,pair<int, int>& v2) {
	if (v1.second == v2.second)
		return v1.first < v2.first;
	return v1.second < v2.second;
}

int main() {
	int N;
	cin >> N;
	vector < pair<int, int>>v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), cmp);

	int count = 0;
	int a = -1;

	for (int i = 0; i < N; i++) {
		if (a <= v[i].first) {
			a = v[i].second;
			count++;
		}
	}

	cout << count;

	return 0;
}