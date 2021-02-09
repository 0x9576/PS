#include<iostream>
using namespace std;

int arr[1005];
int p[1005];

int main() {
	int n;
	cin >> n;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				if(p[i] <p[j]+1)
					p[i] = p[j] + 1;
		}
		if (max < p[i])
			max = p[i];
	}
	cout << max;
}