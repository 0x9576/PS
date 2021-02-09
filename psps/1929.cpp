#include <iostream>
using namespace std;
bool ch[1000001];

int main() {
	int M, N;
	scanf("%d %d", &M, &N);
	int count = 0;
	int c = 1;
	int j = 2;
	for (int i = 2; i <= N; i++) {
		if (!ch[i]) {
			while (true) {
				if (i * j > 1000000)
					break;
				ch[i*j] = true;
				j++;
			}
			j = 2;
			if (i >= M)
				printf("%d\n", i);
		}

	}

	return 0;
}