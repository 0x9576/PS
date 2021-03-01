#include<iostream>
#include<algorithm>
using namespace std;
int N, arr[1001], nex;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);
	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		if (arr[i] > nex + 1)
			break;
		nex += arr[i];
	}
	cout << nex + 1;
}