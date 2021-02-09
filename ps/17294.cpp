#include<iostream>
#include<string>
using namespace std;
int main() {
	char n[20];
	for (int i = 0; i < 20; i++)
		n[i] = -1;
	cin >> n;
	for (int i = 0; n[i+3]!=-1; i++) {
		if (n[i] - n[i + 1] != n[i + 1] - n[i + 2]) {
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
			exit(0);
		}
	}
	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	return 0;
}