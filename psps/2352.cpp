#include<iostream>
#include<algorithm>
using namespace std;

int N,con[40001],cah[40001];

int l_b(int* arr,int end, int tar) {
	int start = 1;
	int mid = (start + end) / 2;
	while (end >start) {
		mid = (start + end) / 2;
		if (arr[mid] < tar) {
			start = mid + 1;
		}
		else
			end = mid;
	}
	return end;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", con + i);

	cah[1] = con[1];
	int len = 1;
	for (int i = 2; i <= N; i++) {
		if (cah[len] < con[i]) {
			cah[++len] = con[i];
			continue;
		}
		int idx = l_b(cah,len+1, con[i]);
		cah[idx] = con[i];
	}
	cout << len;
}