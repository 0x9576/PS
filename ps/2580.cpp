#include<iostream>
using namespace std;
int f[9][9], o[9][9];

void slo(int a, int b) {
	b++;
	if (b == 8) {
		a++;
		b = 0;
	}
	for (int i = a; i < 9; i++)
		for (int j = b; j < 9; j++)
			if (!f[i][j])
				slo(i, j);
}

int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> f[i][j];
			o[i][j]=f[i][j];
		}

}