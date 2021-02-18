#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool v[200005];
int N, K,bk;

int main() {
	cin >> N >> K;
	if (K <= N) {
		cout << N - K<<endl;
		for (int i = N; i >= K; i--)
			printf("%d ", i);
		exit(0);
	}
	queue<vector<int>> q;
	vector<int> vec;
	vec.push_back(N);
	q.push(vec);
	while (!q.empty()) {
		vec = q.front();
		bk = vec.back();
		q.pop();
		if (bk == K)
			break;
		if (bk * 2 < 200001 && !v[bk * 2]) {
			v[bk * 2] = 1;
			vec.push_back(bk * 2);
			q.push(vec);
			vec.pop_back();
		}
		if (bk + 1 < 200001 && !v[bk + 1]) {
			v[bk + 1] = 1;
			vec.push_back(bk +1);
			q.push(vec);
			vec.pop_back();
		}
		if (bk > 0 && !v[bk - 1]) {
			v[bk - 1] = 1;
			vec.push_back(bk - 1);
			q.push(vec);
		}
		vec.clear();
	}
	cout << vec.size() - 1 << endl;
	for (int i = 0; i < vec.size(); i++)
		printf("%d ", vec[i]);
}