#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main() {
	stack <char> s;
	string ans;
	char e[105];
	cin >> e;
	for (int i = 0; e[i]; i++) {
		if (e[i] >= 'A' && e[i] <= 'Z')
			ans += e[i];
		else {
			if (e[i] == '*' || e[i] == '/') {
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					ans += s.top();
					s.pop();
				}
			}
			if (e[i] == '+' || e[i] == '-')
				while (!s.empty() && s.top() != '(') {
					ans += s.top();
					s.pop();
				}
			if (e[i] == ')') {
				while (!s.empty()) {
					if (s.top() == '(') {
						s.pop();
						break;
					}
					ans += s.top();
					s.pop();
				}
			}
			if(e[i] != ')')
				s.push(e[i]);
		}
	}
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
}