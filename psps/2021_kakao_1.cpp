#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
	int answer = 0;
	answer = s.size();
	int co = 0;

	for (int a = 1; a < s.size(); a++) {
		int tem = s.size();
		co = 0;
		for (int i = 0; i <= s.size() - a; i += a) {
			bool flag = true;
			for (int j = 0; j < a; j++) {
				if (s[i + j] != s[i + a + j]) {
					flag = false;
				}
			}
			if (flag)
				co += a;
			else {
				if (co > 0 && co < 10)
					tem -= co - 1;
				if (co >= 10 && co < 100)
					tem -= co;
				if (co > 99 && co < 1000)
					tem -= co + 1;
				co = 0;
			}
		}
		if (co > 0 && co < 10)
			tem -= co - 1;
		if (co >= 10 && co < 100)
			tem -= co;
		if (co > 99 && co < 1000)
			tem -= co + 1;
		answer = min(answer, tem);
	}
	return answer;
}

int main() {
	string s;
	cin >> s;
	cout << s.size();
}