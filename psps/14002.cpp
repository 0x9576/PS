#include<iostream>
#include<vector>
using namespace std;

int arr[1005], p[1005], ma, N,mav,tv;
vector<int>vec[1005];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (arr[i] > arr[j])
				if (p[i] < p[j] + 1) {
					p[i] = p[j] + 1;
					tv = j;
				}
		}
		for (int k = 0; k < vec[tv].size(); k++)
			vec[i].push_back(vec[tv][k]);
		vec[i].push_back(arr[i]);
		if (ma < p[i]) {
			ma = p[i];
			mav = i;
		}
	}
	cout << ma<<endl;
	for (int i = 0; i < vec[mav].size(); i++)
		printf("%d ", vec[mav][i]);
}