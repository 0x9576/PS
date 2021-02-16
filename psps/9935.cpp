#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
string str, b;
vector<char> v;
int tem;

bool stb() {
	for (int i = 0; i < b.size(); i++) {
		if (v[tem + i] != b[i])
			return 0;
	}
	return 1;
}

int main() {
	cin >> str >> b;
	for (int i = 0; i < str.size(); i++) {
		v.push_back(str[i]);
		if (v.size() >= b.size()) {
			tem = v.size() - b.size();
			if (stb())
				for (int i = 0; i < b.size(); i++)
					v.erase(v.begin()+tem);
		}
	}
	if (v.empty())
		cout << "FRULA";
	else
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
}