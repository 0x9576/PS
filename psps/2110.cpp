#include<iostream>
#include<algorithm>

using namespace std;

int arr[200001],ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr,arr+N);

	int left = 1;
	int right = arr[N - 1] - arr[0];

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int tem = arr[0];

		for (int i = 1; i < N; i++) {
			if (mid <= arr[i] - tem) {
				tem = arr[i];
				cnt++;
			}
		}

		if (cnt >= C) {
			ans = mid;
			left = mid +1;
		}
		else
			right = mid -1;
	}
	cout << ans << endl;
}