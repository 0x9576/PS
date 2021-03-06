#include <iostream>
using namespace std;

int value[101][100001], n, k,w[101],v[101];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int wi = w[i];
            int vi = v[i];
            if (wi > j) {
                value[i][j] = value[i - 1][j];
            }
            else {
                value[i][j] = max(value[i - 1][j], vi + value[i - 1][j - wi]);
            }

        }
    }
    cout << value[n][k];
    return 0;
}