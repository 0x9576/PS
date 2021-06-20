#include<iostream>
using namespace std;
char arr[14000][14000];
int N;

void rec(int n, int y, int x) {
	if (n==1) {
		arr[y][x] = '*';
		return;
	}

	for(int i = 0; i<3; i++)
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			rec(n/3, y-(n * i /3), x - (n * j / 3));
		}
}

int main() {
	cin >> N;
	for (int i = 0; i < 14000; i++)
		for (int j = 0; j < 14000; j++)
			arr[i][j] = ' ';
	rec(N, N, N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%c", arr[i][j]);
		puts("");
	}
}