#include<iostream>
#include<vector>
using namespace std;

int arr[1005], p[1005], ma, N,mav;
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
					vec[i].push_back(arr[j]);
				}
		}
		vec[i].push_back(arr[i]);
		if (ma < p[i]) {
			ma = p[i];
			mav = i;
		}
	}
	cout << ma<<endl;
	for (int i = 1; i < vec[mav].size(); i++) {
		printf("%d ", vec[mav][i]);
	}

}