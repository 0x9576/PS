#include <iostream>
bool sc(bool bw) {
	if (bw)
		return false;
	else
		return true;
}


int main() {
	bool bw = true; //true == case1 : black;

	int a; int b;
	char arr[50][50];
	std::cin >> a >> b;
	for (int i = 0; i < a; i++) {
		std::cin >> arr[i];
	}
	int count1 = 0;
	int count2 = 0;
	int c = 0;
	int d = 0;
	int min = 2500;

	while (true) {
		count1 = 0;
		count2 = 0;
		while (true) {
			count1 = 0;
			count2 = 0;
			for (int i = c; i <= c + 7; i++) {
				for (int j = d; j <= d + 7; j++) {
					if (bw) {
						if (arr[i][j] != 'B') {
							count1++;
						}
						if (arr[i][j] != 'W') {
							count2++;
						}
					}
					else {
						if (arr[i][j] != 'W') {
							count1++;
						}
						if (arr[i][j] != 'B') {
							count2++;
						}
					}
					bw = sc(bw);
				}
				bw = sc(bw);
			}
			if (count1 <= count2) {
				if (min > count1) {
					min = count1;
				}
			}
			else {
				if (min > count2) {
					min = count2;
				}
			}
			if (c + 7 == a) {
				c = 0;
				break;
			}
			c++;
		}
		if (count1 <= count2) {
			if (min > count1) {
				min = count1;
			}
		}
		else {
			if (min > count2) {
				min = count2;
			}
		}
		if (d + 7 == b) {
			d = 0;
			break;
		}
		d++;
	}

	std::cout << min << std::endl;
}