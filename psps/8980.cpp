#include <iostream>
using namespace std;
int m[10000][3];
int con[10000];

int main() {
    int N; int C;
    cin >> N >> C;
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> m[i][0] >> m[i][1] >> m[i][2];
    }

    int temp;
    while (true) {
        int cou = 0;
        for (int i = 0; i < M - 1; i++) {
            if (m[i][1] > m[i + 1][1]) {
                for (int j = 0; j < 3; j++) {
                    temp = m[i + 1][j];
                    m[i + 1][j] = m[i][j];
                    m[i][j] = temp;
                }
                cou++;
            }
            if (m[i][1] == m[i + 1][1]) {
                if (m[i][0] > m[i + 1][0]) {
                    for (int j = 0; j < 3; j++) {
                        temp = m[i + 1][j];
                        m[i + 1][j] = m[i][j];
                        m[i][j] = temp;
                    }
                    cou++;
                }
            }
        }
        if (cou == 0)
            break;
    }

    int load = 0;
    int min = 0;
    int a = 0;

    for (int i = 0; i < M; i++) {
        min = m[i][2];
        for (int j = m[i][0]; j < m[i][1]; j++) {
            a = C - con[j];
            if (a < min) {
                min = a;
            }
        }

        if (min > 0) {
            for (int k = m[i][0]; k < m[i][1]; k++) {
                con[k] += min;
            }
            load += min;
        }
    }

    cout << load;

    return 0;
}